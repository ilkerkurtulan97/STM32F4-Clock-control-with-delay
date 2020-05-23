#include "stm32f4xx.h"                  // Device header

int main()
{
	
	GPIO_InitTypeDef					GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef		TIM_TimeBaseStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;
	GPIO_Init(GPIOD,&GPIO_InitStructure);
	
	RCC_APB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
	
	TIM_TimeBaseStructure.TIM_Prescaler					=8399;
	TIM_TimeBaseStructure.TIM_CounterMode				=TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period						=9999;
	TIM_TimeBaseStructure.TIM_ClockDivision			=TIM_CKD_DIV4;
	TIM_TimeBaseStructure.TIM_RepetitionCounter	=0;
	
	
	
	
	while(1)
	{
		if(TIM_GetCounter(TIM2)<2500)
		{
			GPIO_SetBits(GPIOD,GPIO_Pin_12);
			GPIO_ResetBits(GPIOD,GPIO_Pin_13);
			GPIO_ResetBits(GPIOD,GPIO_Pin_14);
			GPIO_ResetBits(GPIOD,GPIO_Pin_15);
		}
		
		if((TIM_GetCounter(TIM2)>=2500) && (TIM_GetCounter(TIM2))<5000)
		{
			GPIO_ResetBits(GPIOD,GPIO_Pin_12);
			GPIO_SetBits(GPIOD,GPIO_Pin_13);
			GPIO_ResetBits(GPIOD,GPIO_Pin_14);
			GPIO_ResetBits(GPIOD,GPIO_Pin_15);
		}
		
		if((TIM_GetCounter(TIM2)>=5000) && (TIM_GetCounter(TIM2))<7500)
		{
			GPIO_ResetBits(GPIOD,GPIO_Pin_12);
			GPIO_ResetBits(GPIOD,GPIO_Pin_13);
			GPIO_SetBits(GPIOD,GPIO_Pin_14);
			GPIO_ResetBits(GPIOD,GPIO_Pin_15);
			
		}
		
		if((TIM_GetCounter(TIM2)>=7500) && (TIM_GetCounter(TIM2))<10000)
		{
			GPIO_ResetBits(GPIOD,GPIO_Pin_12);
			GPIO_ResetBits(GPIOD,GPIO_Pin_13);
			GPIO_ResetBits(GPIOD,GPIO_Pin_14);
			GPIO_SetBits(GPIOD,GPIO_Pin_15);
			
			
		}
		
		
		
		
	
	}
	

}
