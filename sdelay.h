// Simulator 專用副程式
// 進入專用副程式後, 禁止所有中斷,計時器等工作,
// CPU處閒置狀態直到等待時間到達,才離開專用副程式. 

#ifndef SIMULATOR_DELAY_ROUTINE
#define SIMULATOR_DELAY_ROUTINE
#ifdef DUMMY_DELAY
void Delay100us (void)
{
	ACC = 1;
	F0  = 1;
	F0  = 1;
	F0  = 1;
}

void Delay1ms (void)
{
	ACC = 2;
	F0  = 1;
	F0  = 1;
	F0  = 1;
}

void Delay10ms (void)
{
	ACC = 3;
	F0  = 1;
	F0  = 1;
	F0  = 1;
}

void Delay100ms (void)
{
	ACC = 4;
	F0  = 1;
	F0  = 1;
	F0  = 1;
}

void Delay1s (void)
{
	ACC = 5;
	F0  = 1;
	F0  = 1;
	F0  = 1;
}

void Delay10s (void)
{
	ACC = 6;
	F0  = 1;
	F0  = 1;
	F0  = 1;
}

void Delay100s (void)
{
	ACC = 7;
	F0  = 1;
	F0  = 1;
	F0  = 1;
}

void Delay100usP(unsigned char cnt)
{
	F0  = 1;
	F0  = 1;
	F0  = 1;
}

#else
void Delay100us (void)
{
	char i;
	for(i=0; i<31; i++);
	i++;	
}

void Delay1ms (void)
{
	int i ;
	char  j;
	for(i=0 ; i < 124 ;i++) ;
	j++ ;
}

void Delay10ms (void)
{
	char i;
	for(i=0; i < 10; i++){
	    Delay1ms();
	}
}

void Delay100ms (void)
{
	long i ;
	char j ;
	for(i=0 ; i < 709 ; i++) ;  
	for(j=0 ; j < 5 ;j++) ;
	j++ ;
	j++ ;
}

void Delay1s (void)
{
	char i;
	for(i=0; i < 10; i++){
	    Delay100ms();
	}
}

void Delay10s (void)
{
	char i;
	for(i=0; i < 10; i++){
	    Delay1s();
	}
}

void Delay100s (void)
{
	char i;
	for(i=0; i < 10; i++){
	    Delay10s();
	}
}

void Delay100usP(unsigned char cnt)
{
	char i;

	while( cnt != 0 ){
	    for(i=0; i<31; i++);
	    i++;
	    cnt--;
	}
}
#endif
#endif
