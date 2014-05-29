//  檔名:StepM3A.C
//  用二相激磁的方式,使步進馬達正轉n格
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>	//8051初始設定
#include "sDelay.h"	//延遲函式庫
#define n   10 	//定義n=10步
char code pp[]={0x3,0x6,0xC,0x9}; //二相激磁推動線之資料

main()
{
 int Step ;	//定義Step為整數變數
 char idx_pp=0 ;//定義idx_pp為字元變數其數值為0
 for(Step=0;Step<(n+1);Step++)
 {		//若Step<n+1,則繼續執行迴圈
 P0=pp[idx_pp++]; //P0=idx_pp所指之pp的資料,推動步進馬達
 if(idx_pp==4)	//若idx_pp=4,則
 idx_pp=0 ;	//還原資料
 Delay10ms() ;	//呼叫延遲10毫秒
 }
}
