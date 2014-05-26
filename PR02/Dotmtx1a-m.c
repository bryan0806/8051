//檔名:Dotmtx1a.C
//配合"8*8單色點矩陣LED(共陽)實習板"
//在8*8單色點矩陣LED上顯示中文字---"大"
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sDelay.h"
unsigned char code dai[]={0xdd,0xcb,0x17,0xcb,0xdd,0xcb,0x01,0xff};  //建立資料表 dai
delay3ms()              //延遲 3 毫秒之副程式
{
        Delay1ms() ;    //呼叫延遲 1 毫秒
        Delay1ms() ;    //呼叫延遲 1 毫秒
        Delay1ms() ;    //呼叫延遲 1 毫秒
}
main()                  //主程式
{
        unsigned char com ,idx; //宣告無號數字元變數 com,idx

        com=0x80 ;              //令 com = 0x80
        idx=0 ;                 //令 idx = 0
        for( ;;){
            P1=0xff ;           //使矩陣LED全熄滅
            P0=dai[idx++] ;     //取得資料表中第 idx 筆資料,並輸出至P0
            P1=~com ;           //配合P0資料輸出,啟動行位址(P1.7 ~ P1.0)
            com >>=1 ;          //右移一行位址
            if(idx==8){         //若右移 8 次(以顯示一次),則
                idx=0;          //令 idx = 0
                com=0x80 ;      //令 com = 0x80 ,重新在顯示一次
            }
            delay3ms() ;        //呼叫延遲 3 毫秒副程式
        }
}


