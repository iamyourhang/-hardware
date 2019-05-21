#ifndef _ultrasonic_H
#define _ultrasonic_H
/*******************************************/
/**************
    超声波测量源程序
	  接口TRig （GPIOB,GPIO_Pin_5）
	  接口ECHO (GPIOB,GPIO_Pin_6)
	          *****************************/
/******************************************/


//------------------------------------------------------------移植修改区-----------------------------------------------------------------------
#include "sys.h"

#define ULTRA_PORT	GPIOB
#define ULTRA_CLK       RCC_APB2Periph_GPIOB
#define ULTRA_TRIG			GPIO_Pin_5
#define ULTRA_ECHO			GPIO_Pin_6

#define TRIG_Send  PBout(5)
#define ECHO_Reci  PBin(6)

//---------------------------------------------------------------------------------------------------------------------------------------------
void Ultran_Init(void);
void Ultra_Ranging(float *p);




#endif

