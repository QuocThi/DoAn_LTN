#include "NUC_config.h"

void vibration()
{
	// Rung
}

int main()
{
	ESP_config();
	ESP_set_vibration_handler(vibration);
	while(1)
	{
		//if()
	}
	
	return 0;
}
