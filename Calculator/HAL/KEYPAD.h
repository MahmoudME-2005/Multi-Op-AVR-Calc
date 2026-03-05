/*
 * KEYPAD.h
 */ 
#include "../MCAL/DIO.h"



#ifndef KEYPAD_H_
#define KEYPAD_H_


/*
#define KEYPAD_ARR  {  
	{'7','8','9','/'},\
	{'4','5','6','X'},\
	{'1','2','3','-'},\
	{'*','0','=','+'} }
*/
#define KEYPAD_NO_ROW  4
#define KEYPAD_NO_COL  4

#define  KEYPAD_PORT PORTA_ID

//#define KEYPAD_ROWPORT  PORTB_ID
//#define KEYPAD_ROWPORT_READ  PINB


//#define KEYPAD_COLPORT  PORTA_ID




#define KEYPAD_R1_PIN	 PIN7
#define KEYPAD_R2_PIN	 PIN6
#define KEYPAD_R3_PIN	 PIN5
#define KEYPAD_R4_PIN	 PIN4

#define KEYPAD_C1_PIN	 PIN3
#define KEYPAD_C2_PIN	 PIN2
#define KEYPAD_C3_PIN	 PIN1
#define KEYPAD_C4_PIN	 PIN0

#define KEY_NOT_PRESSED  HIGH
#define KEY_PRESSED  LOW


/******************************************functions***********************************/
void KEYPAD_Init(void);

u8 KEYPAD_GetPressedKey(void);


#endif KEYPAD_H_