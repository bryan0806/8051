//  �ɦW:Trig.C
//  �t�X"DAC0800��ߪO"
//  ��DAC0800�e�X�T���i��
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sDelay.h"
unsigned char code trigtbl[]={	//�T���i�θ��
000, 25, 51, 75,101,126,152,177,203,228,
255,228,203,177,152,126,101, 75, 51, 25 };
main()
{
  char i ;
  for(;;)		//�L�a�j��
  {
    for(i=19;i>=00;i--)	//�@��20�����
    {
    P0=trigtbl[i] ;	//��i�ҫ���trigtbl��ƿ�X��P0
    Delay1ms() ;	//����1�@��
    }
  }
}
