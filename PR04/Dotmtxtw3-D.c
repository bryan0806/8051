//檔名:Dotmtxtw3.C
//配合"8*8單色點矩陣LED(共陽)實習板"
//在8*8單色點矩陣LED上顯示上移的中文字---"台"
//作業:改成下移
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sDelay.h"
unsigned char dai[]={0xFF,0xEF,0xC1,0xA5,0x65,0xC1,0xEF,0xFF}; //台

Delay3ms()        //延遲 3 毫秒之副程式
{
  Delay1ms() ;    //呼叫延遲 1 毫秒
  Delay1ms() ;    //呼叫延遲 1 毫秒
  Delay1ms() ;    //呼叫延遲 1 毫秒
}
main()                  //主程式
{
  int i,j;		//宣告整數變數 i,j
  unsigned char ch,com;	//宣告無號數字元變數 ch,com

  for(;;){
    com=0x80;		  //令 com = 0x80
    for(i=0;i<8;i++){	  //共使用8筆資料
        for(j=0;j<8;j++){ //掃描線共有8條
            P1=0xff;	  //使矩陣LED全熄滅
	    P0=dai[j];	  //取得資料表中第 idx 筆資料,並輸出至 P0
            P1=~com;	  //配合P1資料輸出,啟動行位址(P1.7 ~ P1.0)
            com >>=1;	  //右移一行位址
            Delay3ms();	  //呼叫延遲 3 毫秒副程式
        }
	for(j=0;j<8;j++){ //將字型表的每一筆資料均"下旋"(右旋)ㄧ位元
	    ch=dai[j];
	    if ( (ch&0x01)==0x01 ) { //判斷最右邊 位數 若為1
		ch=ch>>1; //右移
		ch=ch|0x80;  // 原位數變成10000000
		} else ch=ch>>1;
	    dai[j]=ch;
	}
	com=0x80;	  //令 com = 0x80 ,重新再顯示一次
    }
  }
}
