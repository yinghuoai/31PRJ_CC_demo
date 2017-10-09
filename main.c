
#include "13demo6.h"

int a;

void menu(manage* cpfmanage)    
{
	
	 
	int b,i;
	char ch;
	
	for(a = 0;a < cpfmanage->fnum;a++)
	{
		b =strlen(cpfmanage->item[a].text);
		
		if(b > 20 || b <0)
		{
			printf("error");
			return;
			
			
		}
		
		printf("%s\n",cpfmanage->item[a].text);
		
	}
	
	
	
	do
	{
	
		ch = getch();
		
		for(a = 0;cpfmanage->item[a].key != ch && a < cpfmanage->fnum ;a++);
		
	
	}while(a == cpfmanage->fnum);
	
	system("cls");
	printf("\n\n");
	
	printf("the function -- %s    --  is working.........\n\n\n\n\n",cpfmanage->item[a].text);
	
	
	for( i = 0;i<cpfmanage->item[a].pnum;i++ )
	{
		printf("NO.%d input: \n",i+1);
		
		gets(str1[i]);
		

		
	}
	
	


	
	printf("--------------------\n");

	

	
	
	

	
}












void init()
{
	menu(&fmanage);

	
}



main()
{
	init();
	
	change();
	
}















