#include "motor.h"

void MOTOR_Init(void){ //MOTOR接口初始化
	GPIO_InitTypeDef  GPIO_InitStructure; 	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC,ENABLE);       
    GPIO_InitStructure.GPIO_Pin = Motor_L1 | Motor_L2 | Motor_R1 | Motor_R2; //选择端口号（0~15或all）                        
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //选择IO接口工作方式       
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //设置IO接口速度（2/10/50MHz）    
	GPIO_Init(MOTORPORT, &GPIO_InitStructure);			
}
void Go_Forward(void){
		GPIO_WriteBit(MOTORPORT,Motor_L1,(BitAction)(0)); 
		GPIO_WriteBit(MOTORPORT,Motor_L2,(BitAction)(1)); 
		GPIO_WriteBit(MOTORPORT,Motor_R1,(BitAction)(1)); 
		GPIO_WriteBit(MOTORPORT,Motor_R2,(BitAction)(0)); 
		}

void Draw_Back(void){
		GPIO_WriteBit(MOTORPORT,Motor_L1,(BitAction)(1)); 
		GPIO_WriteBit(MOTORPORT,Motor_L2,(BitAction)(0)); 
		GPIO_WriteBit(MOTORPORT,Motor_R1,(BitAction)(0)); 
		GPIO_WriteBit(MOTORPORT,Motor_R2,(BitAction)(1)); 
		}
		
void Turn_left(void){
		GPIO_WriteBit(MOTORPORT,Motor_L1,(BitAction)(1)); 
		GPIO_WriteBit(MOTORPORT,Motor_L2,(BitAction)(0)); 
		GPIO_WriteBit(MOTORPORT,Motor_R1,(BitAction)(1)); 
		GPIO_WriteBit(MOTORPORT,Motor_R2,(BitAction)(0)); 
		}

void Turn_right(void){
		GPIO_WriteBit(MOTORPORT,Motor_L1,(BitAction)(0)); 
		GPIO_WriteBit(MOTORPORT,Motor_L2,(BitAction)(1)); 
		GPIO_WriteBit(MOTORPORT,Motor_R1,(BitAction)(0)); 
		GPIO_WriteBit(MOTORPORT,Motor_R2,(BitAction)(1)); 
		}

void Stop(void){
		GPIO_WriteBit(MOTORPORT,Motor_L1,(BitAction)(0)); 
		GPIO_WriteBit(MOTORPORT,Motor_L2,(BitAction)(0)); 
		GPIO_WriteBit(MOTORPORT,Motor_R1,(BitAction)(0)); 
		GPIO_WriteBit(MOTORPORT,Motor_R2,(BitAction)(0)); 
		}		
		
/*
选择IO接口工作方式：
GPIO_Mode_AIN 模拟输入
GPIO_Mode_IN_FLOATING 浮空输入
GPIO_Mode_IPD 下拉输入
GPIO_Mode_IPU 上拉输入
GPIO_Mode_Out_PP 推挽输出
GPIO_Mode_Out_OD 开漏输出
GPIO_Mode_AF_PP 复用推挽输出
GPIO_Mode_AF_OD 复用开漏输出
*/
