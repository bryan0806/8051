//  檔名:StepM1A.C
//  用單相激磁的方式,使步進馬達正轉n格
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>	//8051初始設定
#include "sDelay.h"	//延遲函式庫
#define n   10		//定義n=10步

main()
{//定義pp為無正負字元變數其值為0x1
 unsigned char pp=0x8 ;	
 int Step ;	//定義Step為整數變數
 for(Step=0;Step<(n+1);Step++)   
 {//若Step<n+1,則繼續執行迴圈
 P0=pp ;	//推動步進馬達
 pp>>=1 ;	//向左旋一位
 if(pp==0x00)	//若pp=0x10則
 pp=0x8 ;	//還原資料
 Delay10ms() ;	//呼叫延遲10毫秒
 }
}
