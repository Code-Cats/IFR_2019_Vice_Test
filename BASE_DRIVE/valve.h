#ifndef __VALVE_H_
#define __VALVE_H_

#include "sys.h"

void Valce_Init(void);//��ŷ���ʼ��

void PB12_Init(void);	//P1�ӿ�
void PB13_Init(void);	//P2�ӿ�
void PB9_Init(void);	//P3�ӿ�
void PB8_Init(void);	//P4�ӿ�
void PC8_Init(void);	//P5�ӿ�
void PC9_Init(void);	//P6�ӿ�


#define PB12 PBout(12)
#define PB13 PBout(13)
#define PB9 PBout(9)
#define PB8 PBout(8)
#define PC8 PCout(8)
#define PC9 PCout(9)

#endif
