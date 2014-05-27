//  檔名:KEY3.C
//  配合"4*5鍵盤實習板"
//  簡單鍵盤掃瞄設計
// 作業 2 : 數字從上下反轉 所以 最上一排為16 17 18 19 -> 12 13 14 15 ->
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sDelay.h"
void delay20ms() ;		//使用到延遲 20 毫秒副程式

unsigned char code IdxCol[]= {	//按鍵對應表
        0 , 1 , 0 , 2 ,
        0 , 1 , 0 , 3 ,
        0 , 1 , 0 , 2 ,
        0 , 1 , 0 , 4 } ; 	// 只要改這邊即可

main() {			//主程式
 char row ;                    //宣告字元變數 row
 char keyflag ;                //宣告字元變數 keyflag
 char tP1 ;                    //宣告字元變數 tP1
 P0=0 ;                        //使LED全熄滅
 for(;;) {    
    do {      
	for(P1=tP1=0xf,row=0,keyflag=0;row<5;row++) {               
	//初始化P1=tP1=0xfe , row=keyflag=0. 若 row 小於 5 則 row 加 1
	if((P2&0xf)!=0xf) { //若P2 and 0xf不等於0xf表示有按鍵按下則
	  keyflag=1 ;	//令 keyflag=1
	  break ;	//並跳離for迴圈
	}		//若P2 and 0xf等於0xf則繼續往下
	tP1>>=1 ;	//tP1右移一個位元(掃描碼)
	//tP1+=1 ;	//
	tP1= tP1 | 0x10; // 強制補左方的1
	P1=tP1 ;	//將掃描碼送出
	}
	if(keyflag==1) {	//若按鍵旗標等於 1 表示有按鍵按下,則	  
	    delay20ms() ;	//呼叫延遲 20 毫秒副程式(消除彈跳)
	    if((P2&0xf)==0xf)	//再一次確定是否有按鍵按下,若無按鍵按下則
	    keyflag=0 ;		//令 keyflag = 0 表示是雜訊
	    }
	} while(keyflag==0) ;	//當確定有按鍵按下時則跳離迴圈往下繼續

	P0=row*4+IdxCol[P2&0xf];//取得row*4加上按鍵對應值,並輸出至 P0
	do {
	   while((P2&0xf)!=0xf);//判斷按鍵是否放開,若沒放開則停在原地,
				//若放開則往下繼續
	   delay20ms() ;	//呼叫延遲 20 毫秒副程式(消除彈跳)
	} while((P2&0xf)!=0xf);	//再一次確定按鍵是否放開,若按鍵沒放開則                                    
    }//回上一個 do 繼續,若按鍵放開則繼續執行
}
void delay20ms() {	//延遲 20 毫秒之副程式
        Delay10ms() ;	//呼叫延遲 10 毫秒副程式
        Delay10ms() ;	//呼叫延遲 10 毫秒副程式
}
