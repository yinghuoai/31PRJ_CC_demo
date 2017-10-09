

typedef union{

	void (*setshow)();
	int  (*setret)(int);
	int  (*setadd)(int,int);

}funcType;




typedef struct c{

	char* text;
	char key;
	int can;
	
	funcType choice;


}ItemType;



void menu(ItemType* ,int);



char str1[3][20];









void menu(ItemType* item ,int n)
{
	
	 
	int a,b,i;
	char ch;
	
	for(a = 0;a < n;a++)
	{
		b =strlen(item[a].text);
		
		if(b > 20 || b <0)
		{
			printf("error");
			return;
			
			
		}
		
		printf("%s\n",item[a].text);
		
	}
	
	
	
	do
	{
	
		ch = getch();
		
		for(a = 0;item[a].key != ch && a < n ;a++);
		
	
	}while(a == n);
	
	
	
	for( i = 0;i<item[a].can;i++ )
	{
		gets(str1[i]);
		
		
		
	}
	
	


	
	printf("--------------------\n");

	

	switch(item[a].can)
	{
		case 1:
		
			printf("%d",item[a].choice.setret(atoi(str1[0])));
			break;
		case 2:
		
			printf("%d",item[a].choice.setadd(atoi(str1[0]),atoi(str1[1])) );
			break;
			
		case 0:	
		default:
			
			item[a].choice.setshow() ;
			break;
			
		
		
	}
    	
	
	
	
	
}

	















































