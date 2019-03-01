#ifndef __SWITCH_H
#define __SWITCH_H
#include "sys.h"

void Limit_Init(void);
void B1_Init(void);
void B2_Init(void);
void B3_Init(void);
void B4_Init(void);
void L1_4_Init(void);


#define PB10 PBin(10)
#define PB11 PBin(11)
#define PA1 PAin(1)
#define PB1 PBin(1)
#define PC10 PCin(10)
#define PC11 PCin(11)
#define PC12 PCin(12)
#define PD2 PDin(2)

#define PC4 PCin(4)
#define PC5 PCin(5)
#define PC6 PCin(6)
#define PC7 PCin(7)

#define S1 PA15

#endif
