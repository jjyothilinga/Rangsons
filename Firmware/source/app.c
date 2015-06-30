#include "digitdisplay.h"
#include "mmd.h"
#include "string.h"
#include "app.h"
#include "linearkeypad.h"
#include "typedefs.h"
#include "eep.h"




void APP_ASCIIconversion(void);
void APP_resetCounter_Buffer(void);


/*
*------------------------------------------------------------------------------
* app - the app structure. 
*------------------------------------------------------------------------------
*/
typedef struct _APP
{
	//Variables to handle dot matrix display
	UINT8 model[MSG_LENGTH];
	UINT8 eepUpdate;

	//Variables to handle seven segment display
    APP_STATE state;
    UINT16 Actual_Count;
    UINT8 Actual[NO_OF_DIGITS];
    UINT8 Plan[NO_OF_DIGITS];
	UINT8 Input_Recieved;
	UINT8 plan_eepUpdate;
	UINT8 plan_eepModify;
	UINT8 actual_eepUpdate;
}APP;

#pragma idata APP_DATA
APP app = {{0},0};
MMD_Config mmdConfig = {0};
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

void APP_init(void)
{
	UINT8 i = 0;

	//Dot matrix initialization
	do
	{
			app.model[i] = Read_b_eep(EEPROM_ADDRESS+i);
			Busy_eep();	
	}while(app.model[i++]);

	MMD_clearSegment(0);
	mmdConfig.startAddress = 0;
	mmdConfig.length = MMD_MAX_CHARS;
	mmdConfig.symbolCount = strlen(app.model);
	mmdConfig.symbolBuffer = app.model;
	mmdConfig.scrollSpeed = 0;//SCROLL_SPEED_LOW;
	MMD_configSegment( 0 , &mmdConfig);


	//Seven segment display initialization
	for(i= 0; i < NO_OF_DIGITS; i++)
	{
		app.Plan[i] = Read_b_eep(EPROM_ADD_PLAN + i  );
		Busy_eep();
	}

  	for(i= 0; i < NO_OF_DIGITS; i++)
	{
		app.Actual[i] = Read_b_eep(EPROM_ADD_ACTUAL + i  );
		Busy_eep();
	}
	app.Actual_Count = (((app.Actual[3] - '0')* 1000) + ((app.Actual[2] - '0')* 100 )+ ((app.Actual[1] - '0')* 10) + (app.Actual[0] - '0'));
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

void APP_task(void)
{

	UINT8 i;
	volatile UINT16 temp;

	//Update model name in EEPROM
	if(app.eepUpdate == TRUE)
	{
		app.eepUpdate = FALSE;
		for( i = 0; i <= (strlen(app.model)); i++ )
			{
				Write_b_eep( EEPROM_ADDRESS+i , app.model[i] );
				Busy_eep( );
			}		
	}	



	
	switch(app.state)
	{
		case COUNT:
           if ((LinearKeyPad_getKeyState(START_PB) == TRUE )&& (app.Input_Recieved == FALSE))
           { 

   	       		if(app.Actual_Count < 9999)
				{
					++app.Actual_Count;
				}
				else
					app.Actual_Count = 0;

			    APP_ASCIIconversion();


			    DigitDisplay_updateBufferPartial(app.Actual,4 ,4);
			    app.Input_Recieved = TRUE;
				app.actual_eepUpdate = TRUE;
				app.state = WAIT;
			}
						
		break;

		case WAIT:
		     if ((LinearKeyPad_getKeyState(START_PB) == FALSE))
	         {
				app.Input_Recieved = FALSE;
                app.state = COUNT;
	         }      
		break;

		default:
		break;
	}

	//Update actual count in EEPROM
	if(app.actual_eepUpdate == TRUE)
	{
		app.actual_eepUpdate = FALSE;
		for(i= 0; i < NO_OF_DIGITS; i++)
		{
			Write_b_eep(EPROM_ADD_ACTUAL+ i ,app.Actual[i] );
			Busy_eep();
		}
	}

	//Update planned quantity in EEPROM
	if(app.plan_eepUpdate == TRUE )
	{
		app.plan_eepUpdate = FALSE;  
		for(i= 0; i < NO_OF_DIGITS; i++)
		{
			Write_b_eep(EPROM_ADD_PLAN + i ,app.Plan[i] );
			Busy_eep();
			Write_b_eep(EPROM_ADD_ACTUAL + i ,'0' );
			Busy_eep();
		}
	
	}

	if(app.plan_eepModify == TRUE )
	{
		app.plan_eepModify = FALSE;  
		for(i= 0; i < NO_OF_DIGITS; i++)
		{
			Write_b_eep(EPROM_ADD_PLAN + i ,app.Plan[i] );
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

UINT8 APP_comCallBack( far UINT8 *rxPacket, far UINT8* txCode,far UINT8** txPacket)
{

	UINT8 i;

	UINT8 rxCode = rxPacket[0];
	UINT8 length = 0;

	switch( rxCode )
	{
		case CMD_SET_MODEL:
			app.eepUpdate = TRUE;
			strcpy(app.model,&rxPacket[1]);
			MMD_clearSegment(0);
			mmdConfig.startAddress = 0;
			mmdConfig.length = MMD_MAX_CHARS;
			mmdConfig.symbolCount = strlen(app.model);
			mmdConfig.symbolBuffer = app.model;
			mmdConfig.scrollSpeed = 0;//SCROLL_SPEED_LOW;
			MMD_configSegment( 0 , &mmdConfig);

			*txCode = CMD_SET_MODEL;
			break;

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

			app.plan_eepModify = TRUE;

            for(i=0;i<4;i++)
                app.Plan[i] = rxPacket[i+1];

          	DigitDisplay_updateBufferPartial(app.Plan, 0 ,4);
			*txCode = MODIFY_PLAN;
		break;

		default:
		break;

	}

	return length;

}
