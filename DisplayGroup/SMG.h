#ifndef _SMG_H_
#define _SMG_H_
/***************************************************************************************************    
�������ƣ�	smg_library
����������	���������
Ӳ�����ӣ�  ��8λ�Ű��߽�J8��J12���ӣ�2λ�Ű��߷ֱ�J11_0��J15_DS1��J11_1��J15_DS2���ӡ�
ά����¼��  2019-4-27
***************************************************************************************************/



#define uchar unsigned char
#define uint  unsigned int
#define LOC 0x01
#define SMG_PORT  P1

extern uint __locketi;
sbit LocateLock=P2^0;           //λѡ573������ʹ��
sbit DATALock=P2^1;           //��ѡ573������ʹ��

extern uchar code SMG_CODE[17];//0~F�Ķ���

extern uchar SMG_ROM[8];
                    
void delay(uint time);
void SetData(int locketi, int Data);
void SMG_scan();
void SetLocket(int locketi);


#endif