//
//   �t�X"8��LED(�@��)��ߪO"
//       P0�ұ���8��LED(��l���A:�̥�2�ӫG�F��l6��LED����),�öi��k�۪��ܤ�
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sdelay.h"

main()
{
	P0 =0xc0;
	for(;;) {
	    Delay100ms() ;
	    if(P0&0x01){                 //P0�k��1�줸
		P0 >>=1 ;
		P0 |=0x80 ;
	    }
	    else{
		P0 >>= 1 ;
	    }
	}
}
