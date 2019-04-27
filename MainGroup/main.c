#include "reg52.h"
#include "timer.h"
#include "SMG.h"

uchar temp;          //定义变量

void main()
{
	TimerInterruptInit();
	SetData(0,1);
	SetData(1,2);
	SetData(2,3);
	SetData(3,4);
	SetData(4,5);
	SetData(5,6);
	SetData(6,7);
	SetData(7,16);
	  while(1)
	  {
	  	 SMG_scan();
	  }

}


void TimerInterruptInit()
{
   TMOD=0x01;    //0b00000001  用的是定时器0，工作在方式1（16位寄存器）//要实现定时50ms,(65536-T0)x12/12000000=0.05s得T0=15536即0x3cb0
   TH0=0x3c;     //装定时器初值高8位
   TL0=0xb0;     //装定时器初值低8位
   TR0=1;        //启动定时器0
   ET0=1;        //开定时器0中断
   EA=1;         //开总中断
}


timer0() interrupt 1 using 1
{
  TH0=0x3c;         //重置定时器初值
  TL0=0xb0;
  if(temp>=10)      //满20次，即20次*50ms=1s
   {
		temp = 0x00;
   }
  else
   {
		temp++;        //每进一次中断，temp加1
   }
}
