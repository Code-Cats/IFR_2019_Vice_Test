#ifndef BASE_DEAL_H
#define BASE_DEAL_H

#include "sys.h"

#define VALVE_ISLAND 0		//电磁阀控制位定义
#define VALVE_BULLET_PROTRACT 1
#define VALVE_BULLET_CLAMP 2
#define VALVE_BULLET_STORAGE 3	//弹药舱补弹
#define VALVE_TRAILER 5	//拖车

void PWM_PB4_Set(u16 pwm_set);
void PWM_PB5_Set(u16 pwm_set);
void Valve_Set(u8 valve_value[]);
void Servo_Set(u8 image_cut[]);	//图传切换
void MainBoard_SendData(void);
void Switch_Scanf(void);
void Switch_Filter(void);
void Data_Receive(u8 data);	//从主板传过来的数据解析（主副板通用）
void MainControlData_Deal(u8 *pData);	//除了帧头的第一帧为控制帧，前4位为VALVE，5-6位为保留位；7-8为舵机位

#define FILTER_ORDER 16
#define INFRARE_NUMS 8	//红外传感器数量//7.7新增两个自动对位
typedef struct
{
	struct
	{
		u8 rawdata[INFRARE_NUMS];	//新增2个红外上下岛保护与拖车	7.7新增两个红外对位	6左 7右
		u8 count;
		u8 lastdata[INFRARE_NUMS][FILTER_ORDER];
		u8 dealdata[INFRARE_NUMS];
	}Infrare;
	struct
	{
		u8 rawdata[4];
		u8 count;
		u8 lastdata[4][FILTER_ORDER];
		u8 dealdata[4];
	}Limit;
}SwitchTypeDef;


typedef struct
{
	u8 statu;
	u8 data[5];
	u8 count;
}MainBoardSendTypeDef;

#define MAINBOARD_SENDDATA_DEFAULT \
{\
	0,\
	{0x5A,0,0,0,0xA5},\
	0,\
}\

typedef struct
{
	u8 headOK_state;
	u8 valid_state;	//数据帧有效标志位
	u8 databuffer[5];
	u8 count;
}ReceiveDataTypeDef;

typedef struct
{
	u8 valve[6];
	u8 servo[2];	//暂定舵机位
	u8 image_cut[2];
}MainControlDataTypeDef;

extern SwitchTypeDef Switch;
extern MainBoardSendTypeDef SendData;
extern ReceiveDataTypeDef ReceiveData;
extern MainControlDataTypeDef MainControlData;


#endif

