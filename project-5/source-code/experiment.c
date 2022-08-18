#include "contiki.h"
#include "dev/leds.h"
#include <stdio.h>
#include <math.h>
#include "core/net/rime/rime.h"
#include "dev/serial-line.h"
#include "dev/uart1.h"
#include "node-id.h"
#include "defs_and_types.h"
#include "net/netstack.h"
#include "net/rime/rime.h"
#include "random.h"
#include "board-peripherals.h"
#include <stdbool.h>
#include "analysis/model.c"

// Sensors
#include "contiki-conf.h"
#include "opt-3001-sensor.h"
#include "mpu-9250-sensor.h"
#include "hdc-1000-sensor.h"

#ifdef TMOTE_SKY
#include "powertrace.h"
#endif
/*---------------------------------------------------------------------------*/
#define SENSOR_WARM_UP_SLOTS 6

#define SENSOR_SAMPLE_SIZE 4

#define SENSOR_SAMPLE_INTERVAL_SLOTS 6

// sample duration = (SAMPLE_SIZE - 1) * SAMPLE_INTERVAL + WARM_UP_TIME = 1s

/*---------------------------------------------------------------------------*/
#define TIME_UPPER_BOUND 1
#define NVal 5
// static rtimer_clock_t SLOT_TIME = (((double) RTIMER_SECOND) * TIME_UPPER_BOUND) / (NVal * NVal); // 10s / N ^2
static int Row, Col; // Active slots
/*---------------------------------------------------------------------------*/
// duty cycle = (2N - 1) / N^2
/*---------------------------------------------------------------------------*/
// sender timer
static struct rtimer rt;
static struct pt pt;
/*---------------------------------------------------------------------------*/
static data_packet_struct received_packet;
static data_packet_struct data_packet;
unsigned long curr_timestamp;
/*---------------------------------------------------------------------------*/
PROCESS(cc2650_nbr_discovery_process, "cc2650 neighbour discovery process");
AUTOSTART_PROCESSES(&cc2650_nbr_discovery_process);
/*---------------------------------------------------------------------------*/
static int current_light;
static void get_light_reading() {
    int value = opt_3001_sensor.value(0);
    if (value == CC26XX_SENSOR_READING_ERROR) {
        // printf("OPT: Light Sensor's Warming Up\n");
        return;     // Do not change light reading in case of sensor errors
    }

    // printf("OPT: Light=%d.%02d lux\n", value / 100, value % 100);
    current_light = value;

    SENSORS_ACTIVATE(opt_3001_sensor);      // Due to sensor being a single-shot readings,
                                            // it has to be activated again before next reading
}

static int current_g;
static int current_gyro;
static void get_motion_reading() {
    // Accelerometer results
    int accX = mpu_9250_sensor.value(MPU_9250_SENSOR_TYPE_ACC_X);
    if (accX == CC26XX_SENSOR_READING_ERROR) {
        // printf("MPU: Motion Sensor's Warming Up\n");
        return;     // Do not change current reading in case of sensor errors
    }

    int accY = mpu_9250_sensor.value(MPU_9250_SENSOR_TYPE_ACC_Y);
    int accZ = mpu_9250_sensor.value(MPU_9250_SENSOR_TYPE_ACC_Z);

    int G = sqrt((long long) accX * accX + (long long) accY * accY + (long long) accZ * accZ);

    // printf("MPU: Acceleration=%d.%02d G\n", G / 100, G % 100);
    current_g = G;

    // Gyroscope results
    int gyroX = mpu_9250_sensor.value(MPU_9250_SENSOR_TYPE_GYRO_X);
    int gyroY = mpu_9250_sensor.value(MPU_9250_SENSOR_TYPE_GYRO_Y);
    int gyroZ = mpu_9250_sensor.value(MPU_9250_SENSOR_TYPE_GYRO_Z);

    int gyro = sqrt((long long) gyroX * gyroX + (long long) gyroY * gyroY + (long long) gyroZ * gyroZ);
    // printf("MPU: Angular velocity=%d.02%d deg/sec\n", gyro / 100, gyro % 100);
    current_gyro = gyro;
}

static int current_temperature;
static int current_humidity;
static void get_humidity_reading() {
    int temperature = hdc_1000_sensor.value(HDC_1000_SENSOR_TYPE_TEMP);
    if (temperature == CC26XX_SENSOR_READING_ERROR) {
        // printf("HDC: Humidity Sensor's Warming Up\n");
    }
    // printf("HDC: Temperature=%d.%02d C\n", temperature / 100, temperature % 100);
    current_temperature = temperature;

    int humidity = hdc_1000_sensor.value(HDC_1000_SENSOR_TYPE_HUMIDITY);
    // printf("HDC: Humidity=%d.%02d RH\n",  humidity / 100, humidity % 100);
    current_humidity = humidity;

    SENSORS_ACTIVATE(hdc_1000_sensor);      // To get a fresh reading, we need to activate it again
}

static void activate_sensors() {
    SENSORS_ACTIVATE(opt_3001_sensor);
    mpu_9250_sensor.configure(SENSORS_ACTIVE, MPU_9250_SENSOR_TYPE_ALL);
    SENSORS_ACTIVATE(hdc_1000_sensor);
}

static void start_sensors_reading() {
    // printf("STARTING SENSORS READING\n");

    get_light_reading();
    get_motion_reading();
    get_humidity_reading();

    // printf("\n");
}

int light_results[SENSOR_SAMPLE_SIZE];
int acc_results[SENSOR_SAMPLE_SIZE];
int gyro_results[SENSOR_SAMPLE_SIZE];
int temperature_results[SENSOR_SAMPLE_SIZE];
int humidity_results[SENSOR_SAMPLE_SIZE];
static void store_sensors_results(int idx) {
    light_results[idx] = current_light;
    acc_results[idx] = current_g;
    gyro_results[idx] = current_gyro;
    temperature_results[idx] = current_temperature;
    humidity_results[idx] = current_humidity;
}

static void deactivate_sensors() {
    SENSORS_DEACTIVATE(opt_3001_sensor);
    SENSORS_DEACTIVATE(mpu_9250_sensor);
    SENSORS_DEACTIVATE(hdc_1000_sensor);
}

const int BASE_RSSI = 40;      // It will be considered within 3 meters if RSSI below threshold
int ENVIRONMENT_NOISE = 0;      // Extra RSSI Threshold, depending on the environment measured by sensors

static int min(int a, int b) {
    return (a < b) ? a : b;
}

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static int light_to_noise(int lightVal) {
    if (15000 <= lightVal && lightVal <= 25000) {           // 150 to 250 lux is under a normal environment
        return 0;
    }

    int distance = max(15000 - lightVal, lightVal - 25000);

    return min(5, (int) (distance * 5) / 15000);
}

static int acc_to_noise(int accVal) {
    if (90 <= accVal && accVal <= 110) {      // Normal circumstances
        return 0;
    }

    int distance = max(90 - accVal, accVal - 110);

    return min(5, (int) (distance * 5) / 90);
}

// adjust RSSI based on sensors reading by changing the environment noise
static int light_avg;
static int acc_avg;
static int gyro_avg;
static int temperature_avg;
static int humidity_avg;
static void measureEnvironment() {
    light_avg = 0;
    acc_avg = 0;
    gyro_avg = 0;
    temperature_avg = 0;
    humidity_avg = 0;

    for (int i = 0; i < SENSOR_SAMPLE_SIZE; i++) {
        light_avg += light_results[i];
        acc_avg += acc_results[i];
        gyro_avg += gyro_results[i];
        temperature_avg += temperature_results[i];
        humidity_avg += humidity_results[i];
    }

    light_avg /= SENSOR_SAMPLE_SIZE;
    acc_avg /= SENSOR_SAMPLE_SIZE;
    gyro_avg /= SENSOR_SAMPLE_SIZE;
    temperature_avg /= SENSOR_SAMPLE_SIZE;
    humidity_avg /= SENSOR_SAMPLE_SIZE;

    // printf("Avg Light=%d.%02d lux\n", light_avg / 100, light_avg % 100);
    // printf("Avg Acceleration=%d.%02d G\n", acc_avg  / 100, acc_avg % 100);
    // printf("Avg Angular velocity=%d.%02d deg/sec\n", gyro_avg / 100, gyro_avg % 100);
    // printf("Avg Temperature=%d.%02d C\n", temperature_avg  / 100, temperature_avg % 100);
    // printf("Avg Humidity=%d.%02d RH\n", humidity_avg / 100, humidity_avg % 100);

    ENVIRONMENT_NOISE = light_to_noise(light_avg) + acc_to_noise(acc_avg);
    // printf("%d,%d,%d,%d,%d,%d\n", light_avg, acc_avg, gyro_avg, temperature_avg, humidity_avg, rssi);
    data_packet.light = light_avg;
    data_packet.acc = acc_avg;
    data_packet.gyro = gyro_avg;
    data_packet.temperature = temperature_avg;
    data_packet.humidity = humidity_avg;

    // printf("Environment noise expected to be: %d\n", ENVIRONMENT_NOISE);
}

typedef struct {
  unsigned long id;
  unsigned long last_encounter;
  unsigned long first_encounter;
} node;

// Employ machine learning model to determine whether another node is within 3m
static bool is_within_3m(int rssi) {
    float features[11];

    features[0] = data_packet.light;
    features[1] = data_packet.acc;
    features[2] = data_packet.gyro;
    features[3] = data_packet.temperature;
    features[4] = data_packet.humidity;
    features[5] = rssi;
    features[6] = received_packet.light;
    features[7] = received_packet.acc;
    features[8] = received_packet.gyro;
    features[9] = received_packet.temperature;
    features[10] = received_packet.humidity;
    printf("All features: ");
    for (int i = 0; i < 11; ++i) {
        printf("%d ", (int) features[i]);
    }
    printf("\n");

    if (predict(features)) {
        return true;
    }

    // Test the other direction
    for (int i = 0; i < 5; ++i) {
        // Swapping features[i] and features[i + 6]
        int temp = features[i];
        features[i] = features[i + 6];
        features[i + 6] = temp;
    }

    return predict(features);
}

#define MAX_NODE 1000          // Max number of nodes encountered within one point of time.
static void printResults(int rssi) {
    printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%u,%lu\n", light_avg, acc_avg, gyro_avg, temperature_avg, humidity_avg, rssi,
            received_packet.light, received_packet.acc, received_packet.gyro, received_packet.temperature, received_packet.humidity,
            node_id, received_packet.src_id);
    
    printf("Precition: %d\n", is_within_3m(rssi));
}

static void
broadcast_recv(struct broadcast_conn *c, const linkaddr_t *from)
{
  leds_on(LEDS_GREEN);

  memcpy(&received_packet, packetbuf_dataptr(), sizeof(data_packet_struct));

  int rssi_strength = (signed short) packetbuf_attr(PACKETBUF_ATTR_RSSI);
  printResults(rssi_strength);

  leds_off(LEDS_GREEN);
}

static const struct broadcast_callbacks broadcast_call = {broadcast_recv};
static struct broadcast_conn broadcast;
/*---------------------------------------------------------------------------*/
char sender_scheduler(struct rtimer *t, void *ptr) {
    static int i;

    PT_BEGIN(&pt);

    curr_timestamp = clock_time(); 
    // printf("Start clock %lu ticks, timestamp %3lu.%03lu\n", curr_timestamp, curr_timestamp / CLOCK_SECOND, ((curr_timestamp % CLOCK_SECOND)*1000) / CLOCK_SECOND);
    // printf("Row: %d, Column: %d, Slot Time: %ld\n", Row, Col, SLOT_TIME);

    NETSTACK_RADIO.on();          // Start listening
    activate_sensors();
    while(1) {
        for (i = 0; i < SENSOR_SAMPLE_SIZE; i++) {
            rtimer_set(t, RTIMER_TIME(t) + (RTIMER_SECOND / 4), 1, (rtimer_callback_t)sender_scheduler, ptr);
            PT_YIELD(&pt);

            start_sensors_reading();        // collect results through sensors
            store_sensors_results(i);
        }

        measureEnvironment();

        packetbuf_copyfrom(&data_packet, (int)sizeof(data_packet_struct));
        broadcast_send(&broadcast);
    }

    deactivate_sensors();
    NETSTACK_RADIO.off();
    PT_END(&pt);
}
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(cc2650_nbr_discovery_process, ev, data)
{
    PROCESS_EXITHANDLER(broadcast_close(&broadcast);)

    PROCESS_BEGIN();

    random_init(54222);

    #ifdef TMOTE_SKY
    powertrace_start(CLOCK_SECOND * 5);
    #endif

    broadcast_open(&broadcast, 129, &broadcast_call);

    // for serial port
    #if !WITH_UIP && !WITH_UIP6
    uart1_set_input(serial_line_input_byte);
    serial_line_init();
    #endif

    printf("receiver_light,receiver_acceleration,receiver_angular_velocity,receiver_temperature,receiver_humidity,rssi,sender_light,sender_acceleration,sender_angular_velocity,sender_temperature,sender_humidity,receiver_id,sender_id");
    // printf("CC2650 neighbour discovery\n");
    // printf("Node %d will be sending packet of size %d Bytes\n", node_id, (int)sizeof(data_packet_struct));

    // radio off
    NETSTACK_RADIO.off();

    // initialize data packet
    data_packet.src_id = node_id;

    // initialize R and C values
    // Row = random_rand() % NVal;
    // Col = random_rand() % NVal;

    Row = NVal - 1; // Range between [2, NVal - 1]
    Col = NVal - 1; // Last column

    // Start sender in one millisecond.
    rtimer_set(&rt, RTIMER_NOW() + (RTIMER_SECOND / 1000), 1, (rtimer_callback_t)sender_scheduler, NULL);

    PROCESS_END();
}
/*---------------------------------------------------------------------------*/
