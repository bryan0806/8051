//檔名:Dotmtxtw1.C
//配合"8*8單色點矩陣LED(共陽)實習板"
//在8*8單色點矩陣LED上顯示中文字並左旋---"台-中"
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sDelay.h"
unsigned char code dai[]={0xFF,0xEF,0xC1,0xA5,0x65,0xC1,0xEF,0xFF, //台
                          0xFF,0xC7,0xD7,0x01,0xD7,0xC7,0xFF,0xFF, //中
                         };   


Delay3ms()              //延遲 3 毫秒之副程式
{
        Delay1ms() ;    //呼叫延遲 1 毫秒
        Delay1ms() ;    //呼叫延遲 1 毫秒
        Delay1ms() ;    //呼叫延遲 1 毫秒
}
main()                  //主程式
{
      int i,j;				//宣告整數變數 i,j
      unsigned char com,idx,ids;	//宣告無號數字元變數 com,idx

      for(;;){
        com=0x80;		//令 com = 0x80
        ids=0;			//令 ids = 0
        idx=0;			//令 idx = 0
        for(i=0;i<16;i++){	//共使用8筆資料
          for(j=0;j<8;j++){	//掃描線共有8條
            P1=0xff;		//使矩陣LED全熄滅
            P0=dai[(idx++)%16];	//取得資料表中第 idx 筆資料,並輸出至 P0
            P1=~com;		//配合P1資料輸出,啟動行位址(P1.7 ~ P1.0)
            com >>=1;		//右移一行位址
            Delay3ms();		//呼叫延遲 3 毫秒副程式
          }
          com=0x80;		//令 com = 0x80 ,重新再顯示一次
          ids --;		//一個圖形有 8 個 byte
          idx = ids%16; 	//取下一筆圖形資料
         }
        }
}


