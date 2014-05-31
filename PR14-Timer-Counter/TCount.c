//檔名:TCount.C
//配合"TIMER/COUNTER實習板"
//Timer0為計時器,Timer1為計數器,
//INT0為左右閃爍,INT1為間隔閃爍
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sdelay.h"
void timer() ;

main()
{
 P0=0 ;       //LED全暗
 TMOD=0x051 ; //T1為計數器,T0為計時器
 TH1=0xff ;   //TH1初值設定
 TL1=0xfb ;   //TL1初值設定
 TH0=(0xffff-5000)/256 ; //TH0=0xD8
 TL0=(0xffff-5000)%256 ; 

 IT0=1 ; //外部中斷0,設為負緣觸發
 IT1=1 ; //外部中斷1,設為負緣觸發
 EX0=1 ; //外部中斷0致能
 EX1=1 ; //外部中斷1致能
 ET0=1 ; //計時計數器0致能
 ET1=1 ; //計時計數器1致能
 TR0=1 ; //計時器0開始計時
 TR1=1 ; //計時器1開始計數
 EA=1 ;  //致能中斷功能

 for(;;) ; //停留原地等待中斷
}

void timer0(void) interrupt 1
{
 char i,j=3,savep0 ;
 savep0=P0;	//儲存P0值
 for(i=0;i<9;i++)
 {
 P0=j ;		//輸出至LED顯示
 j<<=1 ;	//j 左移一位
 Delay100ms() ;	//延遲100毫秒
 }
 TH0=(0xffff-5000)/256 ; //TH0=0xD8
 TL0=(0xffff-5000)%256 ;
 P0=savep0;	//還原P0值        
}

void timer1(void) interrupt 3
{
 unsigned int i,j=0xC0,savep0 ;
 savep0=P0;	//儲存P0值
 for(i=0;i<9;i++)
  {
    P0=j ;	//輸出至LED顯示           
    j = j >>1;	//j 右移一位	
    Delay100ms(); //延遲100毫秒
  }
 TH1=0xff ;	//恢復TH1值
 TL1=0xfb ;	//恢復TL1值
 P0=savep0;	//還原P0值
}

void external0(void) interrupt 0
{
 unsigned savep0 ;
 savep0=P0;	//儲存P0值
 P0=0x0f ;	//右半邊亮
 Delay100ms() ;	//延遲10毫秒
 P0=0xf0 ;	//左半邊亮
 Delay100ms() ;	//延遲10毫秒
 P0=savep0;	//還原P0值
}

void external1(void) interrupt 2
{
 unsigned savep0 ;
 savep0=P0;	//儲存P0值
 P0=0x55 ;	//靠右間隔亮
 Delay100ms() ;	//延遲10毫秒
 P0=0xaa ;	//靠左間隔亮
 Delay100ms() ;	//延遲10毫秒
 P0=savep0;	//還原P0值
}

