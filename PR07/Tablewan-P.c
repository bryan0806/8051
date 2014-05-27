//   �ɦW:Tablewan.C
//   �t�X"4��8*8�m���I�x�}LED��ߪO"
//   �b16*16�m���I�x�}LED�W���'�w����['����,�C����@�����@���C��
//   ��m���� P0 P2
//             0  0        ��
//             0  1        ��
//             1  0        ��
//             1  1        ���G
// ���D�O �ק�{����" �["�᭱�����T ����
#pragma oe db pw(80) SM SB CD
#include        <reg51.h>
#include "sDelay.h"
unsigned char code hwan[]= { 0xFF,0xFF,0xFF,0xFF,       //�ť�
                             0xFF,0xFF,0xFF,0xFF,
                             0xFF,0xFF,0xFF,0xFF,
                             0xFF,0xFF,0xFF,0xFF,
                             0xFF,0xFF,0xFF,0xFF,
                             0xFF,0xFF,0xFF,0xFF,
                             0xFF,0xFF,0xFF,0xFF,
                             0xFF,0xFF,0xFF,0xFF,

                             0xFF,0xFF,0xDF,0xEF,       //�w
                             0xD1,0x9F,0x84,0x00,
                             0xD1,0x55,0xDE,0x55,
                             0xD1,0x01,0x85,0x55,
                             0xD1,0x55,0xDE,0xFE,
                             0xF9,0xF9,0x87,0xE7,
                             0xB4,0x1F,0xF7,0xE7,
                             0xF5,0xF9,0xE3,0xFE,
                             0xFF,0xFF,0xFF,0xFF,
                             0xFF,0xFF,0xFF,0xFF,

                             0xFF,0xFF,0xF7,0xBE,       //��
                             0xBB,0xB9,0xDB,0x07,
                             0xDF,0xBB,0xFF,0xDD,
                             0x80,0x0D,0xDF,0xDE,
                             0xBF,0xBE,0xBF,0x7E,
                             0xFF,0xFE,0x80,0x02,
                             0xDF,0xDE,0xDF,0xCE,
                             0x80,0x1D,0xDF,0xFD,
                             0xFF,0xFF,0xFF,0xFF,
                             0xFF,0xFF,0xFF,0xFF,

                             0xFF,0xFF,0xFD,0xBF,       //��
                             0xFC,0xAB,0xE9,0xAA,
                             0xE5,0x6A,0xED,0x56,
                             0x8B,0x55,0xAC,0xB5,
                             0xEE,0xAD,0xAD,0x6B,
                             0xD9,0x5B,0xE5,0x57,
                             0xFD,0xB7,0xFB,0xBF,
                             0xFC,0xBF,0xFF,0xBF,
                             0xFF,0xFF,0xFF,0xFF,
                             0xFF,0xFF,0xFF,0xFF,

                             0xFF,0xFF,0xD1,0xDF,       //�[
                             0x85,0x00,0xD0,0x55,
                             0xDF,0x55,0xD1,0x01,
                             0x84,0x55,0xD1,0x55,
                             0xFF,0xFE,0x80,0x1D,
                             0xD6,0xC3,0xD6,0xDF,
                             0xD6,0xC1,0x80,0x1E,
                             0xDF,0xF0,0xFF,0xFD};


sbit CTRLLED= P2^0 ;            //�w�q CTRLLED ���� P2.0
sbit LRED1=P1^4 ;               //�w�q LRED1 ���� P1.4
sbit LGREEN1=P1^5 ;             //�w�q LGREEN1 ���� P1.5
sbit LRED2=P1^6 ;               //�w�q LRED2 ���� P1.6
sbit LGREEN2=P1^7 ;             //�w�q LGREEN2 ���� P1.7

main()
{
        int i,j;                        //�ŧi����ܼ� i,j
        char idx ;                      //�ŧi�r���ܼ� idx
        unsigned int interval ;         //�ŧi�L���ƾ���ܼ� interval
        unsigned char color ;           //�ŧi�L���Ʀr���ܼ� color ,color=0(��)color=1(��),color=2(��)
        unsigned char woffset ;         //�ŧi�L���Ʀr���ܼ� woffset (���o�ĴX����ƥ�)
        idx=0 ;                         //�O idx = 0
        woffset=0 ;                     //�O woffset = 0
        interval=0 ;                    //�O interval = 0
        color=0 ;                       //�O color = 0

        for( ; ;){
         for(i=0;i<4;i++){                      //�C�����@���� 4*1ms
            for(idx=0;idx<=15;idx++){           //���y�����u
            CTRLLED=1 ;                         //�����Ҧ��x�}LED
            if((color== 0) || (color== 2)){     //�Ycolor=0(��)��color=2(��) �h
                P0=hwan[woffset+idx*2] ;        //���o��ƪ��� woffset+idx*2 �����,�ÿ�X��P0
                LRED1=0 ;                       //��P0����ƿ�X�ܤW�b�����x�}LED(������)
                LRED1=1 ;
                P0=hwan[woffset+idx*2+1] ;      //���o��ƪ��� woffset+idx*2+1 �����,�ÿ�X��P0
                LRED2=0 ;                       //��P0����ƿ�X�ܤU�b�����x�}LED(������)
                LRED2=1 ;
            }
            else{
                P0=0xff ;                       //�_�h P0 ��X 11111111
                LRED1=0 ;                       //��P0����� 11111111 ��X�ܤW�b�����x�}LED
                LRED1=1 ;                       
                LRED2=0 ;                       //��P0����� 11111111 ��X�ܤU�b�����x�}LED
                LRED2=1 ;                       //�Ͽ�X�����
            }
            if((color== 1) || (color== 2)){     //�Ycolor=1(��)��color=2(��) �h
                P0=hwan[woffset+idx*2] ;        //���o��ƪ��� woffset+idx*2 �����,�ÿ�X��P0
                LGREEN1=0 ;                     //��P0����ƿ�X�ܤW�b�����x�}LED(�����)
                LGREEN1=1 ;
                P0=hwan[woffset+idx*2+1] ;      //���o��ƪ��� woffset+idx*2+1 �����,�ÿ�X��P0
                LGREEN2=0 ;                     //��P0����ƿ�X�ܤU�b�����x�}LED(�����)
                LGREEN2=1 ;                     //           (�Y����M��ⳣ�Q���h�|��X����)
            }
            else{
                P0=0xff ;                       //�_�h P0 ��X 11111111
                LGREEN1=0 ;                     //��P0����� 11111111 ��X�ܤW�b�����x�}LED
                LGREEN1=1 ;
                LGREEN2=0 ;                     //��P0����� 11111111 ��X�ܤU�b�����x�}LED
                LGREEN2=1 ;                     //�Ͽ�X������
            }

            P1 &=0xf0 ;                         //�O P1 = P1 and 11110000
            P1 |=(idx &0xf);                    //�A���o���y�ȿ�X
            CTRLLED=0 ;                         //�Ұʯx�}LED
            Delay100usP(2) ;                    //�I�s����200�L��Ƶ{��
            CTRLLED=1 ;                         //�Ұʯx�}LED
            }
            woffset = interval;                 //�o�@��O�k��������: interval�C���[2 �ҥH�C��woffset�|�h2 �Y�k���@��
           }

           interval+=2;                         //�] interval = interval + 1
           if(interval>=152){                   // �o��Y�令152(32+40+40+40)�N�|�����T���� �]���u�ݲ���̫�@��O"�["���̫�@��Y�i ���e�H184�ɵ����٦�32���Ʀ첾 ��array�w�g�S����ƤF �ҥH���ͶýX
            interval = 0;                       //�] interval ���� 0
            woffset=interval;                   //�A�N interval ���ȵ� woffset
            j++;                                //j �ȥ[ 1
           }
           if(j==1)                             //�Y j ���� 1 �h
             color=1;                           //�]�C�⬰���
           if(j==2)                             //�Y j ���� 2 �h
             color=2;                           //�]�C�⬰����
           if(j==3){                            //�Y j ���� 3 �h
             color=0;                           //�]�C�⬰����
             j=0;                               //�M�� j
           }
        }
}
