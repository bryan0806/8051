//  檔名:Timer.C
//  配合"TIMER/COUNTER實習板"
//  利用計時中斷產生週期性之動作(左旋與右旋)
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sdelay.h"
char Count,i,k ;
void timer() ;

main()
{
 char j ;
 P0=Count=0 ;	//LED全暗
 TMOD=0x011 ;	//T1為計時器,T0為計時器
 TH0=0xe0 ;	//TH0初值設定
 //TL1=0 ;	//TL1初值設定 this line can be skipped because in the below , it was changed immediately
 //TL0=0 ;	//TL0初值設定*/ this line can be skipped because in the below , it was changed immediately
 TH0=(0xffff-5000)/256;	//TH0=0xD8
 TL0=(0xffff-5000)%256 ; 
 TH1=(0xffff-5000)/256;	//TH0=0xD8
 TL1=(0xffff-5000)%256 ; 
 ET0=1 ;	//計時計數器0致能
 ET1=1 ;	//計時計數器1致能
 TR0=1 ;	//計時器0開始計時
 TR1=1 ;	//計時器1開始計數
 EA=1 ;	//致能中斷功能
 for(;;) ;	//停留原地,等待中斷
}

void timer0(void) interrupt 1
{
 char j,i ;
 j=1 ;
 for(i=0;i<8;i++)
 {
 P0=j ;		//輸出至LED顯示
 j<<=1 ;	//j 左移一位
 Delay100ms();	//延遲100毫秒
 }
 TH0=(0xffff-5000)/256;	//TH0=0xD8
 TL0=(0xffff-5000)%256 ; 
 P0=0 ;			//清除P0
}

void timer1(void) interrupt 3
{
 unsigned char j,i ;
 j=0x80 ;
 for(i=0;i<8;i++)
 {
 P0=j ;	//輸出至LED顯示
 j=j>>1;
 Delay100ms() ;	//延遲100毫秒
 }                         
 TH1=(0xffff-5000)/256 ;//恢復TH1值
 TL1=(0xffff-5000)%256 ;//恢復TL1值 
 P0=0 ;                 //清除P0
}

