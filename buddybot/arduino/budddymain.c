#include "buddybot.h"



void init_SPI()
{
	DDRB |= (1 << DDB4);  //Set MISO as output
	
	//Set other pins as input
	DDRB &= ~((1 << DDB3) | (1 << DDB5) | (1 << DDB2));
	
	//Enable SPI, set slave and enable SPI interrupts
	SPCR = (1 << SPE) | (1 << SPIE);
	
	//enable global interrupts
	sei();
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

void execute_command(cmd_packet_t *packet) {

	// Perform actions based on the command
	switch (packet->command) {
		case FORWARD:
		MOVE_FORWARD(packet->speed);
		break;
		case BACKWARD:
		MOVE_BACKWARD(packet->speed);
		break;
		case LEFT:
		TURN_LEFT(packet->speed);
		break;
		case RIGHT:
		TURN_RIGHT(packet->speed);
		break;
		case STOP:
		MOVE_STOP();
		case DRIFT_L:
		DRIFT_LEFT(packet->speed);
		break;
		case DRIFT_R:
		DRIFT_RIGHT(packet->speed);
		break;
		break;
	}
}
