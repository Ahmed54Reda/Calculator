/*
 * gpio.h
 *
 *  Created on: May 26, 2024
 *      Author: Redaa
 */
#include"std_types.h"
#include"common_macros.h"
#ifndef GPIO_H_
#define GPIO_H_

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3


#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7


#define PORTS_NUMBER 4
#define PINS_NUMBER 8


typedef enum
{
PIN_INPUT,
PIN_OUTPUT
}GPIO_PinDirectionType;

typedef enum
{
PORT_INPUT,
PORT_OUTPUT=0xFF
}GPIO_PortDirectionType;


/*
 *
 *
 *
 */
void GPIO_setupPinDirection( uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction);
/*
 *
 *
 *
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 val);
/*
 *
 *
 *
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num);
/*
 *
 *
 *
 */
void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction);
/*
 *
 *
 *
 */
void GPIO_writePort(uint8 port_num, uint8 value);
/*
 *
 *
 *
 */
uint8 GPIO_readPort(uint8 port_num);
#endif /* GPIO_H_ */
