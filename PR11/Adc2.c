//�ɦW:ADC2.C
//�t�X"ADC0804��ߪO"
//Ū��ADC0804������q����(�ĥάd�ߤ覡�ӦP�B),
//�ñN����ܩ�8��LED�W
#pragma oe db pw(80) SM SB CD
#include <reg51.h>	//8051��l�]�w
sbit ADCRD=P1^0 ;	//�]�wP1.0���}�W�٬�ADCRD
sbit ADCWR=P1^1 ;	//�]�wP1.1���}�W�٬�ADCWR
sbit ADCINTR=P3^2 ;	//�]�wP3.2���}�W�٬�ADCINTR

main()
{
  for(;;)
  {		//start ADC
  ADCWR=0 ;	//�]�wADCWR(�g�J)�H���H�Ұ�ADC�ഫ
  ADCWR=1 ;	//�M��ADCWR(�g�J)�H��
  while(ADCINTR) ;	//�YADCINTR=0�h��ܤw�ഫ����
  ADCRD=0 ;	//�]�wADCRD(Ū�X)�H���HŪ���ഫ���G��
  P2=P0 ;	//P0��J���Ȱe��P2��LED��ܼƦ��
  ADCRD=1 ;	//�M��ADCRD(Ū�X)�H��
     }
}
