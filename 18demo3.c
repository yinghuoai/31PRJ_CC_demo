#include "19demo4.h"

int a[8] = {11,22,33,44,55,66,77,88};

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
	
	for(n = 0; n < 8 ; n++)
	{
		ListAppend(lp,a[n]);
		
	}
	
	showlist(lp);
	
	ListInsert(lp,1,8);
	showlist(lp);
	
	ListInsert(lp,8,18);
	showlist(lp);
	
	ListDelete(lp,1);
	showlist(lp);
	
	ListDelete(lp,7);
	showlist(lp);
	
	
	
	
	
	
	
	
}



void showlist(List* lp)
{
	TraverseList(lp,putelement);
	printf("\n");
	
	
}


int putelement(EleType* data)
{
	printf("%d",*data);
	return 1;
	
}























