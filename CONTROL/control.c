#include "control.h"
#include "led.h"
#include "timer.h"
#include "base_deal.h"
#include "usart.h"	


void LED_Runing(void)
{
	if(time_2ms_count%250==0)
	{
//		LED=!LED;
	}
}

u8 Valve_Value[6]={0};	//电磁阀控制
u16 Servo_Value[3]={0};
void Control_Task(void)
{
	Switch_Scanf();
	Switch_Filter(); 
	if(SendData.statu==0)
	{
		SendData.data[1]=Switch.Limit.rawdata[0]<<7|Switch.Limit.rawdata[1]<<6|Switch.Limit.rawdata[2]<<5|Switch.Limit.rawdata[3]<<4|Switch.Infrare.dealdata[0]<<3|Switch.Infrare.dealdata[1]<<2|Switch.Infrare.dealdata[2]<<1|Switch.Infrare.dealdata[3];
		SendData.data[2]=Switch.Infrare.dealdata[4]<<7|Switch.Infrare.dealdata[5]<<6|Switch.Infrare.dealdata[6]<<5|Switch.Infrare.dealdata[7]<<4;	//[4]为上下岛加速保护，[5]为拖车检测	//[6]为左对位 [7]为右对位
		SendData.statu=1;
	}
	
	MainBoard_SendData();
	Valve_Set(Valve_Value);
	Servo_Set(MainControlData.image_cut);
}


