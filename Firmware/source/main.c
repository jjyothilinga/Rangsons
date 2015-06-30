
/*
*------------------------------------------------------------------------------
* main.c
*
* main application specific module.
*
* (C)2008 Sam's Logic.
*
* The copyright notice above does not evidence any
* actual or intended publication of such source code.
*
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* File				: main.c
* Created by		: Sam
* Last changed by	: Sam
* Last changed		: 07/07/2009
*------------------------------------------------------------------------------
*
* Revision 0.0 07/07/2009 Sam
* Initial revision
*
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Include Files
*------------------------------------------------------------------------------
*/

#include "board.h"
#include "timer.h"	// Timer related functions
#include "uart.h"
#include "communication.h"
#include "heartBeat.h"
#include "app.h"
#include "mmd.h"

#include "digitdisplay.h"
#include "linearkeypad.h"

/*
*------------------------------------------------------------------------------
* Private Defines
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Processor config bits
*------------------------------------------------------------------------------
*/

#pragma config OSC     = INTIO67
#pragma config FCMEN    = OFF
#pragma config IESO     = OFF
#pragma config PWRT     = OFF
#pragma config BOREN    = ON
#pragma config BORV     = 3
#pragma config WDT      = OFF
#pragma config WDTPS    = 512	//32768
#pragma config MODE 	= MC
#pragma config MCLRE    = ON
#pragma config LPT1OSC  = OFF
//#pragma config PBADEN   = OFF
#pragma config STVREN   = ON
#pragma config LVP      = OFF
//#pragma config ICPRT  = OFF       // Dedicated In-Circuit Debug/Programming
#pragma config XINST    = OFF       // Extended Instruction Set
#pragma config CP0      = OFF
#pragma config CP1      = ON
#pragma config CP2      = ON
#pragma config CP3      = ON
#pragma config CPB      = ON
#pragma config CPD      = OFF
#pragma config WRT0     = OFF
#pragma config WRT1     = OFF
#pragma config WRT2     = OFF
//#pragma config WRT3   = OFF
#pragma config WRTB     = OFF//N       // Boot Block Write Protection
#pragma config WRTC     = OFF
#pragma config WRTD     = OFF
#pragma config EBTR0    = OFF
#pragma config EBTR1    = OFF
#pragma config EBTR2    = OFF
#pragma config EBTR3    = OFF
#pragma config EBTRB    = OFF


extern UINT32 TimerUpdate_count;
extern UINT16 keypadUpdate_count;


/*
*------------------------------------------------------------------------------
* Private Macros
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Private Data Types
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Variables
*------------------------------------------------------------------------------
*/
void EnableInterrupts(void);
extern UINT16 heartBeatCount ;
extern UINT16 comUpdateCount ;
extern UINT16 mmdUpdateCount;
/*
*------------------------------------------------------------------------------
* Private Variables (static)
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Constants
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Private Constants (static)
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Private Function Prototypes (static)
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Functions
*------------------------------------------------------------------------------
*/


/*
*------------------------------------------------------------------------------
* void main(void)

* Summary	: Application specifc main routine. Initializes all port and
*			: pheriperal and put the main task into an infinite loop.
*
* Input		: None
*
* Output	: None
*
*------------------------------------------------------------------------------
*/

#define MMD_REFRESH_PERIOD	(65535 - 20000)
#define TICK_PERIOD	(65535 - 2000) //250us


void main(void)
{
	UINT8 i,j, count;
	BOOL ledStrip_On = 0;
/*
	MMD_Config mmdConfig= {0};
	UINT8 line[10] ="LINE "; 
*/

	BRD_init();
	HB_init();
	DigitDisplay_init(MAX_DIGITS); 
	MMD_init();  // Display initialization



	COM_init(CMD_SOP,CMD_EOP,RESP_SOP,RESP_EOP,APP_comCallBack);
	
	APP_init();

	TMR0_init(TICK_PERIOD,DigitDisplay_task);	//initialize timer0
	TMR1_init(MMD_REFRESH_PERIOD,MMD_refreshDisplay);


	EnableInterrupts();

/*
	MMD_clearSegment(0);
	mmdConfig.startAddress = 0;
	mmdConfig.length = 6;
	mmdConfig.symbolCount = 5;
	mmdConfig.symbolBuffer = line;
	mmdConfig.scrollSpeed = SCROLL_SPEED_LOW;
			
	MMD_configSegment( 0 , &mmdConfig);
*/


	while(1)
	{

		if(  heartBeatCount >= 2000 )
		{
			//APP_task();
			HB_task();
			heartBeatCount = 0;
		}

		if( mmdUpdateCount >= 10 )
		{
			MMD_task();
			mmdUpdateCount = 0;
		}

		if(keypadUpdate_count >=15 )
		{
          keypadUpdate_count = 0;
		  LinearKeyPad_scan();
		  count++;
		}

		if(count >=5 )
		{
		  APP_task();
          count = 0;
		
		}

		COM1_task();
		//ClrWdt();	
	}
}

/*
*  End of main.c
*/