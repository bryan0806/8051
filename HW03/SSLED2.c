//   檔名:SSLED2.C
//   配合"1個七段式LED(共陽)實習板"
//   依序在七段式LED上顯示數字0,1,2,3,4,5,6,7,8,9
//   作業: 9 之後 加上A,B,C,D,E,F
#pragma oe db pw(80) SM SB CD
#include        <reg51.h>
#include "sDelay.h"
unsigned char code sstbl[]= { 0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e} ;  //建立資料表 非常小心 請看電路圖!!! abcdefg.電路圖接線是a = p0.0 ... dot = p0.7
main()
{
        char i ;                //宣告字元變數 i
        i=0 ;                   //令 i 等於 0
        for(;;){
            P0=sstbl[i++] ;     //取得資料表 sstbl 第 i 筆資料並輸出至 P0
            if(i >=16)          //若 i 大於等於 10 則
                i=0 ;           //設 i 為 0 重新顯示
            Delay100ms() ;      //呼叫延遲 100 毫秒副程式
        }
}
