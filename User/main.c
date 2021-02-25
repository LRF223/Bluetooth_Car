#include "stm32f10x.h" //STM32头文件
#include "sys.h"
#include "delay.h"
#include "motor.h"
#include "key.h"
#include "usart.h"


int main (void){//主程序
	u8 a;
	//初始化程序
	RCC_Configuration(); //时钟设置
	MOTOR_Init();//LED初始化
	KEY_Init();//按键初始化
	USART2_Init(9600); //串口初始化（参数是波特率）

	//主循环
	while(1){
		int b = 100;
		int c = 50;
		//查询方式接收
		if(USART_GetFlagStatus(USART2,USART_FLAG_RXNE) != RESET){  //查询串口待处理标志位
			a =USART_ReceiveData(USART2);//读取接收到的数据
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
					printf("%c:Turn_left",a); //把收到的数据发送回电脑
					break;
				case '3':
					Turn_right();
					delay_ms(c);
					Stop();				
					printf("%c:Turn_right ",a); //把收到的数据发送回电脑
					break;
					case '4':
					Stop();
					printf("%c:Stop ",a); //把收到的数据发送回电脑
					break;
				default:
					break;
			}		  
		}

	
	}
}


/*

【变量定义】
u32     a; //定义32位无符号变量a
u16     a; //定义16位无符号变量a
u8     a; //定义8位无符号变量a
vu32     a; //定义易变的32位无符号变量a
vu16     a; //定义易变的 16位无符号变量a
vu8     a; //定义易变的 8位无符号变量a
uc32     a; //定义只读的32位无符号变量a
uc16     a; //定义只读 的16位无符号变量a
uc8     a; //定义只读 的8位无符号变量a

#define ONE  1   //宏定义

delay_us(1); //延时1微秒
delay_ms(1); //延时1毫秒
delay_s(1); //延时1秒

*/



