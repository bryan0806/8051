//  檔名:E93C462.C
//  配合"EEPROM 93C46實習板"
//  寫入一數值(5678h)到93C46的位址00
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
sbit EEPROMCS=P0 ^0 ;
sbit EEPROMSK=P0 ^1 ;
sbit EEPROMDI=P0 ^2 ;
sbit EEPROMDO=P0 ^3 ;
#define CLOCK  EEPROMSK=0; EEPROMSK=1;
#define SEND(DI)  EEPROMDI=DI; CLOCK;
main()
{
 unsigned int Data ;
 unsigned char i ;
 P0=0xff ;
 EEPROMCS=0 ;	// 設定 CS,SK 到初值	
 EEPROMSK=0 ;
 EEPROMCS=1 ;	//使寫入致能	
 SEND(1) ;	//啟始位元	
 SEND(0);SEND(0);	//指令00
 SEND(1);SEND(1);	//次指令11
 for(i=0;i<4;i++) {	//4-'X' Bit 
 SEND(0) ;
 }	
 EEPROMCS=0 ;
 // 寫入一數值(5678h)到93C46的位址(00) 
 EEPROMCS=1 ;
 SEND(1) ;		// 啟始位元	
 SEND(0) ; SEND(1) ;	// 指令01
 for(i=0;i<6;i++){	// 位址000000
	    SEND(0) ;
	}
 Data=0x5678 ;		// 送出資料
 for(i=0 ; i < 16 ; i++){
    if(Data & 0x8000){
	SEND(1) ;
    }
    else {
	SEND(0) ;
    }
    Data <<=1 ;
 }
 EEPROMCS=0 ;	//等待READY 
 EEPROMCS=1 ;
 while(!EEPROMDO){
    CLOCK ;
 }
 
 EEPROMCS=1 ;	// 使寫入除能
 SEND(1) ;	// 啟始位元	
 SEND(0);SEND(0); //指令00	
 SEND(0) ; SEND(0) ;//次指令00
 for(i=0 ; i < 4 ; i++){
    SEND(0) ;
 }
 EEPROMCS=0 ;
 for(;;) ;
}
