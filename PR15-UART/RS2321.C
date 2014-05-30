//  檔名:Rs2321.C
//  配合"RS232實習板"
//  傳送一字串為"HELLO!!"
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>	    //8051初始設定
code char mes[]="Hello!!" ; //為一字串資料

main()
{
 char *s ;	//定義指標字元變數為s
 SM0=0 ; SM1=1;	//SM1=1,設定串列傳輸為模式1
 TMOD=0x20 ;	//TMOD=20H,設TIMER1為8位元自動載入定時器
 TH1=TL1=0xfd;	//TH1=TL1=0FDH,設定鮑率為9600bps
 TR1=1 ;	//TR1=1,開始計時
 for(s=mes;*s!='\0';)	
   {	//s=mes,把mes的位址給s;若不為'\0'則繼續繞
   SBUF=*s++ ;		//SBUF=s的下一位址之資料
   while(TI==0) ;	//若TI=0表示未傳完,需等待
   TI=0 ;		//傳送完後清除換下一資料
   }
 for(;;) ;		//停留原地
}


