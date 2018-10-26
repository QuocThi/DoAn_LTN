#include "NUC_config.h"

void vibration()
{
	// Rung
	DrvGPIO_Open(E_GPC,0,E_IO_OUTPUT);
	DrvGPIO_SetBit(E_GPC,0);
	DrvSYS_Delay(500000);
}


int main()
{
	ESP_config();
	ESP_set_vibration_handler(vibration);
	NUC_button_config();
	set_debounce_button();
	while(1)
	{
		//Button press handler
		if(!DrvGPIO_GetBit(E_GPC,1))
		{
			ESP_send_key(KEY_DOWN);
			DrvSYS_Delay(100000);
		}
		if(!DrvGPIO_GetBit(E_GPC,2))
		{
			ESP_send_key(KEY_RIGHT);
				DrvSYS_Delay(100000);
		}
		if(!DrvGPIO_GetBit(E_GPC,3))
		{
			ESP_send_key(KEY_LEFT);
				DrvSYS_Delay(100000);
		}
		if(!DrvGPIO_GetBit(E_GPD,7))
		{
			ESP_send_key(KEY_UP);
				DrvSYS_Delay(100000);
		}
		if(!DrvGPIO_GetBit(E_GPA,12))
		{
			ESP_send_key(KEY_OK);
				DrvSYS_Delay(100000);
		}
		if(!DrvGPIO_GetBit(E_GPA,13))
		{
			ESP_send_key(KEY_CANCEL);
				DrvSYS_Delay(100000);
		}
	}
	
	return 0;
}
