//  檔名:StepM5.C
//  用半步激磁的方式,使步進馬達正轉n格
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>	//8051初始設定
#include "sDelay.h"	//延遲函式庫
#define n   10		//定義n=10步
char code pp[]={ 0x1,0x3,0x2,0x6, //半步激磁推動線之資料
                 0x4,0xC,0x8,0x9 } ;
main()
{
 int Step ;		//定義Step為整數變數
 char idx_pp=7 ;	//定義idx_pp為字元變數其數值為0
 for(Step=0;Step<(n*2+1);Step++) 
 {//若Step<n*2+1,則繼續執行迴圈
 P0=pp[idx_pp--]; //P0=idx_pp所指之pp的資料,推動步進馬達
 if(idx_pp==-1)	//若idx_pp=8,則
    idx_pp=7 ;	//還原資料
 Delay1s() ;	//呼叫延遲100毫秒
 }
}
