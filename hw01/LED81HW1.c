//
//   �t�X"8��LED(�@��)��ߪO"
//       P0�ұ���8��LED(��l���A:�̥k1�ӫG�F��l6��LED����),�öi�楪�۪��ܤ�
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
