//  �ɦW:Rs2323.C
//  �t�X"RS232��ߪO"
//  ����Ū����J��ƨöǰe
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>	//8051��l�]�w
char buf[10] ;	//�]�w�r��e�q���Q�Ӧr��
char idx,c ;	//�w�q�r���ܼ�idx,c

main()
{
 idx=0 ;	//�����k�s
 SM0=0 ; SM1=1; //�]�w��C�ǿ鬰�Ҧ�1
 TMOD=0x20 ;	//�]�wTIMER1��8�줸�۰ʸ��J�w�ɾ�
 TH1=TL1=0xfd ;	//�]�w�j�v��9600BPS
 TR1=1 ;	//�}�l�p��
 REN=1 ;	//��C�����P��
 for(;;)
  {
  while(RI==0);	//�YRI=0��ܥ�����,�ݵ���
  RI=0 ;	//��������M�����U�@���
  c=SBUF ;	//��ұ�������Ʀs�Jc��
  SBUF=c ;	//��c����Ƶ�SBUF
  while(TI==0);	//�YTI=0��ܥ��ǧ�,�ݵ���
  TI=0 ;	//�ǰe����M�����U�@���
  }
}
