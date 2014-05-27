//  檔名:KEY1.C
//  配合"單鍵實習板"
//  按鍵的彈跳現象(bounce)
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
sbit KEY1=P1^0 ;	//定義 KEY1 等於 P1.0
main()			//主程式
{
 P0=0 ;			//使LED全熄滅
 for(;;)
   {
   while(KEY1 ==1) ; //若無按鍵時,會停在原地,若按鍵按下則往下執行
   P0++;	     //按鍵按下一次則 P0 累加 n 次(因為有彈跳產生)
   while(KEY1==0) ;  //判斷按鍵是否放開,沒放開會停在原地,若按鍵放開則繼續執行
   }
}
