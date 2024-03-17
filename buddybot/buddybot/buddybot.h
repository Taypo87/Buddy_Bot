#ifndef _BUDDY_BOT_
#define _BUDDY_BOT_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define PWM1 PD3 // motor 1 speed control pin
#define PWM2 PD6 // motor 2 speed control pin
#define DIR1 PD2 // motor 1 direction pin
#define DIR2 PD7 // motor 2 direction pin

#define FORWARD 0x00
#define BACKWARD 0x01
#define LEFT 0x02
#define RIGHT 0x03
#define DRIFT_R 0x04
#define DRIFT_L 0x05
#define STOP 0x06

#define SET_SPEED(speed) do { \
	OCR0A = speed * 85; \
	OCR0B = speed * 85; \
} while(0)

#define MOVE_FORWARD(speed) do { \
	PORTD |= (1 << DIR1); \
	PORTD |= (1 << DIR2); \
	SET_SPEED(speed); \
} while(0)

#define MOVE_BACKWARD(speed) do { \
	PORTD &= ~(1 << DIR1); \
	PORTD &= ~(1 << DIR2); \
	SET_SPEED(speed); \
} while(0)

#define TURN_LEFT(speed) do { \
	PORTD |= (1 << DIR1); \
	PORTD &= ~(1 << DIR2); \
	SET_SPEED(speed); \
} while(0)

#define TURN_RIGHT(speed) do { \
	PORTD |= (1 << DIR2); \
	PORTD &= ~(1 << DIR1); \
	SET_SPEED(speed); \
} while(0)

#define DRIFT_RIGHT(speed) do { \
	OCR0A = (speed > 0) ? speed * 85 : 0; \
	OCR0B = (speed > 0) ? (speed * 85) - 50 : 0; \
	PORTD |= (1 << DIR1); \
	PORTD |= (1 << DIR2); \
} while(0)

#define DRIFT_LEFT(speed) do { \
	OCR0B = (speed > 0) ? speed * 85 : 0; \
	OCR0A = (speed > 0) ? (speed * 85) - 50 : 0; \
	PORTD |= (1 << DIR1); \
	PORTD |= (1 << DIR2); \
} while(0)

#define MOVE_STOP() do { \
	OCR0A = 0; \
	OCR0B = 0; \
} while(0)

typedef struct cmd_packet_s {
	unsigned speed : 2;
	unsigned command : 6;
	} cmd_packet_t;
	
	
void init_SPI();
void init_motors();
void execute_command(struct cmd_packet_t *packet);


#endif

