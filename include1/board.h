

/*
*------------------------------------------------------------------------------
* board.h
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


/*
*------------------------------------------------------------------------------
* Include Files
*------------------------------------------------------------------------------
*/

#include <p18f46k22.h>
#include <delays.h>
#include <timers.h>
#include "typedefs.h"
#include "config.h"



/*
*------------------------------------------------------------------------------
* Hardware Port Allocation
*------------------------------------------------------------------------------
*/


//Heart Beat
#define 	HEART_BEAT					PORTEbits.RE0
#define 	HEART_BEAT_DIRECTION		TRISEbits.TRISE0

//Digit Selection 
#define	DIGIT_SEL_A                     PORTAbits.RA0
#define	DIGIT_SEL_A_DIRECTION			TRISAbits.TRISA0
#define	DIGIT_SEL_B  					PORTAbits.RA1
#define	DIGIT_SEL_B_DIRECTION 			TRISAbits.TRISA1
#define	DIGIT_SEL_C						PORTAbits.RA2
#define	DIGIT_SEL_C_DIRECTION  			TRISAbits.TRISA2
#define	DIGIT_SEL_D						PORTAbits.RA3
#define	DIGIT_SEL_D_DIRECTION  			TRISAbits.TRISA3

#define	DIGIT_SEL_E						PORTCbits.RC0
#define	DIGIT_SEL_E_DIRECTION  			TRISCbits.TRISC0
#define	DIGIT_SEL_F						PORTCbits.RC1
#define	DIGIT_SEL_F_DIRECTION  			TRISCbits.TRISC1
#define	DIGIT_SEL_G						PORTCbits.RC2
#define	DIGIT_SEL_G_DIRECTION  			TRISCbits.TRISC2
#define	DIGIT_SEL_H						PORTCbits.RC3
#define	DIGIT_SEL_H_DIRECTION  			TRISCbits.TRISC3

//Display
#define	DISPLAY_PORT               PORTD
#define DISPLAY_PORT_DIRECTION     TRISD

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


//Serial Communication
#define 	SER_TX					PORTCbits.RC6   		// serial transmit
#define		SER_TX_DIR				TRISCbits.TRISC6
#define 	SER_RX					PORTCbits.RC7			// serial receive
#define		SER_RX_DIR				TRISCbits.TRISC7

	
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

#define DEVICE_ID			(0x01)


#define PERIPHERAL_CLOCK			(SYSTEM_CLOCK / 4)UL

#define PERIPHERAL_CLOCK_PERIOD 	(1 / PERIPHERAL_CLOCK)UL



// Direction controle bit is processor specific ,
#define PORT_OUT				(BOOL)(0)
#define PORT_IN					(0XFF)

#define OFF_FOREVER				(BOOL)(0)
#define LOOP_FOREVER			(BOOL)(1)

#define SWITCH_OFF				(BOOL)(0)
#define SWITCH_ON				(BOOL)(1)


#define DISPLAY_DISABLE			(BOOL)(1)
#define DISPLAY_ENABLE			(BOOL)(0)
void EnableInterrupts(void);

/*
#ifdef __74LS374__
#undef DISPLAY_DISABLE
#undef DISPLAY_ENABLE

#define DISPLAY_DISABLE			(BOOL)(0)
#define DISPLAY_ENABLE			(BOOL)(1)

#endif 			//__74LS374__
*/


#define GetSystemClock()		(SYSTEM_CLOCK)      // Hz
#define GetInstructionClock()	(GetSystemClock()/4)
#define GetPeripheralClock()	GetInstructionClock()


#define BUZZER_ON()			BUZ_OP = SWITCH_ON;
#define BUZZER_OFF()		BUZ_OP = SWITCH_OFF;

// Disable global interrupt bit.
#define ENTER_CRITICAL_SECTION()	INTCONbits.GIE = 0;

// Enable global interrupt bit.
#define EXIT_CRITICAL_SECTION()		INTCONbits.GIE = 1;

#define ENABLE_GLOBAL_INT()			EXIT_CRITICAL_SECTION()


#define DISABLE_ADC_INTERRUPT()		PIE1bits.ADIE = 0
#define ENABLE_ADC_INTERRUPT()		PIE1bits.ADIE = 1

#define DISABLE_INT0_INTERRUPT()	INTCONbits.INT0IE = 0
#define ENABLE_INT0_INTERRUPT()		INTCONbits.INT0IE = 1
#define CLEAR_INTO_INTERRUPT()		INTCONbits.INT0IF = 0


#define DISABLE_TMR0_INTERRUPT()	INTCONbits.TMR0IE = 0
#define ENABLE_TMR0_INTERRUPT()		INTCONbits.TMR0IE = 1

#define DISABLE_TMR1_INTERRUPT()	PIE1bits.TMR1IE = 0
#define ENABLE_TMR1_INTERRUPT()		PIE1bits.TMR1IE = 1


#define DISABLE_UART_TX_INTERRUPT()	PIE1bits.TXIE = 0
#define ENABLE_UART_TX_INTERRUPT()	PIE1bits.TXIE = 1

#define DISABLE_UART1_RX_INTERRUPT()	PIE1bits.RCIE = 0
#define ENABLE_UART1_RX_INTERRUPT()	PIE1bits.RCIE = 1

#define DISABLE_UART2_TX_INTERRUPT()	PIE3bits.TX2IE = 0
#define ENABLE_UART2_TX_INTERRUPT()	PIE3bits.TX2IE = 1

#define DISABLE_UART2_RX_INTERRUPT()	PIE3bits.RC2IE = 0
#define ENABLE_UART2_RX_INTERRUPT()	PIE3bits.RC2IE = 1


#define HOLD_ATKBD_CLOCK()		    ATKBD_CLK_DIR= PORT_OUT;\
									ATKBD_CLK = 0;

#define RELEASE_ATKBD_CLOCK()	  	ATKBD_CLK_DIR = PORT_IN;\
									ATKBD_CLK = 1;

#define SET_INT0_FALLING_EDGE_TRIGGER()	INTCON2bits.INTEDG0 = 0

#define	ATKBD_INTERRUPT_EDGE	INTCON2.INTEDG0		

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


/*
*  End of board.h
*/