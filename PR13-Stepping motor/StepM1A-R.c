//  �ɦW:StepM1A.C
//  �γ�ۿE�Ϫ��覡,�ϨB�i���F����n��
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>	//8051��l�]�w
#include "sDelay.h"	//����禡�w
#define n   10		//�w�qn=10�B

main()
{//�w�qpp���L���t�r���ܼƨ�Ȭ�0x1
 unsigned char pp=0x8 ;	
 int Step ;	//�w�qStep������ܼ�
 for(Step=0;Step<(n+1);Step++)   
 {//�YStep<n+1,�h�~�����j��
 P0=pp ;	//���ʨB�i���F
 pp>>=1 ;	//�V���ۤ@��
 if(pp==0x00)	//�Ypp=0x10�h
 pp=0x8 ;	//�٭���
 Delay10ms() ;	//�I�s����10�@��
 }
}
