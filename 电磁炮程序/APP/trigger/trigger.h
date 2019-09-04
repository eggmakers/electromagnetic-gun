#ifndef _TRIGGER_H
#define _TRIGGER_H

#include "system.h"
#include "SysTick.h"

#define charge TIM_SetCompare2(TIM3,50)
#define charge_ready TIM_SetCompare2(TIM3,0)

void Trigger_Init(void);
void Trigger(void);

#endif
