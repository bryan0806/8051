//  �ɦW:INT0.C
//  �t�X"���_��ߪO"
//  INT0�����W�p��
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>	//8051��l�]�w
char Count ;		//�r����Ƭ�Count(���ϰ��ܼ�)

 main()
{
        P0=Count=0 ;	//LED���t
        IT0=1 ;		//�~�����_0,�]���t�tĲ�o
        EA=1;	//�P�त�_�\��
        EX0=1 ;	//�~�����_0�P��
        for(;;) ;	//���ݤ��_
}

 void external0(void) interrupt 0
{
        Count++ ;	//Count=Count+1,�ּW�p��
        P0=Count ;	//��X��LED���
}