//   �ɦW:SSLED3.C
//   �t�X"4�ӤC�q��LED(�@��)��ߪO"
//   �b2�ӤC�q��LED�W��ܻ��W�Ʀr00~99;�䱽�˶��j��100ms
//   �@�~: �ק糧�{���A�Ϩ䵲�G���C�q��ܼƦr��0123->4567->89Ab->CdEF->0123...
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sDelay.h"
unsigned char code sstbl[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};      //�إ߸�ƪ� sstbl
unsigned char code loc[]={ 0xf7,0xfb,0xfd,0xfe} ;                                    //�إ߸�ƪ� loc
main()
{
        char i,j ;                //�ŧi�r���ܼ� i (�N��n��ܤ��ƭ�)
        i=0 ;                   //�O i ���� 0
		j=0;                // for timer
		while(1){
        while(1){
            i = i%16;
			P1=0xff;
			j++;
            P1=0xf7 ;          //turn on left most digit
            P0=sstbl[i];     //display 0
			P1=0xff;         // remember to turn all off to display correctly !!!

			P0=sstbl[i+1];		// display 1
			P1=0xfb;           //turn on left second digit
            P1=0xff;          // remember to turn all off to display correctly !!!
			j++;
            P0=sstbl[i+2];    //display 2
			P1=0xfd ;          //turn on left third digit
            P1=0xff;         // remember to turn all off to display correctly !!!

            P0=sstbl[i+3];     //display 3
			P1=0xfe;			//turn on most right digit
            Delay10ms() ;     //�I�s���� 100 �@��Ƶ{��
			if(j>100) break;
			j++;
        }
		j=0;
		i=i+4;

		}
}


