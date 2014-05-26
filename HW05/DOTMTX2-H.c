//   �ɦW:DOTMTX2.C
//   �t�X"8*8�m���I�x�}LED��ߪO"
//   �b8*8�m���I�x�}LED�W�̧���ܤT���C�⪺����r---"�j"
//
//      ��m���� P0 P2
//                0  0        ��
//                0  1        ��
//                1  0        ��
//                1  1        ���G
// �@�~�令 �@�Ӥj ���H�T���C��զ� 2��-3��-2��

#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sDelay.h"
unsigned char code dai[]= { 0xdd,0xdb,0xd7,0x0f,0xd7,0xdb,0xdd,0xff} ;  //�إ߸�ƪ� dai
#define BASEINT 10                      //���� �w�q BASEINT = 25
#define INTERVAL1       BASEINT*1       //���� �w�q INTERVAL1 = BASEINT * 1 = 25 * 1 = 25
#define INTERVAL2       BASEINT*2       //���� �w�q INTERVAL2 = BASEINT * 2 = 25 * 2 = 50
#define INTERVAL3       BASEINT*3       //���� �w�q INTERVAL3 = BASEINT * 3 = 25 * 3 = 75

delay3ms()                              //�I�s���� 3 �@���Ƶ{��
{
        Delay1ms() ;            //�I�s���� 1 �@��Ƶ{��
        Delay1ms() ;            //�I�s���� 1 �@��Ƶ{��
        Delay1ms() ;            //�I�s���� 1 �@��Ƶ{��
}
main()
{       char idx ;              //�ŧi�r���ܼ� idx
        unsigned char com ;     //�ŧi�L���Ʀr���ܼ� com
        unsigned int interval ; //�ŧi�L���ƾ���ܼ� interval
        unsigned char color ;   //�ŧi�L���Ʀr���ܼ� color ,color=0(��)color=1(��),color=2(��)
        idx=0 ;                 //�O idx = 0
        com=0x80 ;              //�O com = 0x80
        interval=0 ;            //�O interval = 0
        color=0 ;               //�O color = 0
        for( ; ;){
            P1=0xff ;                           //�ϯx�}LED������
            if((color== 0) || (color== 2)){     //�Ycolor=0(��)��color=2(��) �h
                P0=dai[idx] ;                   //���o��ƪ��� idx �����,�ÿ�X��P0
            }
            else{
                P0=0xff ;                       //�_�h P0 ��X 11111111
            }
            if((color == 1) || (color== 2)){    //�Ycolor=1(��)��color=2(��) �h
                P2=dai[idx] ;                   //���o��ƪ��� idx �����,�ÿ�X��P2
            }
            else{
                P2=0xff ;                       //�_�h P2 ��X 11111111
            }
            idx++ ;                             //idx �[ 1,�H���o�U�@�����
            P1=~com ;                           //�t�XP0��ƿ�X,�Ұʦ��}(P1.7 ~ P1.0)
            com >>=1 ;                          //�k���@���}
                                    
                                
                                  
                                
            
                                                //����ɶ�
            if(idx ==  2){         //idx ��2�� ���C��
                color=1 ;                       //�] color = 1 �ഫ�����
            }
            else if(idx == 5){     //idx ��5�� �A���C��
                color=2 ;                       //�] color = 2 �ഫ������
            }
            else if(idx == 8){     //idx ��8�� ���C��
                idx=0 ;                    //�] interval = 0 ���s�p�⩵��ɶ�
                color=0 ;         //�C��^�����
                com=0x80 ;      //com �^��Ĥ@��
            }
            delay3ms() ;                        //�I�s���� 3 �@��Ƶ{��
        }
}
