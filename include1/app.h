#include "board.h"
#include "typedefs.h"
#include "digitdisplay.h"
#include "linearkeypad.h"

typedef enum 
{
	WAIT = 0,
	COUNT 
}APP_STATE;



 typedef enum 
{
	START_PB = 0
	
}PB;

extern void APP_init(void);
UINT8 APP_comCallBack( UINT8 *rxPacket, UINT8* txCode, UINT8** txPacket);
void APP_task(void);


