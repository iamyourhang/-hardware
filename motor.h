//#ifndef __MOTOR_H  
//#define __MOTOR_H  
//  
//  
//#include "stm32f10x.h"  
//#include "stm32f10x_gpio.h"  
//  
//#define High    1  
//#define Low     0  
//  
//#define IN1(a) if (a)  \
//    GPIO_SetBits(GPIOB,GPIO_Pin_4);\
//else  \
//    GPIO_ResetBits(GPIOB,GPIO_Pin_4)  
//  
//#define IN2(a) if (a)  \
//    GPIO_SetBits(GPIOB,GPIO_Pin_5);\
//else  \
//    GPIO_ResetBits(GPIOB,GPIO_Pin_5)  
//  
//#define IN3(a) if (a)  \
//    GPIO_SetBits(GPIOB,GPIO_Pin_6);\
//else  \
//    GPIO_ResetBits(GPIOB,GPIO_Pin_6)  
//  
//#define IN4(a) if (a)  \
//    GPIO_SetBits(GPIOB,GPIO_Pin_7);\
//else  \
//    GPIO_ResetBits(GPIOB,GPIO_Pin_7)  
//  
//void Motor_12_Config(void);  
//  
//void Motor_1_STOP(void);  
//void Motor_1_PRun(void);  
//void Motor_1_NRun(void);  
//  
//void Motor_2_STOP(void);  
//void Motor_2_PRun(void);  
//void Motor_2_NRun(void);  
//  
//#endif  

#include "sys.h"
#include "delay.h"

#ifndef MOTOR_H
#define MOTOR_H
#define L298N_GPIO_PORT GPIOB
#define L298N_PIN_L1 GPIO_Pin_6
#define L298N_PIN_L2 GPIO_Pin_7
#define L298N_PIN_R1 GPIO_Pin_8
#define L298N_PIN_R2 GPIO_Pin_9
void L298N_Init(void);
void run(void);
void back(void);
void stop(void);
void turn_left(void);
void turn_right(void);
#endif

