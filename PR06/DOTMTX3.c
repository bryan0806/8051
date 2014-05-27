//�ɦW:DOTMTX3.C
//�t�X"4��8*8�m���I�x�}LED��ߪO"
//�b16*16�m���I�x�}LED�W�̧���ܤT���C��(��-->��-->��,���y)������r---"�w"
//
//��m���� P0 P2
//        0  0        ��
//        0  1        ��
//        1  0        ��
//        1  1        ���G
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sDelay.h"

//�w���r����ƪ� hwan
unsigned char code hwan[]= { 
        0xFF,0xFF,0xDF,0xEF,0xD1,0x9F,0x84,0x00,
        0xD1,0x55,0xDE,0x55,xD1,0x01,0x85,0x55,
        0xD1,0x55,0xDE,0xFE,0xF9,0xF9,0x87,0xE7,
        0xB4,0x1F,0xF7,0xE7,0xF5,0xF9,0xE3,0xFE,
} ;

sbit CTRLLED= P2^0 ;            //�w�q CTRLLED ���� P2.0
sbit LRED1=P1^4 ;               //�w�q LRED1 ���� P1.4
sbit LGREEN1=P1^5 ;             //�w�q LGREEN1 ���� P1.5
sbit LRED2=P1^6 ;               //�w�q LRED2 ���� P1.6
sbit LGREEN2=P1^7 ;             //�w�q LGREEN2 ���� P1.7
#define BASEINT 25              //���� �w�q BASEINT = 25
#define INTERVAL1  BASEINT*1    //���� �w�q INTERVAL1 = BASEINT * 1 = 25 * 1 = 25
#define INTERVAL2  BASEINT*2    //���� �w�q INTERVAL2 = BASEINT * 2 = 25 * 2 = 50
#define INTERVAL3  BASEINT*3    //���� �w�q INTERVAL3 = BASEINT * 3 = 25 * 3 = 75

main()
{
        char idx ;              //�ŧi�r���ܼ� idx
        unsigned int interval ; //�ŧi�L���ƾ���ܼ� interval
        unsigned char color ;   //�ŧi�L���Ʀr���ܼ� color ,color=0(��)color=1(��),color=2(��)
        idx=0 ;                 //�O idx = 0
        interval=0 ;            //�O interval = 0
        color=0 ;               //�O color = 0

        for( ; ;){
            CTRLLED=1 ;                         //�����Ҧ��x�}LED
            if((color== 0) || (color== 2)){     //�Ycolor=0(��)��color=2(��) �h
                P0=hwan[idx*2] ;                //���o��ƪ��� idx*2 �����,�ÿ�X��P0
                LRED1=0 ;                       //��P0����ƿ�X�ܤW�b�����x�}LED(������)
                LRED1=1 ;
                P0=hwan[idx*2+1] ;              //���o��ƪ��� idx*2+1 �����,�ÿ�X��P0
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
                P0=hwan[idx*2] ;                //���o��ƪ��� idx*2 �����,�ÿ�X��P0
                LGREEN1=0 ;                     //��P0����ƿ�X�ܤW�b�����x�}LED(�����)
                LGREEN1=1 ;
                P0=hwan[idx*2+1] ;              //���o��ƪ��� idx*2 �����,�ÿ�X��P0
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
            P1 |=idx ;                          //�A���o���y�ȿ�X
            CTRLLED=0 ;                         //�Ұʯx�}LED
            idx++ ;                             //�O idx = idx + 1
            if(idx >=16){                       //�Y idx �j�󵥩� 16 (�x�}�H��ܤ@��),�h
                interval++ ;                    //�] interval = interval + 1
                idx=0 ;                         //�O idx = 0 ,���s�b��ܤ@��
            }
                                                //����ɶ�
            if(interval ==  INTERVAL3){         //�p�G interval ���� INTERVAL3(75) (�A���� 25 * 1ms) �h
                interval=0 ;                    //�] interval = 0 ���s�p�⩵��ɶ�
                color=0 ;                       //�] color = 0 �ഫ������
            }
            else if(interval == INTERVAL2){     //�_�h�p�G interval ���� INTERVAL2(50) (�A���� 25 * 1ms) �h
                color=2 ;                       //�] color = 2 �ഫ������
            }
            else if(interval == INTERVAL1){     //�_�h�p�G interval ���� INTERVAL1(25) (���� 25 * 1ms) �h
                color=1 ;                       //�] color = 1 �ഫ�����
            }
            Delay1ms() ;                        //�I�s���� 1 �@��Ƶ{��
        }
}
