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

u8 Valve_Value[6]={0};	//��ŷ�����
u16 Servo_Value[3]={0};
void Control_Task(void)
{
	Switch_Scanf();
	Switch_Filter(); 
	if(SendData.statu==0)
	{
		SendData.data[1]=Switch.Limit.rawdata[0]<<7|Switch.Limit.rawdata[1]<<6|Switch.Limit.rawdata[2]<<5|Switch.Limit.rawdata[3]<<4|Switch.Infrare.dealdata[0]<<3|Switch.Infrare.dealdata[1]<<2|Switch.Infrare.dealdata[2]<<1|Switch.Infrare.dealdata[3];
		SendData.data[2]=Switch.Infrare.dealdata[4]<<7|Switch.Infrare.dealdata[5]<<6|Switch.Infrare.dealdata[6]<<5|Switch.Infrare.dealdata[7]<<4;	//[4]Ϊ���µ����ٱ�����[5]Ϊ�ϳ����	//[6]Ϊ���λ [7]Ϊ�Ҷ�λ
		SendData.statu=1;
	}
	
	MainBoard_SendData();
	Valve_Set(Valve_Value);
	Servo_Set(MainControlData.image_cut);
}


