//  �ɦW:INT0.C
//  �t�X"���_��ߪO"
//  INT0�����W�p��
//�m��: �令 ���_1 �@�ۦP���Ʊ�
#pragma oe db pw(80) SM SB CD
#include <reg51.h>	//8051��l�]�w
char Count ;		//�r����Ƭ�Count(���ϰ��ܼ�)

 main()
{
        P0=Count=0 ;	//LED���t
        IT1=1 ;		//�~�����_1,�]���t�tĲ�o
        EA=1;	//�P�त�_�\��
        EX1=1 ;	//�~�����_1�P��
        for(;;) ;	//���ݤ��_
}

 void external1(void) interrupt 2 // �`�N�~�����_1���s���O "2"
{
        Count++ ;	//Count=Count+1,�ּW�p��
        P0=Count ;	//��X��LED���
}
