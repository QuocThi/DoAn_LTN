#include "uart_ESP8266.h"

char TEXT1[16] = "TX: sending...  ";
char TEXT2[16] = "RX:             ";

volatile uint8_t comRbuf[16] = "";
volatile uint16_t comRbytes = 0;
volatile uint16_t comRhead 	= 0;
volatile uint16_t comRtail 	= 0;

/*---------------------------------------------------------------------------------------------------------*/
/* UART Callback function                                                                           	   */
/*---------------------------------------------------------------------------------------------------------*/
void UART_INT_HANDLE(void)
{
	uint8_t i;
	uint8_t bInChar[1] = {0xFF};

	while(UART0->ISR.RDA_IF==1) 
	{
		DrvUART_Read(UART_PORT0,bInChar,1);	
		if(comRbytes < 8) // check if Buffer is full
		{
			comRbuf[comRbytes] = bInChar[0];
			comRbytes++;
		}
		else if (comRbytes==8)
		{
			comRbytes=0;
			sprintf(TEXT2+4,"%s",comRbuf);
		}			
	}
}

void UART_config()
{	
	STR_UART_T sParam;
	DrvGPIO_InitFunction(E_FUNC_UART0);
/* UART Setting */
    sParam.u32BaudRate 		= 9600;
    sParam.u8cDataBits 		= DRVUART_DATABITS_8;
    sParam.u8cStopBits 		= DRVUART_STOPBITS_1;
    sParam.u8cParity 		= DRVUART_PARITY_NONE;
    sParam.u8cRxTriggerLevel= DRVUART_FIFO_1BYTES;

	/* Set UART Configuration */
 	if(DrvUART_Open(UART_PORT0,&sParam) != E_SUCCESS);  

	DrvUART_EnableInt(UART_PORT0, DRVUART_RDAINT, UART_INT_HANDLE);  	
}

