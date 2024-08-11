/*
 * gpio.c
 *
 *  Created on: May 26, 2024
 *      Author: Redaa
 */
#include"gpio.h"
#include<avr/io.h>

void GPIO_setupPinDirection( uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction) {
	if (port_num > PORTS_NUMBER || pin_num > PINS_NUMBER) {

	} else {
		switch (port_num) {
		case PORT_A:
			if (direction == PIN_OUTPUT) {
				SET_BIT(DDRA, pin_num);
			} else {
				CLEAR_BIT(DDRA, pin_num);
			}
			break;
		case PORT_B:
			if (direction == PIN_OUTPUT) {
				SET_BIT(DDRB, pin_num);
			} else {
				CLEAR_BIT(DDRB, pin_num);
			}
			break;
		case PORT_C:
			if (direction == PIN_OUTPUT) {
				SET_BIT(DDRC, pin_num);
			} else {
				CLEAR_BIT(DDRC, pin_num);
			}
			break;
		case PORT_D:
			if (direction == PIN_OUTPUT) {
				SET_BIT(DDRD, pin_num);
			} else {
				CLEAR_BIT(DDRD, pin_num);
			}
			break;
		}
	}

}

void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 val) {
	if (port_num > PORTS_NUMBER || pin_num > PINS_NUMBER) {

	} else {
		switch (port_num) {
		case PORT_A:
			if (val == LOGIC_HIGH) {
				SET_BIT(PORTA, pin_num);
			} else {
				CLEAR_BIT(PORTA, pin_num);
			}
			break;
		case PORT_B:
			if (val == LOGIC_HIGH) {
				SET_BIT(PORTB, pin_num);
			} else {
				CLEAR_BIT(PORTB, pin_num);
			}
			break;
		case PORT_C:
			if (val == LOGIC_HIGH) {
				SET_BIT(PORTC, pin_num);
			} else {
				CLEAR_BIT(PORTC, pin_num);
			}
			break;
		case PORT_D:
			if (val == LOGIC_HIGH) {
				SET_BIT(PORTD, pin_num);
			} else {
				CLEAR_BIT(PORTD, pin_num);
			}
			break;
		}
	}

}

uint8 GPIO_readPin(uint8 port_num, uint8 pin_num) {
	if (port_num > PORTS_NUMBER || pin_num > PINS_NUMBER) {
		return LOGIC_LOW;
	} else {
		switch (port_num) {
		case PORT_A:
			if (BIT_IS_SET(PINA, pin_num)) {
				return LOGIC_HIGH;
			} else {
				return LOGIC_LOW;
			}
			break;
		case PORT_B:
			if (BIT_IS_SET(PINB, pin_num)) {
				return LOGIC_HIGH;
			} else {
				return LOGIC_LOW;
			}
			break;
		case PORT_C:
			if (BIT_IS_SET(PINC, pin_num)) {
				return LOGIC_HIGH;
			} else {
				return LOGIC_LOW;
			}
			break;
		case PORT_D:
			if (BIT_IS_SET(PIND, pin_num)) {
				return LOGIC_HIGH;
			} else {
				return LOGIC_LOW;
			}
			break;
		default:
			return LOGIC_LOW;
		}
	}
}


void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction)
{
	if (port_num > PORTS_NUMBER) {

	}
	else{
		switch(port_num){
		case PORT_A:
				DDRA=direction;
			break;
		case PORT_B:
			DDRB=direction;
			break;
		case PORT_C:
			DDRC=direction;
			break;
		case PORT_D:
			DDRD=direction;
			break;
		}
	}

}
void GPIO_writePort(uint8 port_num, uint8 value)
{
	if (port_num > PORTS_NUMBER) {

	} else {
		switch (port_num) {
		case PORT_A:
			PORTA=value;
			break;
		case PORT_B:
			PORTB=value;
			break;
		case PORT_C:
			PORTC=value;
			break;
		case PORT_D:
			PORTD=value;
			break;
		}
	}
}

uint8 GPIO_readPort(uint8 port_num)
{
	if (port_num > PORTS_NUMBER) {
		return LOGIC_LOW;
	} else {
		switch (port_num) {
		case PORT_A:
			return PINA;
		break;
		case PORT_B:
			return PINB;
			break;
		case PORT_C:
			return PINC;
			break;
		case PORT_D:
			return PIND;
			break;
		default:
			return LOGIC_LOW;
		}
	}
}
