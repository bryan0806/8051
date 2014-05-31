//  �ɦW:Timer.C
//  �t�X"TIMER/COUNTER��ߪO"
//  �Q�έp�ɤ��_���Ͷg���ʤ��ʧ@(���ۻP�k��)
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sdelay.h"
char Count,i,k ;
void timer() ;

main()
{
 char j ;
 P0=Count=0 ;	//LED���t
 TMOD=0x011 ;	//T1���p�ɾ�,T0���p�ɾ�
 TH0=0xe0 ;	//TH0��ȳ]�w
 //TL1=0 ;	//TL1��ȳ]�w this line can be skipped because in the below , it was changed immediately
 //TL0=0 ;	//TL0��ȳ]�w*/ this line can be skipped because in the below , it was changed immediately
 TH0=(0xffff-5000)/256;	//TH0=0xD8
 TL0=(0xffff-5000)%256 ; 
 TH1=(0xffff-5000)/256;	//TH0=0xD8
 TL1=(0xffff-5000)%256 ; 
 ET0=1 ;	//�p�ɭp�ƾ�0�P��
 ET1=1 ;	//�p�ɭp�ƾ�1�P��
 TR0=1 ;	//�p�ɾ�0�}�l�p��
 TR1=1 ;	//�p�ɾ�1�}�l�p��
 EA=1 ;	//�P�त�_�\��
 for(;;) ;	//���d��a,���ݤ��_
}

void timer0(void) interrupt 1
{
 char j,i ;
 j=1 ;
 for(i=0;i<8;i++)
 {
 P0=j ;		//��X��LED���
 j<<=1 ;	//j �����@��
 Delay100ms();	//����100�@��
 }
 TH0=(0xffff-5000)/256;	//TH0=0xD8
 TL0=(0xffff-5000)%256 ; 
 P0=0 ;			//�M��P0
}

void timer1(void) interrupt 3
{
 unsigned char j,i ;
 j=0x80 ;
 for(i=0;i<8;i++)
 {
 P0=j ;	//��X��LED���
 j=j>>1;
 Delay100ms() ;	//����100�@��
 }                         
 TH1=(0xffff-5000)/256 ;//��_TH1��
 TL1=(0xffff-5000)%256 ;//��_TL1�� 
 P0=0 ;                 //�M��P0
}

