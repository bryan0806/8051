//�ɦW:Dotmtx1a.C
//�t�X"8*8����I�x�}LED(�@��)��ߪO"
//�b8*8����I�x�}LED�W��ܤ���r---"�j"
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sDelay.h"
unsigned char code dai[]={0xdd,0xcb,0x17,0xcb,0xdd,0xcb,0x01,0xff};  //�إ߸�ƪ� dai
delay3ms()              //���� 3 �@���Ƶ{��
{
        Delay1ms() ;    //�I�s���� 1 �@��
        Delay1ms() ;    //�I�s���� 1 �@��
        Delay1ms() ;    //�I�s���� 1 �@��
}
main()                  //�D�{��
{
        unsigned char com ,idx; //�ŧi�L���Ʀr���ܼ� com,idx

        com=0x80 ;              //�O com = 0x80
        idx=0 ;                 //�O idx = 0
        for( ;;){
            P1=0xff ;           //�ϯx�}LED������
            P0=dai[idx++] ;     //���o��ƪ��� idx �����,�ÿ�X��P0
            P1=~com ;           //�t�XP0��ƿ�X,�Ұʦ��}(P1.7 ~ P1.0)
            com >>=1 ;          //�k���@���}
            if(idx==8){         //�Y�k�� 8 ��(�H��ܤ@��),�h
                idx=0;          //�O idx = 0
                com=0x80 ;      //�O com = 0x80 ,���s�b��ܤ@��
            }
            delay3ms() ;        //�I�s���� 3 �@��Ƶ{��
        }
}


