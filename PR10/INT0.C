//  檔名:INT0.C
//  配合"中斷實習板"
//  INT0為遞增計數
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>	//8051初始設定
char Count ;		//字元資料為Count(全區域變數)

 main()
{
        P0=Count=0 ;	//LED全暗
        IT0=1 ;		//外部中斷0,設為負緣觸發
        EA=1;	//致能中斷功能
        EX0=1 ;	//外部中斷0致能
        for(;;) ;	//等待中斷
}

 void external0(void) interrupt 0
{
        Count++ ;	//Count=Count+1,累增計數
        P0=Count ;	//輸出至LED顯示
}
