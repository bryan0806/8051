//  �ɦW:StepM5.C
//  �Υb�B�E�Ϫ��覡,�ϨB�i���F����n��
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>	//8051��l�]�w
#include "sDelay.h"	//����禡�w
#define n   10		//�w�qn=10�B
char code pp[]={ 0x1,0x3,0x2,0x6, //�b�B�E�ϱ��ʽu�����
                 0x4,0xC,0x8,0x9 } ;
main()
{
 int Step ;		//�w�qStep������ܼ�
 char idx_pp=7 ;	//�w�qidx_pp���r���ܼƨ�ƭȬ�0
 for(Step=0;Step<(n*2+1);Step++) 
 {//�YStep<n*2+1,�h�~�����j��
 P0=pp[idx_pp--]; //P0=idx_pp�ҫ���pp�����,���ʨB�i���F
 if(idx_pp==-1)	//�Yidx_pp=8,�h
    idx_pp=7 ;	//�٭���
 Delay1s() ;	//�I�s����100�@��
 }
}
