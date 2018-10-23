#include "NUC_config.h"

volatile uint8_t Receive_buf[16] = "";
volatile uint16_t readCount = 0;
volatile vibration_handler_t vibra = NULL;

/*---------------------------------------------------------------------------------------------------------*/
/* UART Callback function                                                                           	   */
/*---------------------------------------------------------------------------------------------------------*/
void UART_INT_HANDLE(uint32_t userData)
{
	//uint8_t i;
	uint8_t bInChar[1] = {0xFF};

	while(UART0->ISR.RDA_IF==1) 
	{
		DrvUART_Read(UART_PORT0,bInChar,1);	
		if(readCount < 8) // check if Buffer is full
		{
			Receive_buf[readCount] = bInChar[0];
			readCount++;
		}
		else if (readCount==8)
		{
			readCount=0;
			//sprintf(TEXT2+4,"%s",Receive_buf);
		}			
	}
	
	if(Receive_buf[0] == VIBRATION)
	{
		vibra();
	}
	
}

void VIBRATION_config()
{
	
}

void ESP_config()
{	
	STR_UART_T sParam;
	DrvGPIO_InitFunction(E_FUNC_UART0);
/* UART Setting */
#ifdef  BAUD9600
    sParam.u32BaudRate 		= 9600;
#endif
	
#ifdef  BAUD115
    sParam.u32BaudRate 		= 115200;
#endif
	
    sParam.u8cDataBits 		= DRVUART_DATABITS_8;
    sParam.u8cStopBits 		= DRVUART_STOPBITS_1;
    sParam.u8cParity 		= DRVUART_PARITY_NONE;
    sParam.u8cRxTriggerLevel= DRVUART_FIFO_1BYTES;

	/* Set UART Configuration */
 	if(DrvUART_Open(UART_PORT0,&sParam) != E_SUCCESS);  

	DrvUART_EnableInt(UART_PORT0, DRVUART_RDAINT,UART_INT_HANDLE);  	
}

void ESP_send_key(uint8_t Keys)
{
	DrvUART_Write(UART_PORT0,&Keys,1);
}
void ESP_set_vibration_handler(vibration_handler_t handler)
{
	vibra = handler;
}

