/*	Author: ebramkw
	Typedef and definitions	*/

/*---------------------------------------------------------------------------*/
#define NUM_SEND 2
/*---------------------------------------------------------------------------*/
typedef struct {
  unsigned long src_id;
  int light, acc, gyro, temperature, humidity;
} data_packet_struct;
/*---------------------------------------------------------------------------*/