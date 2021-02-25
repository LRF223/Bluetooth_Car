#include "motor.h"

void MOTOR_Init(void){ //MOTOR�ӿڳ�ʼ��
	GPIO_InitTypeDef  GPIO_InitStructure; 	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC,ENABLE);       
    GPIO_InitStructure.GPIO_Pin = Motor_L1 | Motor_L2 | Motor_R1 | Motor_R2; //ѡ��˿ںţ�0~15��all��                        
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //ѡ��IO�ӿڹ�����ʽ       
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //����IO�ӿ��ٶȣ�2/10/50MHz��    
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
ѡ��IO�ӿڹ�����ʽ��
GPIO_Mode_AIN ģ������
GPIO_Mode_IN_FLOATING ��������
GPIO_Mode_IPD ��������
GPIO_Mode_IPU ��������
GPIO_Mode_Out_PP �������
GPIO_Mode_Out_OD ��©���
GPIO_Mode_AF_PP �����������
GPIO_Mode_AF_OD ���ÿ�©���
*/
