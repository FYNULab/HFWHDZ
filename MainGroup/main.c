#include "reg52.h"
#include "timer.h"
#include "SMG.h"

uchar temp;          //�������

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
   TMOD=0x01;    //0b00000001  �õ��Ƕ�ʱ��0�������ڷ�ʽ1��16λ�Ĵ�����//Ҫʵ�ֶ�ʱ50ms,(65536-T0)x12/12000000=0.05s��T0=15536��0x3cb0
   TH0=0x3c;     //װ��ʱ����ֵ��8λ
   TL0=0xb0;     //װ��ʱ����ֵ��8λ
   TR0=1;        //������ʱ��0
   ET0=1;        //����ʱ��0�ж�
   EA=1;         //�����ж�
}


timer0() interrupt 1 using 1
{
  TH0=0x3c;         //���ö�ʱ����ֵ
  TL0=0xb0;
  if(temp>=10)      //��20�Σ���20��*50ms=1s
   {
		temp = 0x00;
   }
  else
   {
		temp++;        //ÿ��һ���жϣ�temp��1
   }
}
