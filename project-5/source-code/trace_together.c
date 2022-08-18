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

#ifdef TMOTE_SKY
#include "powertrace.h"
#else
// Machine Learning Model
#include "model.c"

// Sensors
#include "board-peripherals.h"
#include "contiki-conf.h"
#include "opt-3001-sensor.h"
#include "mpu-9250-sensor.h"
#include "hdc-1000-sensor.h"
#endif
/*---------------------------------------------------------------------------*/
#define LOGGING 0               // Change to 1 for more logging messages
/*---------------------------------------------------------------------------*/
#define SENSOR_WARM_UP_SLOTS 26

#define SENSOR_SAMPLE_SIZE 4

#define SENSOR_SAMPLE_INTERVAL_SLOTS 20

static const int ACTIVATION_SLOT = 0;
static const int DEACTIVATION_SLOT = (SENSOR_WARM_UP_SLOTS + SENSOR_SAMPLE_SIZE * SENSOR_SAMPLE_INTERVAL_SLOTS);

// sample duration = (SAMPLE_SIZE - 1) * SAMPLE_INTERVAL + WARM_UP_TIME = 1s

/*---------------------------------------------------------------------------*/
#define TIME_UPPER_BOUND 30
#define NVal 55
static rtimer_clock_t SLOT_TIME = (((double) RTIMER_SECOND) * TIME_UPPER_BOUND) / (NVal * NVal); // 10s / N ^2
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
static data_packet_struct temp_packet;
static unsigned long curr_timestamp;
/*---------------------------------------------------------------------------*/
PROCESS(trace_together_process, "Trace together process");
AUTOSTART_PROCESSES(&trace_together_process);
/*---------------------------------------------------------------------------*/
static void print_current_time() {
  curr_timestamp = clock_time();
  printf("timestamp: %lu ticks, %3lu.%03lus\n", curr_timestamp, curr_timestamp / CLOCK_SECOND, ((curr_timestamp % CLOCK_SECOND)*1000) / CLOCK_SECOND);
}

static unsigned long get_current_seconds() {
  curr_timestamp = clock_time();
  return curr_timestamp / CLOCK_SECOND;
}

#ifndef TMOTE_SKY
static int current_light;
static void get_light_reading() {
    static int value;
    value = opt_3001_sensor.value(0);
    if (value == CC26XX_SENSOR_READING_ERROR) {
        return;     // Do not change light reading in case of sensor errors
    }

    current_light = value;

    SENSORS_ACTIVATE(opt_3001_sensor);      // Due to sensor being a single-shot readings,
                                            // it has to be activated again before next reading
}

static int current_g;
static int current_gyro;
static void get_motion_reading() {
    // Accelerometer results
    static int accX, accY, accZ, G;
    accX = mpu_9250_sensor.value(MPU_9250_SENSOR_TYPE_ACC_X);
    if (accX == CC26XX_SENSOR_READING_ERROR) {
        return;     // Do not change current reading in case of sensor errors
    }

    accY = mpu_9250_sensor.value(MPU_9250_SENSOR_TYPE_ACC_Y);
    accZ = mpu_9250_sensor.value(MPU_9250_SENSOR_TYPE_ACC_Z);

    G = sqrt((long long) accX * accX + (long long) accY * accY + (long long) accZ * accZ);

    current_g = G;

    // Gyroscope results
    static int gyroX, gyroY, gyroZ, gyro;
    gyroX = mpu_9250_sensor.value(MPU_9250_SENSOR_TYPE_GYRO_X);
    gyroY = mpu_9250_sensor.value(MPU_9250_SENSOR_TYPE_GYRO_Y);
    gyroZ = mpu_9250_sensor.value(MPU_9250_SENSOR_TYPE_GYRO_Z);

    gyro = sqrt((long long) gyroX * gyroX + (long long) gyroY * gyroY + (long long) gyroZ * gyroZ);
    current_gyro = gyro;
}

static int current_temperature;
static int current_humidity;
static void get_humidity_reading() {
    static int temperature, humidity;
    temperature = hdc_1000_sensor.value(HDC_1000_SENSOR_TYPE_TEMP);
    if (temperature == CC26XX_SENSOR_READING_ERROR) {
        return;
    }
    current_temperature = temperature;

    humidity = hdc_1000_sensor.value(HDC_1000_SENSOR_TYPE_HUMIDITY);
    current_humidity = humidity;

    SENSORS_ACTIVATE(hdc_1000_sensor);      // To get a fresh reading, we need to activate it again
}

static void activate_sensors() {
    SENSORS_ACTIVATE(opt_3001_sensor);
    mpu_9250_sensor.configure(SENSORS_ACTIVE, MPU_9250_SENSOR_TYPE_ALL);
    SENSORS_ACTIVATE(hdc_1000_sensor);
}

static void start_sensors_reading() {
    get_light_reading();
    get_motion_reading();
    get_humidity_reading();
}

static int light_results[SENSOR_SAMPLE_SIZE];
static int acc_results[SENSOR_SAMPLE_SIZE];
static int gyro_results[SENSOR_SAMPLE_SIZE];
static int temperature_results[SENSOR_SAMPLE_SIZE];
static int humidity_results[SENSOR_SAMPLE_SIZE];
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

static int min(int a, int b) {
    return (a < b) ? a : b;
}

static int light_avg = 0, acc_avg = 0, gyro_avg = 0, temperature_avg = 0, humidity_avg = 0;

// adjust RSSI based on sensors reading by changing the environment noise
static void adjustRSSI() {
    light_avg = 0;
    acc_avg = 0;
    gyro_avg = 0;
    temperature_avg = 0;
    humidity_avg = 0;

    static int i;
    for (i = 0; i < SENSOR_SAMPLE_SIZE; i++) {
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

    if (LOGGING) {
        printf("Avg Light=%d.%02d lux\n", light_avg / 100, light_avg % 100);
        printf("Avg Acceleration=%d.%02d G\n", acc_avg  / 100, acc_avg % 100);
        printf("Avg Angular velocity=%d.%02d deg/sec\n", gyro_avg / 100, gyro_avg % 100);
        printf("Avg Temperature=%d.%02d C\n", temperature_avg  / 100, temperature_avg % 100);
        printf("Avg Humidity=%d.%02d RH\n", humidity_avg / 100, humidity_avg % 100);
    }

    data_packet.light = light_avg;
    data_packet.acc = acc_avg;
    data_packet.gyro = gyro_avg;
    data_packet.temperature = temperature_avg;
    data_packet.humidity = humidity_avg;
}
#endif

typedef struct {
  unsigned long id;
  unsigned long last_encounter;
  unsigned long first_encounter;
} node;

#define MAX_NODE 50          // Max number of nodes encountered within one point of time.
static int total = 0;
static node encountered_nodes[MAX_NODE];

#define NUM_FEATURES 11

// Employ machine learning model to determine whether another node is within 3m
static int is_within_3m(int rssi) {
    #ifdef TMOTE_SKY
    return random_rand() % 2;
    #else
    static float features[NUM_FEATURES];

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

    if (predict(features)) {
        return 1;
    }

    // Test the other direction
    static int i, temp;
    for (i = 0; i < 5; ++i) {
        // Swapping features[i] and features[i + 6]
        temp = features[i];
        features[i] = features[i + 6];
        features[i + 6] = temp;
    }

    return predict(features);
    #endif
}

static void encounter_node(int rssi) {
    static unsigned long node_id, now;
    node_id = received_packet.src_id;

    if (LOGGING) {
        printf("Detected incoming packet from node %lu, RSSI: %d @", node_id, rssi);
        print_current_time();
    }

    if (!is_within_3m(rssi)) {
        if (LOGGING) {
            printf("Outside of 3 meters!\n");
        }

        return;     // Not considered, since already beyond 3 meters
    }

    if (LOGGING) {
        printf("Within 3 meters!\n");
    }

    now = get_current_seconds();
    static int i;
    for (i = 0; i < total; ++i) {
        if (encountered_nodes[i].id == node_id) {
            encountered_nodes[i].last_encounter = now;
            return;
        }
    }

    if (total == MAX_NODE) {        // No more capacity, but very unlikely to have more than > MAX_NODE people within 3 meters
        return;
    }

    // Keep new nodes
    printf("%lu DETECT %lu\n", now, node_id);
    encountered_nodes[total].id = node_id;
    encountered_nodes[total].first_encounter = now;
    encountered_nodes[total].last_encounter = now;

    total++;
}

// Removing node by simply swapping it to the end of array
static void remove_node(int idx) {
    printf("%lu LEAVE %lu\n", get_current_seconds(), encountered_nodes[idx].id);

    static node temp;

    temp = encountered_nodes[idx];
    encountered_nodes[idx] = encountered_nodes[total - 1];
    encountered_nodes[total - 1] = temp;

    total--;
}

static const unsigned long TIME_THRESHOLD = 5;
static void remove_undetected_nodes() {
    static unsigned long now;
    static uint16_t i;
    now = get_current_seconds();
    for (i = 0; i < total; ++i) {
        if (encountered_nodes[i].last_encounter + TIME_THRESHOLD > now) {
            continue;
        }

        remove_node(i--);       // Did not hear in the last round
    }
}

static void print_contact_summary() {
    if (total <= 1) {
        printf("%d token is within 3m proximity\n", total);
    } else {
        printf("%d tokens are within 3m proximity\n", total);
    }

    static unsigned long now, id, contact_duration;
    now = get_current_seconds();

    static int i;
    for (i = 0; i < total; ++i) {
        id = encountered_nodes[i].id;
        contact_duration = now - encountered_nodes[i].first_encounter;
        printf("\t- Node %lu has been in contact for around %lu seconds\n", id, contact_duration);
    }
}

static int
is_sample_slot(int slot_id) {
  static int is_sample_interval, interval_id;
  if (slot_id < SENSOR_WARM_UP_SLOTS) {
    return 0;
  }

  is_sample_interval = (slot_id - SENSOR_WARM_UP_SLOTS) % SENSOR_SAMPLE_INTERVAL_SLOTS == 0;
  if (!is_sample_interval) {
    return 0;
  }

  interval_id = (slot_id - SENSOR_WARM_UP_SLOTS) / SENSOR_SAMPLE_INTERVAL_SLOTS;
  return (interval_id < SENSOR_SAMPLE_SIZE);
}

static void
broadcast_recv(struct broadcast_conn *c, const linkaddr_t *from)
{
  static int rssi_strength;
  leds_on(LEDS_GREEN);

  memcpy(&received_packet, packetbuf_dataptr(), sizeof(data_packet_struct));

  rssi_strength = (signed short) packetbuf_attr(PACKETBUF_ATTR_RSSI);
  encounter_node(rssi_strength);

  leds_off(LEDS_GREEN);
}
static const struct broadcast_callbacks broadcast_call = {broadcast_recv};
static struct broadcast_conn broadcast;
/*---------------------------------------------------------------------------*/
#define MIN_ROUNDS_FOR_RSSI_ADJUSTMENT 1
#define MAX_ROUNDS_FOR_RSSI_ADJUSTMENT 4

static int NumRoundsBeforeAdjustment=1;
static int lastAdjustment = MIN_ROUNDS_FOR_RSSI_ADJUSTMENT;

#ifndef TMOTE_SKY
// Standard Deviation for Sensor Readings based on our experiment.
static const int STANDARD_LIGHT = 110389;
static const int STANDARD_ACC = 24;
static const int STANDARD_GYRO = 5374;
static const int STANDARD_TEMPERATURE = 283;
static const int STANDARD_HUMIDITY = 944;

static int is_big_difference_in_sensor_readings() {
    if (abs(temp_packet.light - data_packet.light) > STANDARD_LIGHT) {
        return 1;
    }

    if (abs(temp_packet.acc - data_packet.acc) > STANDARD_ACC) {
        return 1;
    }

    if (abs(temp_packet.gyro - data_packet.gyro) > STANDARD_GYRO) {
        return 1;
    }

    if (abs(temp_packet.temperature - data_packet.temperature) > STANDARD_TEMPERATURE) {
        return 1;
    }

    if (abs(temp_packet.humidity - data_packet.humidity) > STANDARD_HUMIDITY) {
        return 1;
    }

    return 0;
}

static void operate_sensors(int r, int c) {
    static int slotId, intervalId;
    slotId = r * NVal + c;
    if (slotId == ACTIVATION_SLOT) {
        activate_sensors();
    }

    if (is_sample_slot(slotId)) {
        intervalId = (slotId - SENSOR_WARM_UP_SLOTS) / SENSOR_SAMPLE_INTERVAL_SLOTS;
        start_sensors_reading();        // collect results through sensors
        store_sensors_results(intervalId);
    }

    if (slotId == DEACTIVATION_SLOT) {
        deactivate_sensors();

        adjustRSSI();

        // Adaptive adjustment time, inspired from adaptive beaconing
        if (is_big_difference_in_sensor_readings()) {
            lastAdjustment = MIN_ROUNDS_FOR_RSSI_ADJUSTMENT;
            temp_packet = data_packet;          // Cache first sensor results in the new environment
        } else {
            lastAdjustment = min(lastAdjustment * 2, MAX_ROUNDS_FOR_RSSI_ADJUSTMENT);
        }
        NumRoundsBeforeAdjustment = lastAdjustment;

        if (LOGGING) {
            printf("Re-assessing the environment again in %d rounds (adaptive assessment)\n\n", NumRoundsBeforeAdjustment);
        }
    }
}
#endif

char sender_scheduler(struct rtimer *t, void *ptr) {
    static int r = 0, c = 0;
    static int is_adjustment_round;

    PT_BEGIN(&pt);

    curr_timestamp = clock_time(); 
    if (LOGGING) {
        printf("Start clock %lu ticks, timestamp %3lu.%03lu\n", curr_timestamp, curr_timestamp / CLOCK_SECOND, ((curr_timestamp % CLOCK_SECOND)*1000) / CLOCK_SECOND);
        printf("Row: %d, Column: %d, Slot Time: %ld\n", Row, Col, SLOT_TIME);
    }

    while(1) {
        if (r == 0) {
            if (LOGGING) {
                printf("\nNEW ROUND\n");
            }

            NumRoundsBeforeAdjustment--;
            is_adjustment_round = (NumRoundsBeforeAdjustment <= 0);
        }

        if (r == Row) {
          leds_on(LEDS_BLUE);
          NETSTACK_RADIO.on();          // Start listening
        }

        // Iterate through columns
        for (c = 0; c < NVal; c++) {

            if (is_adjustment_round) {
                #ifndef TMOTE_SKY
                operate_sensors(r, c);
                #endif
                if (NumRoundsBeforeAdjustment > 0) {
                    is_adjustment_round = 0;
                }
            }

            // Sending column
            if (c == Col) {
                leds_on(LEDS_RED);
                curr_timestamp = clock_time();

                if (LOGGING) {
                    printf("Send at (%d, %d) %8lu ticks   %3lu.%03lu\n", r, c, curr_timestamp, curr_timestamp / CLOCK_SECOND, ((curr_timestamp % CLOCK_SECOND)*1000) / CLOCK_SECOND);
                }

                packetbuf_copyfrom(&data_packet, (int)sizeof(data_packet_struct));
                broadcast_send(&broadcast);

                leds_off(LEDS_RED);
            }
            
            rtimer_set(t, RTIMER_TIME(t) + SLOT_TIME, 1, (rtimer_callback_t)sender_scheduler, ptr);
            PT_YIELD(&pt);
        }

        if (r == Row) {
          NETSTACK_RADIO.off();
          leds_off(LEDS_BLUE);
          remove_undetected_nodes();
          if (LOGGING) {
              print_contact_summary();
          }
        }

        r = (r + 1) % NVal;  // if loop back to the first column, move to the next row
    }

    PT_END(&pt);
}
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(trace_together_process, ev, data)
{
    PROCESS_EXITHANDLER(broadcast_close(&broadcast);)

    PROCESS_BEGIN();

    #ifdef TMOTE_SKY
    powertrace_start(CLOCK_SECOND * 5);
    #endif

    broadcast_open(&broadcast, 129, &broadcast_call);

    // for serial port
    #if !WITH_UIP && !WITH_UIP6
    uart1_set_input(serial_line_input_byte);
    serial_line_init();
    #endif

    if (LOGGING) {
        printf("Trace Together\n");
        printf("Node %d will be sending packet of size %d Bytes\n", node_id, (int)sizeof(data_packet_struct));
    }

    // radio off
    NETSTACK_RADIO.off();

    // initialize data packet
    data_packet.src_id = node_id;
    data_packet.light = 0;
    data_packet.acc = 0;
    data_packet.gyro = 0;
    data_packet.humidity = 0;
    data_packet.temperature = 0;

    temp_packet.src_id = node_id;
    temp_packet.light = 0;
    temp_packet.acc = 0;
    temp_packet.gyro = 0;
    temp_packet.humidity = 0;
    temp_packet.temperature = 0;

    // initialize R and C values
    Row = random_rand() % NVal;
    Col = random_rand() % NVal;

    // Start sender in one millisecond.
    rtimer_set(&rt, RTIMER_NOW() + (RTIMER_SECOND / 1000), 1, (rtimer_callback_t)sender_scheduler, NULL);

    PROCESS_END();
}
/*---------------------------------------------------------------------------*/
