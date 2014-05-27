//檔名:DOTMTX3.C
//配合"4個8*8彩色點矩陣LED實習板"
//在16*16彩色點矩陣LED上依序顯示三種顏色(紅-->綠-->黃,輪流)的中文字---"歡"
//
//色彩說明 P0 P2
//        0  0        黃
//        0  1        紅
//        1  0        綠
//        1  1        不亮
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sDelay.h"

//歡之字型資料表 hwan
unsigned char code hwan[]= { 
        0xFF,0xFF,0xDF,0xEF,0xD1,0x9F,0x84,0x00,
        0xD1,0x55,0xDE,0x55,xD1,0x01,0x85,0x55,
        0xD1,0x55,0xDE,0xFE,0xF9,0xF9,0x87,0xE7,
        0xB4,0x1F,0xF7,0xE7,0xF5,0xF9,0xE3,0xFE,
} ;

sbit CTRLLED= P2^0 ;            //定義 CTRLLED 等於 P2.0
sbit LRED1=P1^4 ;               //定義 LRED1 等於 P1.4
sbit LGREEN1=P1^5 ;             //定義 LGREEN1 等於 P1.5
sbit LRED2=P1^6 ;               //定義 LRED2 等於 P1.6
sbit LGREEN2=P1^7 ;             //定義 LGREEN2 等於 P1.7
#define BASEINT 25              //巨集 定義 BASEINT = 25
#define INTERVAL1  BASEINT*1    //巨集 定義 INTERVAL1 = BASEINT * 1 = 25 * 1 = 25
#define INTERVAL2  BASEINT*2    //巨集 定義 INTERVAL2 = BASEINT * 2 = 25 * 2 = 50
#define INTERVAL3  BASEINT*3    //巨集 定義 INTERVAL3 = BASEINT * 3 = 25 * 3 = 75

main()
{
        char idx ;              //宣告字元變數 idx
        unsigned int interval ; //宣告無號數整數變數 interval
        unsigned char color ;   //宣告無號數字元變數 color ,color=0(紅)color=1(綠),color=2(黃)
        idx=0 ;                 //令 idx = 0
        interval=0 ;            //令 interval = 0
        color=0 ;               //令 color = 0

        for( ; ;){
            CTRLLED=1 ;                         //關閉所有矩陣LED
            if((color== 0) || (color== 2)){     //若color=0(紅)或color=2(黃) 則
                P0=hwan[idx*2] ;                //取得資料表中第 idx*2 之資料,並輸出至P0
                LRED1=0 ;                       //使P0之資料輸出至上半部的矩陣LED(制能紅色)
                LRED1=1 ;
                P0=hwan[idx*2+1] ;              //取得資料表中第 idx*2+1 之資料,並輸出至P0
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
                P0=hwan[idx*2] ;                //取得資料表中第 idx*2 之資料,並輸出至P0
                LGREEN1=0 ;                     //使P0之資料輸出至上半部的矩陣LED(制能綠色)
                LGREEN1=1 ;
                P0=hwan[idx*2+1] ;              //取得資料表中第 idx*2 之資料,並輸出至P0
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
            P1 |=idx ;                          //再取得掃描值輸出
            CTRLLED=0 ;                         //啟動矩陣LED
            idx++ ;                             //令 idx = idx + 1
            if(idx >=16){                       //若 idx 大於等於 16 (矩陣以顯示一次),則
                interval++ ;                    //設 interval = interval + 1
                idx=0 ;                         //令 idx = 0 ,重新在顯示一次
            }
                                                //延遲時間
            if(interval ==  INTERVAL3){         //如果 interval 等於 INTERVAL3(75) (再延遲 25 * 1ms) 則
                interval=0 ;                    //設 interval = 0 重新計算延遲時間
                color=0 ;                       //設 color = 0 轉換成紅色
            }
            else if(interval == INTERVAL2){     //否則如果 interval 等於 INTERVAL2(50) (再延遲 25 * 1ms) 則
                color=2 ;                       //設 color = 2 轉換成黃色
            }
            else if(interval == INTERVAL1){     //否則如果 interval 等於 INTERVAL1(25) (延遲 25 * 1ms) 則
                color=1 ;                       //設 color = 1 轉換成綠色
            }
            Delay1ms() ;                        //呼叫延遲 1 毫秒副程式
        }
}
