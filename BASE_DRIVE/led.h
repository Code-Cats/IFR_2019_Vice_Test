#ifndef LED_H
#define LED_H
#include "sys.h"

void LED_Init(void);

#define LED1 PCout(0)
#define LED2 PCout(1)

#endif
