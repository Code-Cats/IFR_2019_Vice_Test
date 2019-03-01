#include "valve.h"


void Valce_Init(void)//��ŷ���ʼ��
{
	PB12_Init();
	PB13_Init();
	PB9_Init();
	PB8_Init();
	PC8_Init();
	PC9_Init();
}


void PB12_Init(void)	//P1�ӿ�
{
	GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	   
	 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;			   
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOB, &GPIO_InitStructure);			     
  GPIO_ResetBits(GPIOB,GPIO_Pin_12);	
}

void PB13_Init(void)	//P2�ӿ�
{
	GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	   
	 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;			   
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOB, &GPIO_InitStructure);			     
  GPIO_ResetBits(GPIOB,GPIO_Pin_13);	
}

void PB9_Init(void)	//P3�ӿ�
{
	GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	   
	 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;			   
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOB, &GPIO_InitStructure);			     
  GPIO_ResetBits(GPIOB,GPIO_Pin_9);	
}

void PB8_Init(void)	//P4�ӿ�
{
	GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	   
	 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;			   
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOB, &GPIO_InitStructure);			     
  GPIO_ResetBits(GPIOB,GPIO_Pin_8);	
}

void PC8_Init(void)	//P5�ӿ�
{
	GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	   
	 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;			   
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOC, &GPIO_InitStructure);			     
  GPIO_ResetBits(GPIOC,GPIO_Pin_8);	
}

void PC9_Init(void)	//P6�ӿ�
{
	GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	   
	 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;			   
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOC, &GPIO_InitStructure);			     
  GPIO_ResetBits(GPIOC,GPIO_Pin_9);	
}
