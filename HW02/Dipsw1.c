//   �ɦW:DipSw1.C
//   �t�X"�����}��/8��LED��ߪO"
//   �����}����ON/OFF���O����8��LED���G/��
//   �@�~: �Y�����}���� b1b0=00(����)�� ��X��0x01
//                      b1b0=01(���})�� ��X��0x02
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
            if(in_sw1 == 1 && in_sw0 ==1){      // �Х��ݹq���� �`�N!!!: ��}�����}�� ��J��0 �}�������� ��J�H����1
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
