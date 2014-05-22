// 第一個作業:由鍵盤輸入一個16進位(00~ff)數字，進行下面的運算結果輸出
/* 1.清除最右二位元為0 其餘位元保持不變
   2.設定最右二位元為1 其餘位元保持不變
   3.反相最右二位元 其餘位元保持不變
   4.b7 b6 b5 b4 b3' 1 0 0
   5. 若b3 b2 b1 b0不為0 則顯示"非0"否則顯示"為0":
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
		printf("為0\n");
	}else{
		printf("非0\n");
	}
	
	return 0;
}
