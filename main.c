#include <msp430.h> 
#include "led_1.h"

#define ADDR 0X1800;

extern unsigned int Fram_Data;
unsigned int data;

int main(void)
{
	WDT_Init();
	Port_Init();
//	uint dddd;
	data = Fram_Read();

#if 	1
/*（测试代码）
	while(1)
	{
		Frequency_low();
		Fram_Save(Fram_Data);
		Delay_MCU(10000);

		Frequency_medium();
		Fram_Save(Fram_Data);
		Delay_MCU(10000);

		Frequency_high();
		Fram_Save(Fram_Data);
		Delay_MCU(10000);
	}
*/
	while(1)
	{
		if (data == 1)
		{
			Frequency_medium();
			Fram_Save(Fram_Data);
			data = Fram_Read();
			Delay_MCU(10000);
		}

		else if (data == 2)
		{
			Frequency_high();
			Fram_Save(Fram_Data);
			data = Fram_Read();
			Delay_MCU(10000);
		}

		else if (data == 3)
		{
			Frequency_low();
			Fram_Save(Fram_Data);
			data = Fram_Read();
			Delay_MCU(10000);
		}
	}

#elif	1

	while(1)
	{
		dddd = Fram_3();
		Fram_Save(dddd);
		Delay_MCU(10000);	//带返回值部分的main函数，主要在于返回的值直接赋值给
	}

#endif

	return 0;
}
