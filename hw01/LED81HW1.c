//
//   配合"8個LED(共陰)實習板"
//       P0所接的8個LED(初始狀態:最右1個亮；其餘6個LED熄著),並進行左旋的變化
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sdelay.h"

main()
{
	P0 =0x01;
	for(;;) {
	    Delay100ms() ;
	    if(!(P0&0x80)){                 //Look the P7: if it is 0, then shift to left, if it is 1, then shift left and reset to 0x01
		P0 <<=1 ;
	    }
	    else{
		P0 <<= 1 ;
		P0 = 0x01;
	    }
	}
}
