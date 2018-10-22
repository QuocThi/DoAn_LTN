#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvUART.h"

#include "Driver\DrvGPIO.h"
#include "Driver\DrvSYS.h"
extern char text[1];

extern volatile uint8_t comRbuf[16];
extern volatile uint16_t comRbytes;
extern volatile uint16_t comRhead;
extern volatile uint16_t comRtail;

extern char TEXT1[16];
extern char TEXT2[16];

void UART_config();
void UART_send_byte(char byte);
void UART_send_string(char str);
