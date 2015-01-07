#include "app.h" 
#include "linearkeypad.h"
#include "config.h"
#include "board.h"
#include "communication.h"
#include "eep.h"



/*
*------------------------------------------------------------------------------
* Public Variables
* Buffer[0] = seconds, Buffer[1] = minutes, Buffer[2] = Hour,
* Buffer[3] = day, Buffer[4] = date, Buffer[5] = month, Buffer[6] = year
*------------------------------------------------------------------------------
*/



void APP_ASCIIconversion(void);
void APP_resetCounter_Buffer(void);


 

/*
*------------------------------------------------------------------------------
* app - the app structure. 
*------------------------------------------------------------------------------
*/
typedef struct _App
{   
    APP_STATE state;
    UINT16 Actual_Count;
    UINT8 Actual[NO_OF_DIGITS];
    UINT8 Plan[NO_OF_DIGITS];
	UINT8 Input_Recieved;
	UINT8 plan_eepUpdate;
	UINT8 actual_eepUpdate;
}APP;



#pragma idata APP_DATA
APP app = {0};
#pragma idata




/*
*------------------------------------------------------------------------------
* void APP_init(void)
*
* Summary	: Initialize application
*
* Input		: None
*
* Output	: None
*------------------------------------------------------------------------------
*/
void APP_init( void )
{ 
	UINT8 i;

	for(i= 0; i < NO_OF_DIGITS; i++)
	{
		app.Plan[i] = Read_b_eep(EPROM_ADD_PLAN + i  );
		Busy_eep();
	}

	app.Actual_Count = Read_b_eep(EPROM_ADD_ACTUAL);
	Busy_eep();
	app.Actual_Count <<= 8;
	app.Actual_Count |= Read_b_eep(EPROM_ADD_ACTUAL+1);
	Busy_eep();

	APP_ASCIIconversion();

	DigitDisplay_updateBufferPartial(app.Plan,0,4);
	DigitDisplay_updateBufferPartial(app.Actual,4,4);  

    app.state = COUNT;
}


/*
*------------------------------------------------------------------------------
* void APP_task(void)
*
* Summary	: 
*
* Input		: None
*
* Output	: None
*------------------------------------------------------------------------------
*/

void APP_task( void )
{
	UINT8 i;
	volatile UINT16 temp;


	switch(app.state)
	{
		case COUNT:
           if ((LinearKeyPad_getKeyState(START_PB) == 1)&& (app.Input_Recieved == 0))
           { 
   	       		if(app.Actual_Count < 9999)
				{
					app.Actual_Count++;
				}
				else
					app.Actual_Count = 0;
			    APP_ASCIIconversion();
			    DigitDisplay_updateBufferPartial(app.Actual,4 ,4);
			    app.Input_Recieved = 1;
				app.actual_eepUpdate = TRUE;
				app.state = WAIT;
			}
						
		break;

		case WAIT:
		     if ((LinearKeyPad_getKeyState(START_PB) == 0))
	         {
				app.Input_Recieved = 0;
                app.state = COUNT;
	         }      
		break;

		default:
		break;
	}

	if(app.actual_eepUpdate == TRUE)
	{
		temp = app.Actual_Count;
		app.actual_eepUpdate = FALSE;
	
		Write_b_eep(EPROM_ADD_ACTUAL, (UINT8)(temp >> 8));
		Busy_eep();

		Write_b_eep(EPROM_ADD_ACTUAL+1, (UINT8)temp );
		Busy_eep();
		
	}

	if(app.plan_eepUpdate == TRUE )
	{
		app.plan_eepUpdate = FALSE;  
		for(i= 0; i < NO_OF_DIGITS; i++)
		{
			Write_b_eep(EPROM_ADD_PLAN + i ,app.Plan[i] );
			Busy_eep();
			Write_b_eep(EPROM_ADD_ACTUAL + i ,0 );
			Busy_eep();
		}
	
	}

			
	 
}

/*
*------------------------------------------------------------------------------
* void APP_conversion(UINT16)
*
* Summary	: 
*
* Input		: None
*
* Output	: None
*------------------------------------------------------------------------------
*/
void APP_ASCIIconversion(void)
{  
	UINT8 i=0;
    UINT16 count = app.Actual_Count;

	for( i = 0; i < 4; i++)
	{
	       app.Actual[i] = (count % 10)  + '0';
		   count /= 10;
	}
 
}


/*
*------------------------------------------------------------------------------
* void APP_resetCounter_Buffer(void)
*
* Summary	: 
*
* Input		: None
*
* Output	: None
*------------------------------------------------------------------------------
*/
void APP_resetCounter_Buffer(void)
{
	UINT8 i;
	for(i = 0; i < NO_OF_DIGITS; i++)			//reset all digits
	{
		app.Actual[i] = '0';
	}
}	


/*
*------------------------------------------------------------------------------
* void APP_comCallBack(void)
*
* Summary	: 
*
* Input		: None
*
* Output	: None
*------------------------------------------------------------------------------
*/

UINT8 APP_comCallBack( UINT8 *rxPacket, UINT8* txCode, UINT8** txPacket)
{

	UINT8 i;
   	

	UINT8 rxCode = rxPacket[0];

	UINT8 length = 0;
		    	
	switch( rxCode )
 	{
	  	case SET_PLAN:
			app.plan_eepUpdate= TRUE;
		    app.Actual_Count = 0;
            APP_ASCIIconversion();
			DigitDisplay_updateBufferPartial(app.Actual, 4 ,4);

            for(i=0;i<4;i++)
				app.Plan[i] = rxPacket[i+1];
    
           	DigitDisplay_updateBufferPartial(app.Plan, 0 ,4);
			*txCode = SET_PLAN;
		   
		break;
	

        case MODIFY_PLAN:
			app.plan_eepUpdate = TRUE;

            for(i=0;i<4;i++)
                app.Plan[i] = rxPacket[i+1];

          	DigitDisplay_updateBufferPartial(app.Plan, 0 ,4);
			*txCode = MODIFY_PLAN;
		break;
	}

	return length;

}