#ifndef CONFIG_H
#define CONFIG_H

/*
*------------------------------------------------------------------------------
* config.h
*
*/

/*----------------------------------------
*	OSCILLATOR CONFIG
*----------------------------------------*/

#define SYSTEM_CLOCK			(16000000UL)	// Hz		// 8MHz internal oscillator


/*----------------------------------------
*	TIMER CONFIG
*----------------------------------------*/
#define FULLSCALE_16BIT				(65535)
#define TIMER0_TIMEOUT_DURATION 	(1000UL)			//1ms			

/*----------------------------------------
*	DEVICE CONFIG
*----------------------------------------*/
#define __FACTORY_CONFIGURATION__
#define TIMESTAMP_DURATION 		(200)
//MMD module configuration
#define MMD_MAX_CHARS			8
#define MMD_MAX_SEGMENTS		4
#define MMD_MAX_ADDRESS			128
#define __MMD_STATIC__



/*----------------------------------------
*	UART CONFIG
*----------------------------------------*/
#define UART1_BAUDRATE		19200
//#define UART2_BAUDRATE
#define ACTIVE_USARTS			1

//#define UART2

#define UART_TEST

/*--------------------
*	COM module configuration
*----------------------------------------*/
#define DEVICE_ADDRESS  		0x01
#define __BCC_XOR__
#define __RESPONSE_ENABLED__
//#define __LOOP_BACK__
#define BROADCAST_ADDRESS		0xFF
#define CMD_SOP					0xAA
#define CMD_EOP 				0xBB
#define RESP_SOP				0xCC
#define RESP_EOP				0xDD
#define __NO_CHECKSUM__



enum
{
	CMD_PACKET_SIZE = 30,
	RESP_PACKET_SIZE = 30
};

#define RX_PACKET_SIZE		(60)	
#define TX_PACKET_SIZE		(60)

/*----------------------------------------
*	Display module configuration
*----------------------------------------*/
#define __DISPLAY_TEST__
#define MAX_MSG 			7
//#define COMMON_CATHODE


// Enable for external eeprom access
// Comment out this line if internal eeprom access required
#define EEP_EXTERRNAL
// For uart enable
#define EN_UART
// Enable for hardware i2c module usage
//#define USE_MSSP_I2C

/*----------------------------------------
*	RTC CONFIGURATION
*----------------------------------------*/

//#define TIME_DEBUG

//#define RTC_DS1307
//#define RTC_DS3232


/*----------------------------------------
*	Keypad Configurations
*----------------------------------------*/

//#define __FACTORY_CONFIGURATION__
//#define __SIMULATION__
/*----------------------------------------
*	App Configurations
*----------------------------------------*/

#define EPROM_ADD_PLAN  	0
#define EPROM_ADD_ACTUAL 	4
#define SET_PLAN 			0x81
#define MODIFY_PLAN 		0x82

#define NO_OF_DIGITS		(0X04)
#define MAX_COUNT			(9999)

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

#endif
/*
*  End of config.h
*/



