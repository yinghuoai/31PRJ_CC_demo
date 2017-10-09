#include "19demo4.h"


char a[20] = "hello world!";

void showlist(List*);

int putelement(EleType*);



main()
{
	List* lp;
	int n;
	
	
	lp = CreateList();
	
	if(!lp)
	{
		printf("Create?\n");
		return;
		
	}
	
	for(n = 0; a[n] ; n++)
	{
		ListAppend(lp,a[n]);
		
		
	}
	
	showlist(lp);
	
	ListInsert(lp,1,'h');
	showlist(lp);
	
	
	ListInsert(lp,8,'a');
	showlist(lp);
	
	
	ListDelete(lp,1);
	showlist(lp);
	
	ListDelete(lp,7);
	showlist(lp);
	
	ClearList(lp);
	showlist(lp);
	
	
		ListInsert(lp,1,'h');
	showlist(lp);
	
			ListInsert(lp,1,'i');
	showlist(lp);
}



void showlist(List* lp)
{
	TraverseList(lp,putelement);
	printf("\n");
	
	
}

int putelement(EleType* data)
{
	
	printf("%c",*data);
	return 1;
	
	
}










