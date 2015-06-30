#ifndef __BOARD__
#define __BOARD__

/*
*------------------------------------------------------------------------------
* device.h
*
* Include file for port pin assignments
*

*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* File				: device.h
*------------------------------------------------------------------------------
*

*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Include Files
*------------------------------------------------------------------------------
*/

#include <p18f8722.h>
#include <delays.h>
#include <timers.h>
#include "typedefs.h"
#include "config.h"


/*
*------------------------------------------------------------------------------
* Hardware Port Allocation
*------------------------------------------------------------------------------
*/



// Heart Beat




// Rs485 / RS232 Serial commnunicaton port
#define		TX1_EN					PORTGbits.RG3			// TX control for RS485 communication
#define		TX1_EN_DIR				TRISGbits.TRISG3
#define		TX2_EN					PORTGbits.RG4			// TX control for RS485 communication
#define		TX2_EN_DIR				TRISGbits.TRISG4


#define 	SER2_TX					PORTGbits.RG1 		// serial transmit
#define		SER2_TX_DIR				TRISGbits.TRISG1
#define 	SER2_RX					PORTGbits.RG2			// serial receive
#define		SER2_RX_DIR				TRISGbits.TRISG2


#define 	SER1_TX					PORTCbits.RC6 		// serial transmit
#define		SER1_TX_DIR				TRISCbits.TRISC6
#define 	SER1_RX					PORTCbits.RC7			// serial receive
#define		SER1_RX_DIR				TRISCbits.TRISC7


// I2C communication Port
#define 	I2C_SCL					PORTCbits.RC3
#define 	I2C_SCL_DIR 			TRISCbits.RC3
#define 	I2C_SDA					PORTCbits.RC4
#define 	I2C_SDA_DIR 			TRISCbits.RC4


// HeartBeat
#define		HEART_BEAT				PORTGbits.RG0			// high - OFF, Low - ON
#define		HEART_BEAT_DIR			TRISGbits.TRISG0

// MMD PORTS
#define 	DISPLAY_CONTROL				PORTFbits.RF0
#define 	DISPLAY_CONTROL_DIRECTION	TRISFbits.TRISF0

#define		DATA_PORT				PORTA	//LATD	 				// 7seg display data (DB0-DB7)
#define 	DATA_PORT_DIR			TRISA
#define		DIGIT_PORT				PORTE	//LATB	 				// digit drivers(upto 128 digits)
#define		DIGIT_PORT_DIR			TRISE	//LATB	 				// digit drivers(upto 128 digits)

#define		ROW_SEL_A				PORTDbits.RD7			// decoder digit sel A
#define		ROW_SEL_A_DIR			TRISDbits.TRISD7
#define		ROW_SEL_B				PORTDbits.RD6		// decoder digit sel B
#define		ROW_SEL_B_DIR			TRISDbits.TRISD6
#define		ROW_SEL_C				PORTDbits.RD5		// decoder digit sel C
#define		ROW_SEL_C_DIR			TRISDbits.TRISD5
#define		ROW_SEL_D				PORTDbits.RD4		// decoder digit sel D
#define		ROW_SEL_D_DIR			TRISDbits.TRISD4
#define		ROW_SEL_E				PORTDbits.RD3		// decoder digit sel E
#define		ROW_SEL_E_DIR			TRISDbits.TRISD3
#define		ROW_SEL_F				PORTDbits.RD2		// decoder digit sel F
#define		ROW_SEL_F_DIR			TRISDbits.TRISD2
#define		ROW_SEL_G				PORTDbits.RD1	// decoder digit sel G
#define		ROW_SEL_G_DIR			TRISDbits.TRISD1
#define		ROW_SEL_H				PORTDbits.RD0	// decoder digit sel G
#define		ROW_SEL_H_DIR			TRISDbits.TRISD0
//Digit Selection 
#define	DIGIT_SEL_A                     PORTJbits.RJ0
#define	DIGIT_SEL_A_DIRECTION			TRISJbits.TRISJ0
#define	DIGIT_SEL_B  					PORTJbits.RJ1
#define	DIGIT_SEL_B_DIRECTION 			TRISJbits.TRISJ1
#define	DIGIT_SEL_C						PORTJbits.RJ2
#define	DIGIT_SEL_C_DIRECTION  			TRISJbits.TRISJ2
#define	DIGIT_SEL_D						PORTJbits.RJ3
#define	DIGIT_SEL_D_DIRECTION  			TRISJbits.TRISJ3

#define	DIGIT_SEL_E						PORTJbits.RJ4
#define	DIGIT_SEL_E_DIRECTION  			TRISJbits.TRISJ4
#define	DIGIT_SEL_F						PORTJbits.RJ5
#define	DIGIT_SEL_F_DIRECTION  			TRISJbits.TRISJ5
#define	DIGIT_SEL_G						PORTJbits.RJ6
#define	DIGIT_SEL_G_DIRECTION  			TRISJbits.TRISJ6
#define	DIGIT_SEL_H						PORTJbits.RJ7
#define	DIGIT_SEL_H_DIRECTION  			TRISJbits.TRISJ7

//Display
#define	DISPLAY_PORT               PORTH
#define DISPLAY_PORT_DIRECTION     TRISH

//Keypad PortB
#define KEYPAD_PORT_0				PORTBbits.RB0
#define KEYPAD_PORT_0_DIRECTION		TRISBbits.TRISB0
#define KEYPAD_PORT_1				PORTBbits.RB1
#define KEYPAD_PORT_1_DIRECTION		TRISBbits.TRISB1
#define KEYPAD_PORT_2				PORTBbits.RB2
#define KEYPAD_PORT_2_DIRECTION		TRISBbits.TRISB2
#define KEYPAD_PORT_3				PORTBbits.RB3
#define KEYPAD_PORT_3_DIRECTION		TRISBbits.TRISB3
#define KEYPAD_PORT_4				PORTBbits.RB4
#define KEYPAD_PORT_4_DIRECTION		TRISBbits.TRISB4
#define KEYPAD_PORT_5				PORTBbits.RB5
#define KEYPAD_PORT_5_DIRECTION		TRISBbits.TRISB6
#define KEYPAD_PORT_6				PORTBbits.RB6
#define KEYPAD_PORT_6_DIRECTION		TRISBbits.TRISB6
#define KEYPAD_PORT_7				PORTBbits.RB7
#define KEYPAD_PORT_7_DIRECTION		TRISBbits.TRISB7



			
/*
*------------------------------------------------------------------------------
* Public Defines
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Macros
*------------------------------------------------------------------------------
*/



#define SYSTEM_CLOCK			(32000000UL)	// 8MHz internal oscillator	

#define PERIPHERAL_CLOCK			(SYSTEM_CLOCK / 4)UL

#define PERIPHERAL_CLOCK_PERIOD 	(1 / PERIPHERAL_CLOCK)UL



// Direction controle bit is processor specific ,
#define PORT_OUT				(BOOL)(0)
#define PORT_IN					(BOOL)(0xFF)

#define OFF_FOREVER				(BOOL)(0)
#define LOOP_FOREVER			(BOOL)(1)

#define SWITCH_OFF				(BOOL)(0)
#define SWITCH_ON				(BOOL)(1)

#define DISPLAY_DISABLE			(BOOL)(1)
#define DISPLAY_ENABLE			(BOOL)(0)


#define GetSystemClock()		(SYSTEM_CLOCK)      // Hz
#define GetInstructionClock()	(GetSystemClock()/4)
#define GetPeripheralClock()	GetInstructionClock()

#define ENTER_CRITICAL_SECTION()	INTCONbits.GIE = 0;// Disable global interrupt bit.


#define EXIT_CRITICAL_SECTION()		INTCONbits.GIE = 1;// Enable global interrupt bit.

#define ENABLE_GLOBAL_INT()			EXIT_CRITICAL_SECTION()


#define DISABLE_INT0_INTERRUPT()	INTCONbits.INT0IE = 0
#define ENABLE_INT0_INTERRUPT()		INTCONbits.INT0IE = 1
#define CLEAR_INTO_INTERRUPT()		INTCONbits.INT0IF = 0


#define DISABLE_TMR0_INTERRUPT()	INTCONbits.TMR0IE = 0
#define ENABLE_TMR0_INTERRUPT()		INTCONbits.TMR0IE = 1

#define DISABLE_TMR1_INTERRUPT()	PIE1bits.TMR1IE = 0
#define ENABLE_TMR1_INTERRUPT()		PIE1bits.TMR1IE = 1



#define DISABLE_UART2_TX_INTERRUPT()	PIE3bits.TX2IE = 0
#define ENABLE_UART2_TX_INTERRUPT()		PIE3bits.TX2IE = 1

#define DISABLE_UART2_RX_INTERRUPT()	PIE3bits.RC2IE = 0
#define ENABLE_UART2_RX_INTERRUPT()		PIE3bits.RC2IE = 1

#define DISABLE_UART1_TX_INTERRUPT()	PIE1bits.TX1IE = 0
#define ENABLE_UART1_TX_INTERRUPT()		PIE1bits.TX1IE = 1

#define DISABLE_UART1_RX_INTERRUPT()	PIE1bits.RC1IE = 0
#define ENABLE_UART1_RX_INTERRUPT()		PIE1bits.RC1IE = 1

#define ENB_485_TX()	TX_EN = 1;
#define ENB_485_RX()	TX_EN = 0

#define Delay10us(us)		Delay10TCYx(((GetInstructionClock()/1000000)*(us)))
#define DelayMs(ms)												\
	do																\
	{																\
		unsigned int _iTemp = (ms); 								\
		while(_iTemp--)												\
			Delay1KTCYx((GetInstructionClock()+999999)/1000000);	\
	} while(0)

/*
*------------------------------------------------------------------------------
* Public Data Types
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Variables (extern)
*------------------------------------------------------------------------------
*/


/*
*------------------------------------------------------------------------------
* Public Constants (extern)
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Function Prototypes (extern)
*------------------------------------------------------------------------------
*/

extern void BRD_init(void);

#endif
/*
*  End of device.h
*/