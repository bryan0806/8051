//�ɦW:Dotmtxtw3.C
//�t�X"8*8����I�x�}LED(�@��)��ߪO"
//�b8*8����I�x�}LED�W��ܤW��������r---"�x"
//�@�~:�令�U��
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sDelay.h"
unsigned char dai[]={0xFF,0xEF,0xC1,0xA5,0x65,0xC1,0xEF,0xFF}; //�x

Delay3ms()        //���� 3 �@���Ƶ{��
{
  Delay1ms() ;    //�I�s���� 1 �@��
  Delay1ms() ;    //�I�s���� 1 �@��
  Delay1ms() ;    //�I�s���� 1 �@��
}
main()                  //�D�{��
{
  int i,j;		//�ŧi����ܼ� i,j
  unsigned char ch,com;	//�ŧi�L���Ʀr���ܼ� ch,com

  for(;;){
    com=0x80;		  //�O com = 0x80
    for(i=0;i<8;i++){	  //�@�ϥ�8�����
        for(j=0;j<8;j++){ //���y�u�@��8��
            P1=0xff;	  //�ϯx�}LED������
	    P0=dai[j];	  //���o��ƪ��� idx �����,�ÿ�X�� P0
            P1=~com;	  //�t�XP1��ƿ�X,�Ұʦ��}(P1.7 ~ P1.0)
            com >>=1;	  //�k���@���}
            Delay3ms();	  //�I�s���� 3 �@��Ƶ{��
        }
	for(j=0;j<8;j++){ //�N�r�����C�@����Ƨ�"�U��"(�k��)���줸
	    ch=dai[j];
	    if ( (ch&0x01)==0x01 ) { //�P�_�̥k�� ��� �Y��1
		ch=ch>>1; //�k��
		ch=ch|0x80;  // �����ܦ�10000000
		} else ch=ch>>1;
	    dai[j]=ch;
	}
	com=0x80;	  //�O com = 0x80 ,���s�A��ܤ@��
    }
  }
}
