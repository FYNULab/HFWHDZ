#ifndef _SMG_H_
#define _SMG_H_
/***************************************************************************************************    
工程名称：	smg_library
功能描述：	控制数码管
硬件连接：  用8位杜邦线将J8与J12连接，2位杜邦线分别将J11_0与J15_DS1、J11_1与J15_DS2连接。
维护记录：  2019-4-27
***************************************************************************************************/



#define uchar unsigned char
#define uint  unsigned int
#define LOC 0x01
#define SMG_PORT  P1

extern uint __locketi;
sbit LocateLock=P2^0;           //位选573锁存器使能
sbit DATALock=P2^1;           //段选573锁存器使能

extern uchar code SMG_CODE[17];//0~F的段码

extern uchar SMG_ROM[8];
                    
void delay(uint time);
void SetData(int locketi, int Data);
void SMG_scan();
void SetLocket(int locketi);


#endif