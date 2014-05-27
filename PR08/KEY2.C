//  檔名:KEY2.C
//  配合"單鍵實習板"
//  配合解彈跳(debounce)的程式設計
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sDelay.h"

sbit KEY1=P1^0 ;	//定義 KEY1 等於 P1.0
void delay20ms()	//呼叫延遲 20 毫秒之副程式
{
 Delay10ms();	//呼叫延遲 10 毫秒副程式
 Delay10ms();	//呼叫延遲 10 毫秒副程式
}

main()				//主程式
{
 P0=0 ;				//使LED全熄滅
 for(;;)
  {
    do
    {
    while(KEY1 ==1) ;	//當無按鍵時,會停在原地,若按鍵按下則往下執行消除彈跳
    delay20ms() ;	//呼叫延遲 20 毫秒副程式(消除彈跳用)
    }
    while(KEY1 == 1) ;	//若 KEY1 等於 1 表示是雜訊,則回上面的 do 繼續執行
			//若 KEY1 為 0 則表示按鍵有按下
    P0++;		//按鍵按下一次則 P0 累加一次

    do
    {
      while(KEY1==0) ;	//判斷按鍵是否放開,若沒放開則會停在原地,若放開則往下執行消除彈跳
      delay20ms() ;	//呼叫延遲 20 毫秒副程式(消除彈跳)
    }
    while(KEY1== 0) ;	//若 KEY1 等於 0 表示是雜訊,則回上面的 do 繼續執行
			//若 KEY1 為 1 表示按鍵有放開
  }
}
