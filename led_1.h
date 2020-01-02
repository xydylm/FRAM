/*
 * led_1.h
 *
 *  Created on: 2019Äê12ÔÂ26ÈÕ
 *      Author: Lixing
 */

#ifndef LED_1_H_
#define LED_1_H_

#include <msp430.h>

void Delay_MCU(uint time);
void Fram_Save(uint data);
void WDT_Init();
void Port_Init();
void Frequency_low(void);
void Frequency_medium(void);
void Frequency_high(void);
uint Fram_Read(void);


uint Fram_3(void);


#endif /* LED_1_H_ */
