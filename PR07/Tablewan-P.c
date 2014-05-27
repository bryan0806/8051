//   檔名:Tablewan.C
//   配合"4個8*8彩色點矩陣LED實習板"
//   在16*16彩色點矩陣LED上顯示'歡迎參觀'左旋,每旋轉一次換一種顏色
//   色彩說明 P0 P2
//             0  0        黃
//             0  1        紅
//             1  0        綠
//             1  1        不亮
// 習題是 修改程式讓" 觀"後面的雜訊 消失
#pragma oe db pw(80) SM SB CD
#include        <reg51.h>
#include "sDelay.h"
unsigned char code hwan[]= { 0xFF,0xFF,0xFF,0xFF,       //空白
                             0xFF,0xFF,0xFF,0xFF,
                             0xFF,0xFF,0xFF,0xFF,
                             0xFF,0xFF,0xFF,0xFF,
                             0xFF,0xFF,0xFF,0xFF,
                             0xFF,0xFF,0xFF,0xFF,
                             0xFF,0xFF,0xFF,0xFF,
                             0xFF,0xFF,0xFF,0xFF,

                             0xFF,0xFF,0xDF,0xEF,       //歡
                             0xD1,0x9F,0x84,0x00,
                             0xD1,0x55,0xDE,0x55,
                             0xD1,0x01,0x85,0x55,
                             0xD1,0x55,0xDE,0xFE,
                             0xF9,0xF9,0x87,0xE7,
                             0xB4,0x1F,0xF7,0xE7,
                             0xF5,0xF9,0xE3,0xFE,
                             0xFF,0xFF,0xFF,0xFF,
                             0xFF,0xFF,0xFF,0xFF,

                             0xFF,0xFF,0xF7,0xBE,       //迎
                             0xBB,0xB9,0xDB,0x07,
                             0xDF,0xBB,0xFF,0xDD,
                             0x80,0x0D,0xDF,0xDE,
                             0xBF,0xBE,0xBF,0x7E,
                             0xFF,0xFE,0x80,0x02,
                             0xDF,0xDE,0xDF,0xCE,
                             0x80,0x1D,0xDF,0xFD,
                             0xFF,0xFF,0xFF,0xFF,
                             0xFF,0xFF,0xFF,0xFF,

                             0xFF,0xFF,0xFD,0xBF,       //參
                             0xFC,0xAB,0xE9,0xAA,
                             0xE5,0x6A,0xED,0x56,
                             0x8B,0x55,0xAC,0xB5,
                             0xEE,0xAD,0xAD,0x6B,
                             0xD9,0x5B,0xE5,0x57,
                             0xFD,0xB7,0xFB,0xBF,
                             0xFC,0xBF,0xFF,0xBF,
                             0xFF,0xFF,0xFF,0xFF,
                             0xFF,0xFF,0xFF,0xFF,

                             0xFF,0xFF,0xD1,0xDF,       //觀
                             0x85,0x00,0xD0,0x55,
                             0xDF,0x55,0xD1,0x01,
                             0x84,0x55,0xD1,0x55,
                             0xFF,0xFE,0x80,0x1D,
                             0xD6,0xC3,0xD6,0xDF,
                             0xD6,0xC1,0x80,0x1E,
                             0xDF,0xF0,0xFF,0xFD};


sbit CTRLLED= P2^0 ;            //定義 CTRLLED 等於 P2.0
sbit LRED1=P1^4 ;               //定義 LRED1 等於 P1.4
sbit LGREEN1=P1^5 ;             //定義 LGREEN1 等於 P1.5
sbit LRED2=P1^6 ;               //定義 LRED2 等於 P1.6
sbit LGREEN2=P1^7 ;             //定義 LGREEN2 等於 P1.7

main()
{
        int i,j;                        //宣告整數變數 i,j
        char idx ;                      //宣告字元變數 idx
        unsigned int interval ;         //宣告無號數整數變數 interval
        unsigned char color ;           //宣告無號數字元變數 color ,color=0(紅)color=1(綠),color=2(黃)
        unsigned char woffset ;         //宣告無號數字元變數 woffset (取得第幾筆資料用)
        idx=0 ;                         //令 idx = 0
        woffset=0 ;                     //令 woffset = 0
        interval=0 ;                    //令 interval = 0
        color=0 ;                       //令 color = 0

        for( ; ;){
         for(i=0;i<4;i++){                      //每左移一次停 4*1ms
            for(idx=0;idx<=15;idx++){           //掃描垂直線
            CTRLLED=1 ;                         //關閉所有矩陣LED
            if((color== 0) || (color== 2)){     //若color=0(紅)或color=2(黃) 則
                P0=hwan[woffset+idx*2] ;        //取得資料表中第 woffset+idx*2 之資料,並輸出至P0
                LRED1=0 ;                       //使P0之資料輸出至上半部的矩陣LED(制能紅色)
                LRED1=1 ;
                P0=hwan[woffset+idx*2+1] ;      //取得資料表中第 woffset+idx*2+1 之資料,並輸出至P0
                LRED2=0 ;                       //使P0之資料輸出至下半部的矩陣LED(制能紅色)
                LRED2=1 ;
            }
            else{
                P0=0xff ;                       //否則 P0 輸出 11111111
                LRED1=0 ;                       //使P0之資料 11111111 輸出至上半部的矩陣LED
                LRED1=1 ;                       
                LRED2=0 ;                       //使P0之資料 11111111 輸出至下半部的矩陣LED
                LRED2=1 ;                       //使輸出為綠色
            }
            if((color== 1) || (color== 2)){     //若color=1(綠)或color=2(黃) 則
                P0=hwan[woffset+idx*2] ;        //取得資料表中第 woffset+idx*2 之資料,並輸出至P0
                LGREEN1=0 ;                     //使P0之資料輸出至上半部的矩陣LED(制能綠色)
                LGREEN1=1 ;
                P0=hwan[woffset+idx*2+1] ;      //取得資料表中第 woffset+idx*2+1 之資料,並輸出至P0
                LGREEN2=0 ;                     //使P0之資料輸出至下半部的矩陣LED(制能綠色)
                LGREEN2=1 ;                     //           (若紅色和綠色都被制能則會輸出黃色)
            }
            else{
                P0=0xff ;                       //否則 P0 輸出 11111111
                LGREEN1=0 ;                     //使P0之資料 11111111 輸出至上半部的矩陣LED
                LGREEN1=1 ;
                LGREEN2=0 ;                     //使P0之資料 11111111 輸出至下半部的矩陣LED
                LGREEN2=1 ;                     //使輸出為紅色
            }

            P1 &=0xf0 ;                         //令 P1 = P1 and 11110000
            P1 |=(idx &0xf);                    //再取得掃描值輸出
            CTRLLED=0 ;                         //啟動矩陣LED
            Delay100usP(2) ;                    //呼叫延遲200微秒副程式
            CTRLLED=1 ;                         //啟動矩陣LED
            }
            woffset = interval;                 //這一行是右移的關鍵: interval每次加2 所以每次woffset會多2 即右移一行
           }

           interval+=2;                         //設 interval = interval + 1
           if(interval>=152){                   // 這邊若改成152(32+40+40+40)就會把雜訊消失 因為只需移到最後一行是"觀"的最後一行即可 之前以184時等於還有32行資料位移 但array已經沒有資料了 所以產生亂碼
            interval = 0;                       //設 interval 等於 0
            woffset=interval;                   //再將 interval 之值給 woffset
            j++;                                //j 值加 1
           }
           if(j==1)                             //若 j 等於 1 則
             color=1;                           //設顏色為綠色
           if(j==2)                             //若 j 等於 2 則
             color=2;                           //設顏色為黃色
           if(j==3){                            //若 j 等於 3 則
             color=0;                           //設顏色為紅色
             j=0;                               //清除 j
           }
        }
}
