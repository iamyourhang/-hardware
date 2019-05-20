//#include "motor.h"  
//#include "stm32f10x.h"  
//#include "stm32f10x_rcc.h"  
//#include "delay.h"       
//  
//void Motor_12_Config(void)   
//{  
//    GPIO_InitTypeDef GPIO_InitStructure;   //定义GPIO_InitTypeDef结构体
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  //使能引脚始时钟  
//      
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7; //定义IN引脚  
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //推挽输出  
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //输出频率 
//    GPIO_Init(GPIOB, &GPIO_InitStructure);  //初始化GPIOA输出
//      
//    GPIO_ResetBits(GPIOB,GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7); //所有引脚拉低
//}  
//  
//void Motor_1_STOP()  
//{  
//    IN1(High);  
//    IN2(High);  
//	
//}  
//  
//void Motor_1_PRun()  
//{  
//    IN1(Low);  
//    IN2(High);  

//}  
//  
//void Motor_1_NRun()  
//{  
//    IN1(High);  
//    IN2(Low);  
//	
//}  
//  
//void Motor_2_STOP()  
//{  
//    IN3(High);  
//    IN4(High);  
//}  
//  
//void Motor_2_PRun()  
//{  
//    IN3(Low);  
//    IN4(High);  
//  
//}  
//void Motor_2_NRun()  
//{  
//    IN3(High);  
//    IN4(Low);  
//	
//}  


#include "sys.h"
#include "delay.h"
#include "motor.h"
/*
	L298N的IN1,IN2,IN3,IN4分别接PB.6,PB.7,PB.8,PB.9
	OUT1接左边电机的正极,OUT2接左边电机的负极
	OUT3接右边电机的正极,OUT4接右边电机的负极
*/
void L298N_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9; 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	
  GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void run(void){//左右两轮前进
	GPIO_SetBits(L298N_GPIO_PORT,L298N_PIN_L1);
	GPIO_ResetBits(L298N_GPIO_PORT,L298N_PIN_L2);
	GPIO_SetBits(L298N_GPIO_PORT,L298N_PIN_R1);
	GPIO_ResetBits(L298N_GPIO_PORT,L298N_PIN_R2);
}

void stop(void){//左右两轮后退
	GPIO_ResetBits(L298N_GPIO_PORT,L298N_PIN_L1);
	GPIO_ResetBits(L298N_GPIO_PORT,L298N_PIN_L2);
	GPIO_ResetBits(L298N_GPIO_PORT,L298N_PIN_R1);
	GPIO_ResetBits(L298N_GPIO_PORT,L298N_PIN_R2);
}
void turn_left(void){//左轮后退，右轮前进
	GPIO_ResetBits(L298N_GPIO_PORT,L298N_PIN_L1);
	GPIO_SetBits(L298N_GPIO_PORT,L298N_PIN_L2);
	GPIO_SetBits(L298N_GPIO_PORT,L298N_PIN_R1);
	GPIO_ResetBits(L298N_GPIO_PORT,L298N_PIN_R2);
}
void turn_right(void){//左轮前进，右轮后退
	GPIO_SetBits(L298N_GPIO_PORT,L298N_PIN_L1);
	GPIO_ResetBits(L298N_GPIO_PORT,L298N_PIN_L2);
	GPIO_ResetBits(L298N_GPIO_PORT,L298N_PIN_R1);
	GPIO_SetBits(L298N_GPIO_PORT,L298N_PIN_R2);
}
void back(void){//左右两轮后退
	GPIO_ResetBits(L298N_GPIO_PORT,L298N_PIN_L1);
	GPIO_SetBits(L298N_GPIO_PORT,L298N_PIN_L2);
	GPIO_ResetBits(L298N_GPIO_PORT,L298N_PIN_R1);
	GPIO_SetBits(L298N_GPIO_PORT,L298N_PIN_R2);
}


