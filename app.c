/*
 * app.c
 *
 *  Created on: May 26, 2024
 *      Author: Redaa
 */
#include "gpio.h"
#include "lcd.h"
#include "keypad.h"
#include "util/delay.h"
#define INITIAL_ROW 0
#define INITIAL_COL 0
#define DELAY 100

uint16 calculator(uint8 num1, uint8 num2, uint8 oper);

int main(void)
{

	uint8 number1, number2, operatorr;
	LCD_init();
	LCD_clearScreen();
	LCD_moveCursor(INITIAL_ROW, INITIAL_COL);
	char first[] = "Enter the first number";
	char second[] = "Enter the second number";
	char operatorrr[] = "Enter the operator";
	char result_str[] = "The Result =";

	while(1) {
		LCD_moveCursor(INITIAL_ROW, INITIAL_COL);
		LCD_displayString(first);
		_delay_ms(DELAY);
		number1 = KEYPAD_getPressedKey();
		while(number1==0);

		LCD_clearScreen();
		_delay_ms(DELAY);

		LCD_moveCursor(INITIAL_ROW, INITIAL_COL);
		LCD_displayString(operatorrr);
		_delay_ms(DELAY);
		operatorr = KEYPAD_getPressedKey();
		while(operatorr==0);

		LCD_clearScreen();
		_delay_ms(DELAY);

		LCD_moveCursor(INITIAL_ROW, INITIAL_COL);
		LCD_displayString(second);
		_delay_ms(DELAY);
		number2 = KEYPAD_getPressedKey();
		while(number2==0);

		LCD_clearScreen();
		_delay_ms(DELAY);

		LCD_moveCursor(INITIAL_ROW, INITIAL_COL);
		uint8 equal=KEYPAD_getPressedKey();
		while(equal != '='){
			equal=KEYPAD_getPressedKey();
		}

		LCD_displayString(result_str);
		_delay_ms(DELAY);
		LCD_moveCursor(1, 6);
		LCD_intgerToString(calculator(number1, number2, operatorr));
		_delay_ms(DELAY*10);
		LCD_clearScreen();




	}
}

uint16 calculator(uint8 num1, uint8 num2, uint8 oper)
{
	uint8 result = 0;
	switch (oper) {
		case '+':
			result = num1 + num2;
			break;
		case '/':
			result = num1 / num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
	}
	return result;
}
