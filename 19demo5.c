#include "19demo4.h"


char a[20]= "hello world";

int put(EleType* dp)
{
	printf("%c",*dp);
	
	return 1;
	
}

void show(List* lp)
{
	TraverseList(lp,put);
	printf("\n");
	
	
}


main()
{
	List* lp;
	int i;
	
	lp = CreateList();
	
	if(!lp)
	{
		printf("error");
		
		return;
	}
	
	for(i= 0;a[i];i++)
	{
		ListAppend(lp,a[i]);
		
		
	}
	
	show(lp);
	
	ClearList(lp);
	show(lp);
	
	ListInsert(lp,1,'i');
	show(lp);


	ListInsert(lp,1,'h');

	show(lp);
	
	
}






























