//   �ɦW:SSLED2.C
//   �t�X"1�ӤC�q��LED(�@��)��ߪO"
//   �̧Ǧb�C�q��LED�W��ܼƦr0,1,2,3,4,5,6,7,8,9
//   �@�~: 9 ���� �[�WA,B,C,D,E,F
#pragma oe db pw(80) SM SB CD
#include        <reg51.h>
#include "sDelay.h"
unsigned char code sstbl[]= { 0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e} ;  //�إ߸�ƪ� �D�`�p�� �Ьݹq����!!! abcdefg.�q���ϱ��u�Oa = p0.0 ... dot = p0.7
main()
{
        char i ;                //�ŧi�r���ܼ� i
        i=0 ;                   //�O i ���� 0
        for(;;){
            P0=sstbl[i++] ;     //���o��ƪ� sstbl �� i ����ƨÿ�X�� P0
            if(i >=16)          //�Y i �j�󵥩� 10 �h
                i=0 ;           //�] i �� 0 ���s���
            Delay100ms() ;      //�I�s���� 100 �@��Ƶ{��
        }
}
