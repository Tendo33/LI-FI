实验简介
	实验内容: 学习串口UART的使用
	实验平台: ST官方STM32F746NGH6 Discovery开发板
	MDK版本 : 5.17
	固件库  : ST最新固件库STM32CubeF7
	说明    : 此程序为非凡进行二次开发,方便大家学习,此实验需用用户自己
			  通过CN4的D0(RX)、D1(TX)外接串口电路实验		      
	
实验功能
	打开串口调试助手,波特率9600.程序运行,LD1指示灯(reset按键旁),快速闪烁,
	串口调试助手会收到一条信息hello world!!!
	按下一次user按键,发送信息STM32F746 USART TEST!!!
	串口接收到长度小于100的信息,开发板会将接收的信息回发回来。

时钟分配	
	A.晶振：
		-外部高速晶振：25MHz
		-RTC晶振：32.768KHz

	B.各总线运行时钟：
		-系统时钟 = SYCCLK = AHB1 = 216MHz
		-APB2 = 108MHz 
		-APB1 = 54MHz

	C.浮点运算单元：使用


管脚分配
	LD1->PI1
	KEY->PI11
	TX->PC6
	RX->PC7

联系我们
	淘宝店铺: https://shop148702745.taobao.com/
	技术论坛: www.feifanembed.com
	QQ群:542830257