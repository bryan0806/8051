//檔名:ADC2.C
//配合"ADC0804實習板"
//讀取ADC0804的類比電壓值(採用查詢方式來同步),
//並將之顯示於8個LED上
#pragma oe db pw(80) SM SB CD
#include <reg51.h>	//8051初始設定
sbit ADCRD=P1^0 ;	//設定P1.0接腳名稱為ADCRD
sbit ADCWR=P1^1 ;	//設定P1.1接腳名稱為ADCWR
sbit ADCINTR=P3^2 ;	//設定P3.2接腳名稱為ADCINTR

main()
{
  for(;;)
  {		//start ADC
  ADCWR=0 ;	//設定ADCWR(寫入)信號以啟動ADC轉換
  ADCWR=1 ;	//清除ADCWR(寫入)信號
  while(ADCINTR) ;	//若ADCINTR=0則表示已轉換完成
  ADCRD=0 ;	//設定ADCRD(讀出)信號以讀取轉換結果值
  P2=P0 ;	//P0輸入之值送至P2由LED顯示數位值
  ADCRD=1 ;	//清除ADCRD(讀出)信號
     }
}
