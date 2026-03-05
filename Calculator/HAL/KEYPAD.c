/*
 * CFile1.c
 *
 * Created: 3/3/2026 4:09:14 PM
 *  Author: Mahmoud Ehab
 */ 

#include "KEYPAD.h"
#include <util/delay.h>

void KEYPAD_Init(void)
{
	DIO_voidSetPortDirection(KEYPAD_PORT, 0b00001111);
	DIO_voidSetPortValue(KEYPAD_PORT, PORT_HIGH);
}

u8 KEYPAD_GetPressedKey(void)
{	
	u8 KEYPAD_ARR[][4] =  {
		{'7','8','9','/'},
		{'4','5','6','X'},
		{'1','2','3','-'},
		{'*','0','=','+'}
	};
	
	int arr_col_pins[] = {
		KEYPAD_C1_PIN,
		KEYPAD_C2_PIN,
		KEYPAD_C3_PIN,
		KEYPAD_C4_PIN
	};
	
	int arr_row_pins[] = {
		KEYPAD_R1_PIN,
		KEYPAD_R2_PIN,
		KEYPAD_R3_PIN,
		KEYPAD_R4_PIN
	};
	
	for (int i = 0; i < KEYPAD_NO_COL; i++)
	{
		DIO_voidSetPinValue(KEYPAD_PORT, arr_col_pins[i], PIN_LOW);
		
		for (int j = 0; j < KEYPAD_NO_ROW; j++)
		{
			if (DIO_u8GetPinValue(KEYPAD_PORT, arr_row_pins[j]) == PIN_LOW)
			{
				_delay_ms(30);
				while (DIO_u8GetPinValue(KEYPAD_PORT, arr_row_pins[j]) == PIN_LOW) {}
				
				return KEYPAD_ARR[j][i];
			}
		}
		
		DIO_voidSetPinValue(KEYPAD_PORT, arr_col_pins[i], PIN_HIGH);
	}
	
	return PORT_LOW;
}