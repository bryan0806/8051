//   檔名:DipSw1.C
//   配合"指撥開關/8個LED實習板"
//   指撥開關的ON/OFF分別控制8個LED的亮/熄
//   作業: 若指撥開關為 b1b0=00(關關)時 輸出為0x01
//                      b1b0=01(關開)時 輸出為0x02
//                      b1b0=10               0x03
//                      b1b0=11               0x04
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>

sbit in_sw0 = P1^0;
sbit in_sw1 = P1^1;

main()
{
		
        for(;;)
       {
            if(in_sw1 == 1 && in_sw0 ==1){      // 請先看電路圖 注意!!!: 當開關為開時 輸入為0 開關為關時 輸入信號為1
					P0=0x01;
			}else if(in_sw1 ==1 && in_sw0 ==0){
					P0=0x02;
			}else if(in_sw1 ==0 && in_sw0 ==1){
					P0=0x03;
			}else if(in_sw1 ==0 && in_sw0 ==0){
					P0=0x04;
			}                    
		}
}
