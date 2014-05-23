//   檔名:SSLED3.C
//   配合"4個七段式LED(共陽)實習板"
//   在2個七段式LED上顯示遞增數字00~99;其掃瞄間隔為100ms
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sDelay.h"
unsigned char code sstbl[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};      //建立資料表 sstbl
unsigned char code loc[]={ 0xf7,0xfb,0xfd,0xfe} ;                                    //建立資料表 loc
main()
{
        char i ;                //宣告字元變數 i (代表要顯示之數值)
        i=0 ;                   //令 i 等於 0
        for(i=0;i<100;i++){
            
            P1=0xff ;          //關閉七段顯示器
            P0=sstbl[i/10];    //將顯示值經轉換計算後顯示於第三顆
            P1=0xFD;           //掃描第三顆七段顯示器

            P1=0xff ;          //關閉七段顯示器
            P0=sstbl[i%10];    //將顯示值經轉換計算後顯示於第四顆
            P1=0xFE;           //掃描第四顆七段顯示器
            Delay100ms() ;     //呼叫延遲 100 毫秒副程式
        }
}


