/*
 * Calculator.c
 *
 * Created: 3/4/2026 1:30:58 PM
 * Author : Mahmoud Ehab
 */ 

#include <avr/io.h>
#include "HAL/KEYPAD.h"
#include "HAL/LCD.h"
#include "LIB/Linkedlist.h"
#include "LIB/Calculator.h"

int tokenize_int(int x)
{
	if (x == 0)
	{
		return x;
	}
	else if (x < 0)
	{
		x = -x;
	}
	tokenize_int(x/10);

	LCD_Data((x%10) + 48);
}

int int_length(int x)
{
	int length = 0;
	
	if (x < 0)
	{
		x = -x;
	}
	else if (x == 0)
	{
		return 1;
	}
	
	while (x > 0)
	{
		length++;
		x /= 10;
	}
	
	return length;
}

int main(void)
{
	KEYPAD_Init();
	LCD_Init();
	Linkedlist num_list;
	Linkedlist calc_list;
	int result;
	int length = 0;
	
	Linkedlist_constructor(&num_list);
	Linkedlist_constructor(&calc_list);
	
	u8 keypressed;

    while (1) 
    {
		keypressed = KEYPAD_GetPressedKey();

		switch (keypressed)
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			if (columnME < 40)
			{
				append(&num_list, keypressed, 0);
				LCD_Data(keypressed);
			}
			break;
			case '+':
			case '-':
			case 'X':
			case '/':
			if (columnME < 40)
			{
				if (num_list.length > 0)
				{
					append(&calc_list, parse_int(&num_list), 0);
					empty(&num_list);
				}
				append(&calc_list, keypressed, 1);
				LCD_Data(keypressed);
			}
			break;
			case '*':
			LCD_ClearScreen();
			empty(&num_list);
			empty(&calc_list);
			break;
			case '=':
			append(&calc_list, parse_int(&num_list), 0);
			empty(&num_list);
			result = calculate(&calc_list);
			length = int_length(result);
			if (result < 0)
			{
				length++;
			}
			
			LCD_MoveCursor(1, 14 - length);
			
			if (result < 0)
			{
				LCD_Data('-');
			}
			
			if (result != 0)
			{
				tokenize_int(result);
			}
			else
			{
				LCD_Data('0');
			}
			break;
		}
    }
}

