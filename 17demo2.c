void f1();
void f2();
void ask(char* chp,void (*fp)());

main()
{
	
	printf("hello world!\n");
	printf("hello\n");
	printf("world\n");
	
	ask("use green paint?(y/n)",f1);
	ask("clear scr?(y/n)",f2);
	
	
	
}

void f1()
{
	int a;
	char far* p = (char far*)0xb8000000;
	for(a = 0 ; a < 2000; a++)
	{
		p[a*2 + 1] = 2;
		
		
	}
	
}

void f2()
{
	system("cls");
	
	
	
}


void ask(char* str,void (*fp)())
{
	
	int n;
	int a;
	int row;
	int col;
	char far* scr = (char far*)0xb8000000;
	
	char* buf;
	char ch;
	
	n = strlen(str);
	
	if(n/80)
	{
		row = (25 - (n/80 + 1))/2;
		col = 3;
		
		
	}
	else
	{
		row = 12;
		col = (80 - (n%80))/2;
		
		
	}
	
	buf = (char*)malloc(n*2);
	
	for(a = 0;a < n*2;a++)
	{
		buf[a] = scr[  (row - 1)*160 +(col - 1)*2 + a ];
		
		
	}
	
	for(a = 0;a <n;a++)
	{
		scr[  (row - 1)*160 + (col - 1 + a)*2 ] = str[a];
		scr[  (row - 1)*160 + (col - 1 + a)*2 + 1 ] = 2;
		
	}
	
	while(8)
	{
		ch = getch();
		if( ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N' )
			break;
		
		
		
	}
	
	for(a = 0; a < n*2; a++)
	{
		scr[ (row - 1)*160 + (col - 1)*2 + a ] = buf[a];
		
	}
	
	

	if( ch == 'y' || ch == 'Y' )
	{
		fp();
		
	}
	

	
	

}

























