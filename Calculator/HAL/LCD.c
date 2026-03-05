/*
 * LCD.c
 *
 * Created: 3/3/2026 9:34:33 PM
 *  Author: Mahmoud Ehab
 */ 

#include "LCD.h"

void LCD_Command(u8 comm)
{
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, PIN_HIGH);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, PIN_LOW);
	DIO_voidSetPortValue(LCD_DATA_PORT, comm);
	_delay_ms(3);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, PIN_LOW);
	
	_delay_ms(15);
}

void LCD_Data(u8 data)
{
	if (columnME < 40)
	{
		DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, PIN_HIGH);
		DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, PIN_HIGH);
		DIO_voidSetPortValue(LCD_DATA_PORT, data);
		_delay_ms(2);
		DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, PIN_LOW);
		columnME++;
		if (columnME >= max_columnME)
		{
			LCD_Command(LCD_SHIFT_LEFT);
		}
		
		_delay_ms(15);
	}
}

void LCD_ClearScreen(void)
{
	LCD_Command(LCD_CLR);
	LCD_MoveCursor(0, 0);
}

void LCD_Init(void)
{
	_delay_ms(30);
	DIO_voidSetPortDirection(LCD_CONTROL_PORT, 0b00000111);
	DIO_voidSetPortDirection(LCD_DATA_PORT, PORT_HIGH);
	LCD_Command(LCD_HOME);
	LCD_Command(LCD_FUN_SET_TWOLINE_5x8);
	LCD_Command(LCD_DIS_ON_SETUP);
	//LCD_Command(lcd_DisplayOn_CursorOn);
	LCD_ClearScreen();
	LCD_Command(LCD_EntryMode);
	LCD_MoveCursor(0, 0);
	columnME = 0;
	max_columnME = (columnME/16 + 1) * 16 - 1;
}

void LCD_SendString(const u8 *Str)
{
	while (*Str)
	{
		LCD_Data(*Str);
		Str++;
	}
}

void LCD_MoveCursor(u8 row, u8 col)
{
	columnME = col;
	
	LCD_Command(LCD_HOME);
	
	if (row == 0)
	{
		LCD_Command(0x80 + col);
	}
	else
	{
		LCD_Command(0x80 + 0x40 + col);
	}
	
	max_columnME = (columnME/16 + 1) * 16 - 1;
	
	for (int i = 0; i < columnME/16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			LCD_Command(LCD_SHIFT_LEFT);
		}
	}
}

void LCD_SendString_MV_CR (u8 *Str,u8 row,u8 col)
{
	LCD_MoveCursor(row, col);
	LCD_SendString(Str);
}

void LCD_Scroll_RIGHT(u8 no)
{
	while(no--)
	{
		LCD_Command(LCD_SHIFT_LEFT);
	}
}

void LCD_Scroll_LEFT(u8 no)
{
	while(no--)
	{
		LCD_Command(LCD_SHIFT_RIGHT);
	}
}

void LCD_SET_CGRAM(u8 address)
{
	LCD_Command(0x40 | address);
}