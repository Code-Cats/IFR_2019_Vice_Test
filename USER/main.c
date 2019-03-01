#include "stm32f10x.h"
#include "timer.h"
#include "led.h"
#include "pwm.h"
#include "base_deal.h"
#include "switch.h"
#include "valve.h"
#include "delay.h"
#include "usart.h"	

#include "sys.h"

extern SwitchTypeDef Switch;
/************************************************
STM32F103C8T6小绿板
************************************************/


void gpio_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	    //使能PC端口时钟

	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13;			    //LED0-->PA.4 端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO口速度为50MHz
  GPIO_Init(GPIOB, &GPIO_InitStructure);			     //初始化GPIOA.4
  GPIO_SetBits(GPIOB,GPIO_Pin_12);					//PA.4 输出高
	GPIO_ResetBits(GPIOB,GPIO_Pin_13);					//PA.4 输出高
}

void iic_test(void)	//pa8 9 10   pb6 7 8 9
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	    //使能PC端口时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	    //使能PC端口时钟


	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_5 | GPIO_Pin_1 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10;			    //LED0-->PA.4 端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO口速度为50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);			     //初始化GPIOA.4

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;			    //LED0-->PA.4 端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO口速度为50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);			     //初始化GPIOA.4
}





 u32 trigger_count=0;
// u16 pwm_tem=500;
 int main(void)
 {
	delay_init();
	delay_ms(200);
	AFIO->MAPR|=AFIO_MAPR_SWJ_CFG_JTAGDISABLE;	//	禁用JTAG，只启用SWD方式调试,貌似这条语句没有起到该有的作用
//	uart_init(115200);
	LED_Init();
	 
	 gpio_Init();
	 
	 
//	Limit_Init();
//	Valce_Init();
///////  TIM3_PWM_Init(ESC_CYCLE-1,72-1);	//5.11重启//ESC_CYCLE=20000,20ms
//	pwm_init();	//董陪伦的
///////	TIM1_Int_Init(2000-1,72-1);	//	72MHZ频率，分频720(不知道为什么频率异常，故换成了72)，100khz计数频率，计数100次为1ms,计数200次为2ms
//  Switch_Init();
	 iic_test();
	 AFIO->MAPR|=AFIO_MAPR_SWJ_CFG_JTAGDISABLE;	//	禁用JTAG，只启用SWD方式调试,貌似这条语句没有起到该有的作用
  while(1)
	{
//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//调用GPIO重映射函数		
//		PWM_PB4_Set(pwm_tem);
//		PWM_PB5_Set(pwm_tem);
		
		PAout(1)=0;
		
		PAout(0)=0;
		PAout(5)=0;
		
		PAout(8)=0;
		PAout(9)=0;
		PAout(10)=0;
		
		PBout(6)=0;
		PBout(7)=0;
		PBout(8)=0;
		PBout(9)=0;
		
		delay_ms(1);
		
		PAout(1)=1;
		
		PAout(8)=1;
		PAout(9)=1;
		PAout(10)=1;
		
		PBout(6)=1;
		PBout(7)=1;
		PBout(8)=1;
		PBout(9)=1;
		
		delay_ms(1);
		
		if(Switch.Limit.rawdata[0]==1||Switch.Limit.rawdata[1]==1)
		{
			trigger_count++;
			LED1=1;
		}
		else
		{
			LED1=0;
		}
		
		if(Switch.Limit.rawdata[2]==1||Switch.Limit.rawdata[3]==1)
		{
			trigger_count++;
			LED2=1;
		}
		else
		{
			LED2=0;
		}
		
		TIM3->CCR1=1000;
		TIM3->CCR2=1000;
		TIM3->CCR3=1000;
		TIM3->CCR4=1000;
	}
 }
