//  �ɦW:KEY3.C
//  �t�X"4*5��L��ߪO"
//  ²����L���˳]�p
// �@�~ 2 : �Ʀr�q�W�U���� �ҥH �̤W�@�Ƭ�16 17 18 19 -> 12 13 14 15 ->
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sDelay.h"
void delay20ms() ;		//�ϥΨ쩵�� 20 �@��Ƶ{��

unsigned char code IdxCol[]= {	//���������
        0 , 1 , 0 , 2 ,
        0 , 1 , 0 , 3 ,
        0 , 1 , 0 , 2 ,
        0 , 1 , 0 , 4 } ; 	// �u�n��o��Y�i

main() {			//�D�{��
 char row ;                    //�ŧi�r���ܼ� row
 char keyflag ;                //�ŧi�r���ܼ� keyflag
 char tP1 ;                    //�ŧi�r���ܼ� tP1
 P0=0 ;                        //��LED������
 for(;;) {    
    do {      
	for(P1=tP1=0xf,row=0,keyflag=0;row<5;row++) {               
	//��l��P1=tP1=0xfe , row=keyflag=0. �Y row �p�� 5 �h row �[ 1
	if((P2&0xf)!=0xf) { //�YP2 and 0xf������0xf��ܦ�������U�h
	  keyflag=1 ;	//�O keyflag=1
	  break ;	//�ø���for�j��
	}		//�YP2 and 0xf����0xf�h�~�򩹤U
	tP1>>=1 ;	//tP1�k���@�Ӧ줸(���y�X)
	//tP1+=1 ;	//
	tP1= tP1 | 0x10; // �j��ɥ��誺1
	P1=tP1 ;	//�N���y�X�e�X
	}
	if(keyflag==1) {	//�Y����X�е��� 1 ��ܦ�������U,�h	  
	    delay20ms() ;	//�I�s���� 20 �@��Ƶ{��(�����u��)
	    if((P2&0xf)==0xf)	//�A�@���T�w�O�_��������U,�Y�L������U�h
	    keyflag=0 ;		//�O keyflag = 0 ��ܬO���T
	    }
	} while(keyflag==0) ;	//��T�w��������U�ɫh�����j�驹�U�~��

	P0=row*4+IdxCol[P2&0xf];//���orow*4�[�W���������,�ÿ�X�� P0
	do {
	   while((P2&0xf)!=0xf);//�P�_����O�_��},�Y�S��}�h���b��a,
				//�Y��}�h���U�~��
	   delay20ms() ;	//�I�s���� 20 �@��Ƶ{��(�����u��)
	} while((P2&0xf)!=0xf);	//�A�@���T�w����O�_��},�Y����S��}�h                                    
    }//�^�W�@�� do �~��,�Y�����}�h�~�����
}
void delay20ms() {	//���� 20 �@���Ƶ{��
        Delay10ms() ;	//�I�s���� 10 �@��Ƶ{��
        Delay10ms() ;	//�I�s���� 10 �@��Ƶ{��
}
