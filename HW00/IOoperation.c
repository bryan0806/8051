// �Ĥ@�ӧ@�~:����L��J�@��16�i��(00~ff)�Ʀr�A�i��U�����B�⵲�G��X
/* 1.�M���̥k�G�줸��0 ��l�줸�O������
   2.�]�w�̥k�G�줸��1 ��l�줸�O������
   3.�Ϭ۳̥k�G�줸 ��l�줸�O������
   4.b7 b6 b5 b4 b3' 1 0 0
   5. �Yb3 b2 b1 b0����0 �h���"�D0"�_�h���"��0":
*/


#include <stdio.h>


int main(void){
	
	/*int x = 100;
    printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
	printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);
	*/
	int oct;
	
	printf("please input a hexadecimal number:");
	scanf("%x",&oct);
	printf("you enter %d\n",oct);
	printf("keep all but last 2 are 0 : %x\n",oct&252);
	printf("set up last 2 are 1 and keep others unchange: %x\n",oct|3);
	printf("reverse last 2 are 1 and keep others unchange: %x\n",oct^3);
	printf("b7b6b5b4b3100: %x\n",((oct^8)|4)&252); // first or operation with 00000100, then and operation with 11111100
	if((oct&0x0f)==0){
		printf("��0\n");
	}else{
		printf("�D0\n");
	}
	
	return 0;
}
