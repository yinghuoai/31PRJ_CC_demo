
int fa(char* str )
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
	

	
	
	
	
	return (ch == 'y'||ch == 'Y');
	
	
	
	
}







main()
{
	int a;
	char far* p = (char far*)0xb8000000;
	
	printf("hello world!\n");
	printf("hello\n");
	printf("world\n");
	
	a = fa("use green paint?(y/n)");
	
	if(a)
	{
		for(a = 0; a < 2000; a++)
		{
			p[a*2 + 1] = 2;
			
		}
		
	}
	else
	{
		for(a = 0; a < 2000; a++)
		{
			p[a*2 + 1] = 7;
			
		}
		
		
	}
	
	
	a = fa("clear scr?(y/n)");
	if(a)
	{
		system("cls");
		
		
	}
	
	
}








































