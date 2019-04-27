#include "reg52.h"
#include "SMG.h"

uint __locketi = 0;

uchar code SMG_CODE[17]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0x00};
uchar SMG_ROM[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00};

/***************************************************************************************************    
�������ƣ�	delay
����������	�������ʱ��ǿ�Ҳ�����ʹ�ã���Ӱ�������ʱ��
ά����¼��  2019-4-27
***************************************************************************************************/
void delay(uint time)         //int������Ϊ16λ,�������ֵΪ65535            
 {
  uint  i,j;             //�������i,j,����ѭ����� 
  for(i=0;i<time;i++)    //forѭ��,ѭ��50*time��
     for(j=0;j<50;j++);  //forѭ��,ѭ��50��
 }
/***************************************************************************************************    
�������ƣ�	SetData
����������	����locketiλ���ϵ�����Data
����˵����	locketi  int  λ��
			Data	int		���ݣ�0~15�ֱ��Ӧ0~F��16Ϊ�գ�
ά����¼��  2019-4-27
***************************************************************************************************/
void SetData(int locketi, int Data)
{
    SMG_ROM[locketi] = SMG_CODE[Data];
}
/***************************************************************************************************    
�������ƣ�	SMG_scan
����������	�����ˢ�£�һ�㽻�ɶ�ʱ��ϵͳ���ã�
����˵����	��
ά����¼��  2019-4-27
***************************************************************************************************/
void SMG_scan()
{
	SetLocket(__locketi);	
    SMG_PORT=SMG_ROM[__locketi];        
	DATALock=1;
	DATALock=0;

	__locketi++;                   //λ�ü�1
	if(__locketi>7)
	{
		__locketi = 0;
	}	
    delay(10);               //��ʱ����һ��,��ʱ�������������ʱ��С���а�Ӱ    
}
/***************************************************************************************************    
�������ƣ�	SetLocket
����������	�����λѡ�����������ˢ�º������ã�
����˵����	locketi int ����ܵ�ǰˢ��λ��
ά����¼��  2019-4-27
***************************************************************************************************/
void SetLocket(int locketi)
{
	uchar Locate; 
	Locate= LOC<<locketi;				 //����iλ
	SMG_PORT=~Locate;                //���ڹ������͵�ƽ��ѡͨĳ1λ��������ȡ��  
	LocateLock=1;					         //����λ
    LocateLock=0;                    //�Ͽ�����,λѡ573��Q7~Q0�Ա���                    
}
