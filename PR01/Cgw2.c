//   檔名:Cgw2.C
//   配合"8個LED(共陰)實習板"
//   P0所接的8個LED,其變化方式:
//     一個燈由左往右亮,一個燈由右往左亮,反覆動作
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sDelay.h"
main()
{
        int  i;                         //宣告整數變數 i
        char rr,ll;                     //宣告字元變數 rr,ll
        for(;;) {
         ll = 0x80;                     //設往右移之初值 0x80
         rr = 0x01;                     //設往左移之初值 0x01
         for(i=0 ; i<8 ; i++){          //設迴圈次數
           P0 = ll | rr;                //輸出等於 ll 與 rr 左或運算
           ll >>= 1;                    //將 ll 往右移一位
           ll &= 0x7f;                  //再將 ll 最高位元清為 0 練習一:若這邊將他隱藏 可看到 最左邊總是被填入1 因為是signed char 練習二:使用unsigned char看是否正常:
           rr <<= 1;                    //將 rr 左移一位元
           Delay100ms();                //呼叫延遲 100 毫秒副程式
         }
        }
}
