#include "stm32f10x.h" 
#include "sys.h"
#include "delay.h"
#include "motor.h"
#include "usart.h"
#include "pwm.h"

int main (void){
	u8 a;
	int c = 150;

	RCC_Configuration(); 		//ʱ������
	MOTOR_Init();						//LED��ʼ��
	USART2_Init(9600); 			//���ڳ�ʼ���������ǲ����ʣ�
	
	TIM3_PWM_Init(7200-1,0); 						//PWMʱ��Ƶ��=72000/(7200)*(1) = 10kHZ 

		TIM_SetCompare3(TIM3,5000);        //�ı�Ƚ�ֵTIM3->CCR2�ﵽ����ռ�ձȵ�Ч��
		TIM_SetCompare4(TIM3,5000);	
	
	while(1){				
		if(USART_GetFlagStatus(USART2,USART_FLAG_RXNE) != RESET){	 			//��ѯ��ʽ���գ���ѯ���ڴ������־λ
			a =USART_ReceiveData(USART2);																	//��ȡ���յ�������
			switch (a){
				case '0':
					Go_Forward();
					delay_ms(c);
					if(USART_GetFlagStatus(USART2,USART_FLAG_RXNE) == RESET)	//��⵽�����ɿ���ͣ��
					{	
						Stop();							
					}			
					printf("%c:Go_Forward ",a); 															//���յ������ݷ���
					break;
				
				case '1':
					Draw_Back();
					delay_ms(c);
					if(USART_GetFlagStatus(USART2,USART_FLAG_RXNE) == RESET)
					{	
						Stop();							
					}			
					printf("%c:Draw_Back",a); 
					break;
				
				case '2':
					Turn_left();
					printf("%c:Turn_left",a); 	
					delay_ms(c);				
					if(USART_GetFlagStatus(USART2,USART_FLAG_RXNE) == RESET)
					{	
						Stop();							
					}			
					break;
				
				case '3':
					Turn_right();
					delay_ms(c);
					if(USART_GetFlagStatus(USART2,USART_FLAG_RXNE) == RESET)
					{	
						Stop();							
					}			
					printf("%c:Turn_right ",a); 
					break;
				
					case '4':
					Stop();
					printf("%c:Stop ",a); 
					break;

/*********************PWM����***************************/				
					case '5':			
					TIM_SetCompare3(TIM3,7200);        
					TIM_SetCompare4(TIM3,7200);
					printf("%c:fast speed ",a); 
					break;
					
					case '6':
					TIM_SetCompare3(TIM3,6000);        
					TIM_SetCompare4(TIM3,6000);
					printf("%c:medium speed ",a); 			
					break;

					case '7':			
					TIM_SetCompare3(TIM3,5000);        
					TIM_SetCompare4(TIM3,5000);
					printf("%c:slow speed ",a); 
					break;
					
				default:
					break;
			}		  
		}

	
	}
}
