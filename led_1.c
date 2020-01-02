/*
 * led_1.c
 *
 *  Created on: 2019��12��26��
 *      Author: Lixing
 */
#include "led_1.h"
#define ADDR 0X1800;


int i;
unsigned int Fram_Data;


void Delay_MCU(uint time)
{
    TA0CCTL0 = CCIE;
    TA0CCR0 = time;
    TA0CTL = TASSEL__ACLK | MC__UP;
    __bis_SR_register(LPM3_bits+GIE);
}
#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer0_A0_ISR (void)
{
    TA0CCTL0 &= ~CCIE;
    __bic_SR_register_on_exit(LPM3_bits + GIE);
}


void Fram_Save(uint data)
{
	uint *ADDR_ram;

	ADDR_ram = (uint*)ADDR;
	*ADDR_ram = data;
}

uint Fram_Read(void)	//���ص���FRAM�����ֵ
{
	uint *ADDR_ram;

	ADDR_ram = (uint*)ADDR;
	return (*ADDR_ram);
}

void WDT_Init()
{
	WDTCTL = WDTPW | WDTHOLD;
	PM5CTL0 &= ~LOCKLPM5;
}


void Port_Init()
{
	P1DIR = BIT0;
	P1OUT &= ~BIT0;
}

void Frequency_low(void)
{
	for(i=10;i>0;i--)
	{
		P1OUT |= BIT0;
		Delay_MCU(10000);

		P1OUT &= ~BIT0;
		Delay_MCU(10000);
	}
	Fram_Data = 1;
}


void Frequency_medium(void)
{
	for(i=10;i>0;i--)
	{
		P1OUT |= BIT0;
		Delay_MCU(5000);

		P1OUT &= ~BIT0;
		Delay_MCU(5000);
	}
	Fram_Data = 2;
}


void Frequency_high(void)  //�����з���ֵ�ĺ�������,�ں����︳ֵ����
{
	for(i=10;i>0;i--)
	{
		P1OUT |= BIT0;
		Delay_MCU(1000);

		P1OUT &= ~BIT0;
		Delay_MCU(1000);
	}
	Fram_Data = 3;
}


/*uint Fram_3(void)   //���з���ֵ�ĺ������͡�����ֵ��main������ע�Ͳ���
{
	uint data;
	for(i=5;i>0;i--)
	{
		P1OUT |= BIT0;
		Delay_MCU(1000);

		P1OUT &= ~BIT0;
		Delay_MCU(1000);
	}
	data = 3;
	return data;

}*/
