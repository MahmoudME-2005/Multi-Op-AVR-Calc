/*
 * DIO.c
 *
 * Created: 2/13/2026 5:04:30 PM
 *  Author: Mahmoud Ehab
 */ 

#include "DIO.h"

void DIO_voidSetPortDirection(u8 Copy_u8PORT, u8 Copy_u8Direction)
{
	if (Copy_u8PORT < NUM_OF_PORTS)	
	{
		switch (Copy_u8PORT)
		{
			case PORTA_ID:
			DDRA = Copy_u8Direction;
			break;
			case PORTB_ID:
			DDRB = Copy_u8Direction;
			break;
			case PORTC_ID:
			DDRC = Copy_u8Direction;
			break;
			case PORTD_ID:
			DDRD = Copy_u8Direction;
			break;
		}
	}
}

void DIO_voidSetPortValue(u8 Copy_u8PORT, u8 Copy_u8Value)
{
	if (Copy_u8PORT < NUM_OF_PORTS)
	{
		switch (Copy_u8PORT)
		{
			case PORTA_ID:
			PORTA = Copy_u8Value;
			break;
			case PORTB_ID:
			PORTB = Copy_u8Value;
			break;
			case PORTC_ID:
			PORTC = Copy_u8Value;
			break;
			case PORTD_ID:
			PORTD = Copy_u8Value;
			break;
		}
	}
}

u8 DIO_u8GetPortValue(u8 Copy_u8PORT)
{
	if (Copy_u8PORT < 4)
	{
		switch (Copy_u8PORT)
		{
			case PORTA_ID:
			return PINA;
			break;
			case PORTB_ID:
			return PINB;
			break;
			case PORTC_ID:
			return PINC;
			break;
			case PORTD_ID:
			return PIND;
			break;
		}
	}
	else
	{
		return 0;
	}
}

void DIO_voidSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
	if (Copy_u8PORT < 4 && Copy_u8Pin < 8)
	{
		switch (Copy_u8PORT)
		{
			case PORTA_ID:
				if (Copy_u8Direction == 1)
				{
					SET_BIT(DDRA, Copy_u8Pin);
				}
				else if (Copy_u8Direction == 0)
				{
					CLR_BIT(DDRA, Copy_u8Pin);
				}
			break;
			case PORTB_ID:
				if (Copy_u8Direction == 1)
				{
					SET_BIT(DDRB, Copy_u8Pin);
				}
				else if (Copy_u8Direction == 0)
				{
					CLR_BIT(DDRB, Copy_u8Pin);
				}
			break;
			case PORTC_ID:
				if (Copy_u8Direction == 1)
				{
					SET_BIT(DDRC, Copy_u8Pin);
				}
				else if (Copy_u8Direction == 0)
				{
					CLR_BIT(DDRC, Copy_u8Pin);
				}
			break;
			case PORTD_ID:
				if (Copy_u8Direction == 1)
				{
					SET_BIT(DDRD, Copy_u8Pin);
				}
				else if (Copy_u8Direction == 0)
				{
					CLR_BIT(DDRD, Copy_u8Pin);
				}
			break;
		}
	}
}

void DIO_voidSetPinValue(u8 Copy_u8PORT, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	if (Copy_u8PORT < 4 && Copy_u8Pin < 8)
	{
		switch (Copy_u8PORT)
		{
			case PORTA_ID:
			if (Copy_u8Value == 1)
			{
				SET_BIT(PORTA, Copy_u8Pin);
			}
			else if (Copy_u8Value == 0)
			{
				CLR_BIT(PORTA, Copy_u8Pin);
			}
			break;
			case PORTB_ID:
			if (Copy_u8Value == 1)
			{
				SET_BIT(PORTB, Copy_u8Pin);
			}
			else if (Copy_u8Value == 0)
			{
				CLR_BIT(PORTB, Copy_u8Pin);
			}
			break;
			case PORTC_ID:
			if (Copy_u8Value == 1)
			{
				SET_BIT(PORTC, Copy_u8Pin);
			}
			else if (Copy_u8Value == 0)
			{
				CLR_BIT(PORTC, Copy_u8Pin);
			}
			break;
			case PORTD_ID:
			if (Copy_u8Value == 1)
			{
				SET_BIT(PORTD, Copy_u8Pin);
			}
			else if (Copy_u8Value == 0)
			{
				CLR_BIT(PORTD, Copy_u8Pin);
			}
			break;
		}
	}
}

u8 DIO_u8GetPinValue(u8 Copy_u8PORT, u8 Copy_u8Pin)
{
	if (Copy_u8PORT < 4 && Copy_u8Pin < 8)
	{
		switch (Copy_u8PORT)
		{
			case PORTA_ID:
			return GET_BIT(PINA, Copy_u8Pin);
			break;
			case PORTB_ID:
			return GET_BIT(PINB, Copy_u8Pin);
			break;
			case PORTC_ID:
			return GET_BIT(PINC, Copy_u8Pin);
			break;
			case PORTD_ID:
			return GET_BIT(PIND, Copy_u8Pin);
			break;
		}
	}
	else
	{
		return PIN_LOW;
	}
}