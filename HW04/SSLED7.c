//   �ɦW:SSLED3.C
//   �t�X"4�ӤC�q��LED(�@��)��ߪO"
//   �b2�ӤC�q��LED�W��ܻ��W�Ʀr00~99;�䱽�˶��j��100ms
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sDelay.h"
unsigned char code sstbl[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};      //�إ߸�ƪ� sstbl
unsigned char code loc[]={ 0xf7,0xfb,0xfd,0xfe} ;                                    //�إ߸�ƪ� loc
main()
{
        char i ;                //�ŧi�r���ܼ� i (�N��n��ܤ��ƭ�)
        i=0 ;                   //�O i ���� 0
        for(i=0;i<100;i++){
            
            P1=0xff ;          //�����C�q��ܾ�
            P0=sstbl[i/10];    //�N��ܭȸg�ഫ�p�����ܩ�ĤT��
            P1=0xFD;           //���y�ĤT���C�q��ܾ�

            P1=0xff ;          //�����C�q��ܾ�
            P0=sstbl[i%10];    //�N��ܭȸg�ഫ�p�����ܩ�ĥ|��
            P1=0xFE;           //���y�ĥ|���C�q��ܾ�
            Delay100ms() ;     //�I�s���� 100 �@��Ƶ{��
        }
}


