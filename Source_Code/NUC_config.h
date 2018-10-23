#ifndef __NUC_CONFIG_H__
#define __NUC_CONFIG_H__

#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvUART.h"

#include "Driver\DrvGPIO.h"
#include "Driver\DrvSYS.h"

#define BAUD9600	9600
//#define BAUD115	11500


typedef void (*vibration_handler_t) (void); 

#define KEY_UP			0x01
#define KEY_DOWN		0x02
#define KEY_LEFT		0x04
#define KEY_RIGHT		0x08
#define KEY_CANCEL	0x10
#define KEY_HIT			0x20
#define VIBRATION		0x40

void ESP_config();
void VIBRATION_config();
void ESP_send_key(uint8_t Keys);
void ESP_set_vibration_handler(vibration_handler_t handler);

#endif /* __NUC_CONFIG_H__ */


