#include "stm32f10x.h" //STM32ͷ�ļ�
#include "sys.h"
#include "delay.h"
#include "motor.h"
#include "key.h"
#include "usart.h"

#include "pwm.h"

int main (void){//������
	u8 a;
	//��ʼ������
	RCC_Configuration(); //ʱ������
	MOTOR_Init();//LED��ʼ��
	KEY_Init();//������ʼ��
	USART2_Init(9600); //���ڳ�ʼ���������ǲ����ʣ�
	
	TIM3_PWM_Init(59999,23);
	//����Ƶ��Ϊ50Hz����ʽΪ�����ʱ��Tout����λ�룩=(arr+1)(psc+1)/Tclk 20MS = (59999+1)*(23+1)/72000000
  //TclkΪͨ�ö�ʱ����ʱ�ӣ����APB1û�з�Ƶ�����Ϊϵͳʱ�ӣ�72MHZ
  //PWMʱ��Ƶ��=72000000/(59999+1)*(23+1) = 50HZ (20ms),�����Զ�װ��ֵ60000,Ԥ��Ƶϵ��24

		TIM_SetCompare3(TIM3,45000);        //�ı�Ƚ�ֵTIM3->CCR2�ﵽ����ռ�ձȵ�Ч��
		TIM_SetCompare4(TIM3,45000);	
	
	//��ѭ��
	while(1){
		int c = 150;
		//��ѯ��ʽ����
		if(USART_GetFlagStatus(USART2,USART_FLAG_RXNE) != RESET){  //��ѯ���ڴ������־λ
			a =USART_ReceiveData(USART2);//��ȡ���յ�������
			switch (a){
				case '0':
					Go_Forward();
					delay_ms(c);
					if(USART_GetFlagStatus(USART2,USART_FLAG_RXNE) == RESET)//��⵽�����ɿ���ͣ��
					{	
						Stop();							
					}			
					printf("%c:Go_Forward ",a); //
					break;
				
				case '1':
					Draw_Back();
					delay_ms(c);
					if(USART_GetFlagStatus(USART2,USART_FLAG_RXNE) == RESET)
					{	
						Stop();							
					}			
					printf("%c:Draw_Back",a); //
					break;
				
				case '2':
					Turn_left();
					printf("%c:Turn_left",a); //���յ������ݷ��ͻص���			
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
					printf("%c:Turn_right ",a); //���յ������ݷ��ͻص���
					break;
				
					case '4':
					Stop();
					printf("%c:Stop ",a); //���յ������ݷ��ͻص���
					break;
					
					case '5':			
					TIM_SetCompare3(TIM3,2000);        //�ı�Ƚ�ֵTIM3->CCR2�ﵽ����ռ�ձȵ�Ч��
					TIM_SetCompare4(TIM3,2000);
					printf("%c:fast speed ",a); //���յ������ݷ��ͻص���
					break;
					
					case '6':
					TIM_SetCompare3(TIM3,40000);        //�ı�Ƚ�ֵTIM3->CCR2�ﵽ����ռ�ձȵ�Ч��
					TIM_SetCompare4(TIM3,40000);
					printf("%c:medium speed ",a); //���յ������ݷ��ͻص���
					break;

					case '7':			
					TIM_SetCompare3(TIM3,48000);        //�ı�Ƚ�ֵTIM3->CCR2�ﵽ����ռ�ձȵ�Ч��
					TIM_SetCompare4(TIM3,48000);
					printf("%c:slow speed ",a); //���յ������ݷ��ͻص���
					break;					
					
				default:
					break;
			}		  
		}

	
	}
}


/*

���������塿
u32     a; //����32λ�޷��ű���a
u16     a; //����16λ�޷��ű���a
u8     a; //����8λ�޷��ű���a
vu32     a; //�����ױ��32λ�޷��ű���a
vu16     a; //�����ױ�� 16λ�޷��ű���a
vu8     a; //�����ױ�� 8λ�޷��ű���a
uc32     a; //����ֻ����32λ�޷��ű���a
uc16     a; //����ֻ�� ��16λ�޷��ű���a
uc8     a; //����ֻ�� ��8λ�޷��ű���a

#define ONE  1   //�궨��

delay_us(1); //��ʱ1΢��
delay_ms(1); //��ʱ1����
delay_s(1); //��ʱ1��

*/



