//  檔名:TIMER0A.C
//  配合"TIMER/COUNTER實習板"
//  利用計時中斷產生計數延遲效果
// Homework: change to timer 1 and delay 1s
#pragma oe db pw(80) SM SB CD
#include <reg51.h>	//8051初始設定
char Count ;	//定義字元資料為Count

main()
{
 P0=Count=0 ;	//LED全暗
 TMOD=0x10 ;	//設定Timer0為16位元計時器
 TH0=(0xffff-100000)/256;	//TH0=0xD8
 TL0=(0xffff-100000)%256;	//TL0=0xEF
 EA=1 ;		//致能中斷功能
 ET1=1 ;	//計時計數器0致能
 TR1=1 ;	//計時器0開始計時
 for(;;) ;	//等待計時中斷
}
 void timer1(void) interrupt 3
{
 Count++ ;	//Count=Count+1,累增一
 P0=Count ;	//輸出至LED顯示
 TH0=(0xffff-100000)/256; //TH0=0xD8,還原計時數值
 TL0=(0xffff-100000)%256; //TL0=0xEF
}
