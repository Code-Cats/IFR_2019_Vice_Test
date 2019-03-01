#include "switch.h"


void Limit_Init(void)
{
	B1_Init();
	B2_Init();
	B3_Init();
	B4_Init();	//��λ
	L1_4_Init();
}

void B1_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 ////////////���Ľӿ���Ĵ˴�  
	 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;			////////////���Ľӿ���Ĵ˴�      
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 	 //��������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOB, &GPIO_InitStructure);			     		////////////���Ľӿ���Ĵ˴�  
  GPIO_SetBits(GPIOB,GPIO_Pin_10 | GPIO_Pin_11);				////////////���Ľӿ���Ĵ˴�  
}

void B2_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);	    
	 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;		
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 	 //��������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOA, &GPIO_InitStructure);			    
  GPIO_SetBits(GPIOA,GPIO_Pin_1);	

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;		
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 	 //��������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOB, &GPIO_InitStructure);			    
  GPIO_SetBits(GPIOB,GPIO_Pin_1);	
}

void B3_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	   
	 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;			   
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 	 //��������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOC, &GPIO_InitStructure);			     
  GPIO_SetBits(GPIOC,GPIO_Pin_10 | GPIO_Pin_11);			
}

void B4_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD, ENABLE);	   
	 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;			    
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 	 //��������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOC, &GPIO_InitStructure);			     
  GPIO_SetBits(GPIOC,GPIO_Pin_12);					//�����
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;			    
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 	 //��������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOD, &GPIO_InitStructure);			     
  GPIO_SetBits(GPIOD,GPIO_Pin_2);					//�����
}

void L1_4_Init(void)
{ 
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	    //ʹ��PC�˿�ʱ��
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//����GPIO��ӳ�亯��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;			   
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 	
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOC, &GPIO_InitStructure);			    
 // GPIO_ResetBits(GPIOC,GPIO_Pin_14 | GPIO_Pin_15);		
}

