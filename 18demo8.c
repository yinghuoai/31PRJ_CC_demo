#include "18demo7.h"

typedef struct
{
	char a;
	int b;
	
}EleType;




EleType a[8] = {'a',1,'b',2,'c',3,'d',4,'e',5,'f',6,'g',7,'h',8};


void showlist(List*);

int putelement(void*);

main()
{
	List* lp;
	int n;
	EleType data;
	
	
	
	lp = CreateList(sizeof(EleType));
	
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
	
	data.a = '*';
	data.b = 8;
	
	ListInsert(lp,1,data);
	showlist(lp);
	
	
	data.a = 'a';
	data.b = 20;
	ListInsert(lp,8,data);
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


int putelement(void* data)
{
	
	EleType* test = (EleType*)data;
	
	printf("(%c %d)  ",test->a,test->b);	
	
	return 1;
	
}


























































