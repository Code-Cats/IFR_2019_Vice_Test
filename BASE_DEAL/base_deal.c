#include "base_deal.h"
#include "pwm.h"
#include "switch.h"
#include "valve.h"

SwitchTypeDef Switch={0};

void PWM_PB4_Set(u16 pwm_set)	//������ӡ���£�PB4ΪTIM3-CH1
{
	TIM_SetCompare1(TIM3,ESC_CYCLE-pwm_set);
}

void PWM_PB5_Set(u16 pwm_set)
{
	TIM_SetCompare2(TIM3,ESC_CYCLE-pwm_set);
}


//#define VALVE_ISLAND 0
//#define VALVE_BULLET_PROTRACT 1
//#define VALVE_BULLET_CLAMP 2
//#define VALVE_BULLET_STORAGE 3	//��ҩ�ղ���
//#define VALVE_TRAILER 5	//�ϳ�
void Valve_Set(u8 valve_value[])
{
	valve_value[VALVE_ISLAND]=MainControlData.valve[VALVE_ISLAND];
	valve_value[VALVE_BULLET_PROTRACT]=MainControlData.valve[VALVE_BULLET_PROTRACT];
	valve_value[VALVE_BULLET_CLAMP]=MainControlData.valve[VALVE_BULLET_CLAMP];
	valve_value[VALVE_BULLET_STORAGE]=MainControlData.valve[VALVE_BULLET_STORAGE];
	valve_value[VALVE_TRAILER]=MainControlData.valve[VALVE_TRAILER];

	PB12=valve_value[0];
	PB13=valve_value[1];
	PB9=valve_value[2];
	PB8=valve_value[3];
	PC8=valve_value[4];
	PC9=valve_value[5];
}

void Servo_Set(u8 image_cut[])	//ͼ���л�
{
	PWM3_1=image_cut[0]*ESC_CYCLE;
	PWM3_2=image_cut[1]*ESC_CYCLE;
//	TIM_SetCompare1(TIM3,servo_value[0]);
//	TIM_SetCompare2(TIM3,servo_value[1]);
//	TIM_SetCompare3(TIM3,servo_value[2]);
}

void Switch_Scanf(void)
{
	Switch.Infrare.rawdata[0]=PA1;
	Switch.Infrare.rawdata[1]=PB1;
	Switch.Infrare.rawdata[2]=PB11;
	Switch.Infrare.rawdata[3]=PB10;
	Switch.Infrare.rawdata[4]=PC11;	//[4]Ϊ���µ����ٱ�����[5]Ϊ�ϳ����
	Switch.Infrare.rawdata[5]=PC10;	//[4]Ϊ���µ����ٱ�����[5]Ϊ�ϳ����
	
	Switch.Infrare.rawdata[6]=PC12;	//[6]Ϊ���λ	0Ϊ����
	Switch.Infrare.rawdata[7]=PD2;	//[7]Ϊ�Ҷ�λ
	
	Switch.Limit.rawdata[0]=PC4;
	Switch.Limit.rawdata[1]=PC5;
	Switch.Limit.rawdata[2]=PC6;
	Switch.Limit.rawdata[3]=PC7;
}

void Switch_Filter(void)
{
	u16 Infrare_sum[INFRARE_NUMS]={0};
//	u16 Limit_sum[4]={0};
	u8 i_count=0;
	u8 j_count=0;
	
	for(i_count=0;i_count<INFRARE_NUMS;i_count++)
	{
		Infrare_sum[i_count]=0;	//�����������һ��
//		Limit_sum[i_count]=0;	//�������for���һ��
		
		Switch.Infrare.lastdata[i_count][Switch.Infrare.count]=Switch.Infrare.rawdata[i_count];	//��ǰ���������¼����
//		Switch.Limit.lastdata[i_count][Switch.Limit.count]=Switch.Limit.rawdata[i_count];	//��ǰ���������¼����
	}
		
	for(i_count=0;i_count<INFRARE_NUMS;i_count++)
	{
		for(j_count=0;j_count<FILTER_ORDER;j_count++)
		{
			Infrare_sum[i_count]+=Switch.Infrare.lastdata[i_count][j_count];
//			Limit_sum[i_count]+=Switch.Limit.lastdata[i_count][j_count];
		}
	}
	
	for(i_count=0;i_count<INFRARE_NUMS;i_count++)
	{
		Switch.Infrare.dealdata[i_count]=Infrare_sum[i_count]>(FILTER_ORDER/2)?1:0;
//		Switch.Limit.dealdata[i_count]=Limit_sum[i_count]>(FILTER_ORDER/2)?1:0;
	}

	
	Switch.Infrare.count=Switch.Infrare.count<(FILTER_ORDER-1)?(Switch.Infrare.count+1):0;
//	Switch.Limit.count=Switch.Limit.count<(FILTER_ORDER-1)?(Switch.Limit.count+1):0;
	
}


MainBoardSendTypeDef SendData=MAINBOARD_SENDDATA_DEFAULT;
//��������崮�ڷ��ͺ���	//2msִ��һ�Σ�10ms����һ�ν����14400�Ĳ����ʣ�һ���ֽ���ഫ��11λ��11/14400=0.76ms
void MainBoard_SendData(void)
{
	if(USART_GetFlagStatus(USART1,USART_FLAG_TC)== SET)	//�����һ֡�������
	{
		if(SendData.statu==1)
		{
			SendData.data[0]=0x5A;	//��ֹ֡ͷ֡β���ƻ�
			SendData.data[4]=0xA5;	//��ֹ֡ͷ֡β���ƻ�
			USART_SendData(USART1,SendData.data[SendData.count]);
			SendData.count++;
			if(SendData.count>4)
			{
				SendData.statu=0;
				SendData.count=0;
			}
		}
	}
	
}


ReceiveDataTypeDef ReceiveData={0};
u16 t_usart1_count=0;
void Data_Receive(u8 data)	//�����崫���������ݽ�����������ͨ�ã�
{
	t_usart1_count++;
	if(data==0x5A&&ReceiveData.headOK_state==0)
	{
		ReceiveData.valid_state=0;	//���ݽ����ڼ䲻�������ݽ���
		ReceiveData.headOK_state=1;	
		ReceiveData.count=0;	//����count
	}
	
	if(ReceiveData.headOK_state==1)	//֡ͷ���ҵ�
	{
		ReceiveData.databuffer[ReceiveData.count]=data;
		ReceiveData.count++;
		if((data==0xA5&&ReceiveData.count!=5)||(ReceiveData.count>5))	//ʧЧ
		{
			ReceiveData.valid_state=0;
			ReceiveData.headOK_state=0;
			ReceiveData.count=0;	//����count
		}
		else if(data==0xA5&&ReceiveData.count==5)
		{
			ReceiveData.valid_state=1;
			ReceiveData.headOK_state=0;
			ReceiveData.count=0;	//����count
		}
	}
	
	MainControlData_Deal(ReceiveData.databuffer);
	//////////////////////////////��������ݽ�������-->����Ϊ��ʵ����
	
}


MainControlDataTypeDef MainControlData={0};

void MainControlData_Deal(u8 *pData)	//����֡ͷ�ĵ�һ֡Ϊ����֡��ǰ4λΪVALVE��5-6λΪ����λ��7-8Ϊ���λ
{
	for(int i=0;i<6;i++)
	{
		MainControlData.valve[i]=*(pData+1)>>(7-i)&0x01;
	}
	
	for(int i=0;i<2;i++)
	{
		MainControlData.servo[i]=*(pData+1)>>(1-i)&0x01;
	}
	
	for(int i=0;i<2;i++)
	{
		MainControlData.image_cut[i]=*(pData+2)>>(7-i)&0x01;		//[4]Ϊ���µ����ٱ�����[5]Ϊ�ϳ����
	}
}

