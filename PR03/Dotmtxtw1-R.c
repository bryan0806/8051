//�ɦW:Dotmtxtw1.C
//�t�X"8*8����I�x�}LED(�@��)��ߪO"
//�b8*8����I�x�}LED�W��ܤ���r�å���---"�x-��"
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sDelay.h"
unsigned char code dai[]={0xFF,0xEF,0xC1,0xA5,0x65,0xC1,0xEF,0xFF, //�x
                          0xFF,0xC7,0xD7,0x01,0xD7,0xC7,0xFF,0xFF, //��
                         };   


Delay3ms()              //���� 3 �@���Ƶ{��
{
        Delay1ms() ;    //�I�s���� 1 �@��
        Delay1ms() ;    //�I�s���� 1 �@��
        Delay1ms() ;    //�I�s���� 1 �@��
}
main()                  //�D�{��
{
      int i,j;				//�ŧi����ܼ� i,j
      unsigned char com,idx,ids;	//�ŧi�L���Ʀr���ܼ� com,idx

      for(;;){
        com=0x80;		//�O com = 0x80
        ids=0;			//�O ids = 0
        idx=0;			//�O idx = 0
        for(i=0;i<16;i++){	//�@�ϥ�8�����
          for(j=0;j<8;j++){	//���y�u�@��8��
            P1=0xff;		//�ϯx�}LED������
            P0=dai[(idx++)%16];	//���o��ƪ��� idx �����,�ÿ�X�� P0
            P1=~com;		//�t�XP1��ƿ�X,�Ұʦ��}(P1.7 ~ P1.0)
            com >>=1;		//�k���@���}
            Delay3ms();		//�I�s���� 3 �@��Ƶ{��
          }
          com=0x80;		//�O com = 0x80 ,���s�A��ܤ@��
          ids --;		//�@�ӹϧΦ� 8 �� byte
          idx = ids%16; 	//���U�@���ϧθ��
         }
        }
}


