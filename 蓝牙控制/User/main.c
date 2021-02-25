#include "stm32f10x.h" //STM32ͷ�ļ�
#include "sys.h"
#include "delay.h"
#include "motor.h"
#include "key.h"
#include "usart.h"


int main (void){//������
	u8 a;
	//��ʼ������
	RCC_Configuration(); //ʱ������
	MOTOR_Init();//LED��ʼ��
	KEY_Init();//������ʼ��
	USART2_Init(9600); //���ڳ�ʼ���������ǲ����ʣ�

	//��ѭ��
	while(1){
		int b = 100;
		int c = 50;
		//��ѯ��ʽ����
		if(USART_GetFlagStatus(USART2,USART_FLAG_RXNE) != RESET){  //��ѯ���ڴ������־λ
			a =USART_ReceiveData(USART2);//��ȡ���յ�������
			switch (a){
				case '0':
					Go_Forward();
					delay_ms(b);
					Stop();
					printf("%c:Go_Forward ",a); //
					break;
				case '1':
					Draw_Back();
					delay_ms(b);
					Stop();					
					printf("%c:Draw_Back",a); //
					break;
				case '2':
					Turn_left();
					delay_ms(c);
					Stop();				
					printf("%c:Turn_left",a); //���յ������ݷ��ͻص���
					break;
				case '3':
					Turn_right();
					delay_ms(c);
					Stop();				
					printf("%c:Turn_right ",a); //���յ������ݷ��ͻص���
					break;
					case '4':
					Stop();
					printf("%c:Stop ",a); //���յ������ݷ��ͻص���
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



