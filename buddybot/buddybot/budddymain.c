#include "buddybot.h"
#include <iom328p.h>

void main(void)
{
	init_motors();
}

void init_motors()
{
	//setting PWM pins as output  (Pulse Width Modulation) for speed control
	DDRB |= (1 << PWM1) | (1 << PWM2);
	
	//setting direction pins as output
	DDRD |= (1 << DIR1) | (1 << DIR2);
	
	//set up timer for PWM
	TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM10);
	TCCR1B = (1 << CS11);
	
	//set duty cycle to 0 (motors off)
	
	OCR1A = 0;
	OCR1B = 0;
	// set direction of motors to forward
	
	PORTD &= ~(1 << DIR1);
	PORTD &= ~(1 << DIR2);
}
ISR(SPI_STC_vect) {
	execute_command((cmd_packet_t *)&SPDR);
}

void execute_command(struct CommandPacket *packet) {

	// Perform actions based on the command
	switch (command) {
		case FORWARD:
		move_forward(packet->speed);
		break;
		case BACKWARD:
		move_backward(packet->speed);
		break;
		case LEFT:
		turn_left(packet->speed);
		break;
		case RIGHT:
		turn_right(packet->speed);
		break;
		case STOP:
		stop_motors();
		break;
	}
}
