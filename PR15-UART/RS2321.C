//  �ɦW:Rs2321.C
//  �t�X"RS232��ߪO"
//  �ǰe�@�r�ꬰ"HELLO!!"
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>	    //8051��l�]�w
code char mes[]="Hello!!" ; //���@�r����

main()
{
 char *s ;	//�w�q���Цr���ܼƬ�s
 SM0=0 ; SM1=1;	//SM1=1,�]�w��C�ǿ鬰�Ҧ�1
 TMOD=0x20 ;	//TMOD=20H,�]TIMER1��8�줸�۰ʸ��J�w�ɾ�
 TH1=TL1=0xfd;	//TH1=TL1=0FDH,�]�w�j�v��9600bps
 TR1=1 ;	//TR1=1,�}�l�p��
 for(s=mes;*s!='\0';)	
   {	//s=mes,��mes����}��s;�Y����'\0'�h�~��¶
   SBUF=*s++ ;		//SBUF=s���U�@��}�����
   while(TI==0) ;	//�YTI=0���ܥ��ǧ�,�ݵ���
   TI=0 ;		//�ǰe����M�����U�@���
   }
 for(;;) ;		//���d��a
}

