//   �ɦW:Cgw2.C
//   �t�X"8��LED(�@��)��ߪO"
//   P0�ұ���8��LED,���ܤƤ覡:
//     �@�ӿO�ѥ����k�G,�@�ӿO�ѥk�����G,���аʧ@
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sDelay.h"
main()
{
        int  i;                         //�ŧi����ܼ� i
        char rr,ll;                     //�ŧi�r���ܼ� rr,ll
        for(;;) {
         ll = 0x80;                     //�]���k������� 0x80
         rr = 0x01;                     //�]����������� 0x01
         for(i=0 ; i<8 ; i++){          //�]�j�馸��
           P0 = ll | rr;                //��X���� ll �P rr ���ιB��
           ll >>= 1;                    //�N ll ���k���@��
           ll &= 0x7f;                  //�A�N ll �̰��줸�M�� 0 �m�ߤ@:�Y�o��N�L���� �i�ݨ� �̥����`�O�Q��J1 �]���Osigned char �m�ߤG:�ϥ�unsigned char�ݬO�_���`:
           rr <<= 1;                    //�N rr �����@�줸
           Delay100ms();                //�I�s���� 100 �@��Ƶ{��
         }
        }
}
