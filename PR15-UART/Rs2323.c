//  檔名:Rs2323.C
//  配合"RS232實習板"
//  等待讀取輸入資料並傳送
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>	//8051初始設定
char buf[10] ;	//設定字串容量為十個字元
char idx,c ;	//定義字元變數idx,c

main()
{
 idx=0 ;	//指標歸零
 SM0=0 ; SM1=1; //設定串列傳輸為模式1
 TMOD=0x20 ;	//設定TIMER1為8位元自動載入定時器
 TH1=TL1=0xfd ;	//設定鮑率為9600BPS
 TR1=1 ;	//開始計時
 REN=1 ;	//串列接收致能
 for(;;)
  {
  while(RI==0);	//若RI=0表示未接收,需等待
  RI=0 ;	//接收完後清除換下一資料
  c=SBUF ;	//把所接收的資料存入c中
  SBUF=c ;	//把c之資料給SBUF
  while(TI==0);	//若TI=0表示未傳完,需等待
  TI=0 ;	//傳送完後清除換下一資料
  }
}
