//  �ɦW:ADC3.C
//  �t�X"ADC0804��ߪO"
//  Ū��ADC0804������q����(�ĥΤ��_�覡�ӦP�B)
//  ,�ñN����ܩ�8��LED�W
#pragma oe db pw(80) SM SB CD
#include <reg51.h>	//8051��l�]�w
sbit ADCRD=P1^0 ;	//�]�wP1.0���}�W�٬�ADCRD
sbit ADCWR=P1^1 ;	//�]�wP1.1���}�W�٬�ADCWR

 main()
{
  EA=1 ;	//�P�त�_�\��
  IT0=1 ;	//�����t�tĲ�o�ʧ@
  EX0=1 ;	//�Ұ�INT0
		//start first ADC
  ADCWR=0 ;	//�]�wADCWR(�g�J)�H���H�Ұ�ADC�ഫ
  ADCWR=1 ;	//�M��ADCWR(�g�J)�H��
  for(;;) ;	//���ݤ��_
}

 void external0(void) interrupt 0
{
  ADCRD=0 ;	//�]�wADCRD(Ū�X)�H���HŪ���ഫ���G��
  P2=P0 ;	//P0��J���Ȱe��P2��LED��ܼƦ��
  ADCRD=1 ;	//�M��ADCRD(Ū�X)�H��
		//start next ADC
  ADCWR=0 ;	//�]�wADCWR(�g�J)�H���H�Ұ�ADC�ഫ
  ADCWR=1 ;	//�M��ADCWR(�g�J)�H��
}
