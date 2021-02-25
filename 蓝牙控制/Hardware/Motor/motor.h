#ifndef __MOTOR_H
#define __MOTOR_H	 
#include "sys.h"

//#define LED1 PBout(0)// PB0
//#define LED2 PBout(1)// PB1	
#define MOTORPORT	GPIOB	//定义IO接口
#define Motor_R1	GPIO_Pin_5	//定义IO接口
#define Motor_R2	GPIO_Pin_6	//定义IO接口
#define Motor_L1	GPIO_Pin_7	//定义IO接口
#define Motor_L2	GPIO_Pin_8	//定义IO接口


void MOTOR_Init(void);//初始化
void Go_Forward(void);
void Draw_Back(void);
void Turn_left(void);
void Turn_right(void);
void Stop(void);		 				    
#endif
