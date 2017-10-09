
typedef char  EleType;

typedef struct node{
	
	EleType data;
	struct node* next;
	
	
}ChainNode;

typedef struct{
	
	ChainNode* head;
	
	ChainNode* tail;
	
	
	
}List;




List* CreateList(void);


void DestroyList(List*);


void ClearList(List*);


ChainNode* GetAddr(List*,int);


ChainNode* NewChainNode(EleType);



int ListAppend(List*,EleType);




int ListDelete(List*,int);


int ListInsert(List*,int,EleType);



int GetElement(List*,int,EleType*);



int TraverseList(List*,int (*)(EleType*));









List* CreateList(void)
{
	
	List* lp;
	EleType* data  = 0;
	
	lp= (List*)malloc(sizeof(List));
	
	if(!lp)
	{
		return 0;
	}
	
	lp->head  = lp->tail = NewChainNode(*data);
	
	if(!lp->head)
	{
		
		free(lp);
		return 0;
	}
	if(!lp->tail)
	{
		
		free(lp);
		return 0;
	}
		
	
	return lp;
	
	
}


void DestroyList(List* lp)
{
	ClearList(lp);
	
		free(lp->head);
		free(lp->tail);
		free(lp);

	
	
}


void ClearList(List* lp)
{
	
	while(ListDelete(lp,1));
	
	
	
}


ChainNode* GetAddr(List* lp,int n)
{
	ChainNode* p;
	int a = 0;
	
	if(n<0)
	{
		return 0;
	}
	
	p=lp->head;
	
	while(p&&a<n)
	{
		
		p=p->next;
		a++;
		
	}
	
	return p;
	
}


ChainNode* NewChainNode(EleType data1)
{
	ChainNode* p;
	p = (ChainNode*)malloc(sizeof(ChainNode));
	
	if(!p)
	{
		return 0;
	}
	
	p->data = data1;
	p->next = 0;
	
	return p;
	
	
}



int ListAppend(List* lp,EleType data)
{
	ChainNode* p;

	
	p = NewChainNode(data);
	if(!(p))
	{
		return 0;
	}	
	
	lp->tail->next = p;
	
	lp->tail = p;
	
	return 1;
	
	
	
	
	
}




int ListDelete(List* lp,int n)
{
	
	ChainNode* p1;
	ChainNode* p2;
	
	if(!lp->head->next)
	{
		
		return 0;
	}
	
	
	p1 = GetAddr(lp,n-1);
	
	if(!(p1&&p1->next))
	{
		return 0;
	}
	
	p2 = p1->next;
	p1->next = p1->next->next;
	
	free(p2);
	
	
	return 1;
	
	
	
	
	
	
}


int ListInsert(List* lp,int n,EleType data)
{
	ChainNode* p1;
	ChainNode* p2;
	

	
	p1 = GetAddr(lp,n-1);
	
	if(!(p1))
	{
		return 0;
	}
	
	p2 = NewChainNode(data);
	if(!(p2))
	{
		return 0;
	}	
	
	p2->next = p1->next;
	
	p1->next = p2;
	
	return 1;
	
	
	
	
	
	
}



int GetElement(List* lp,int n,EleType* dp)
{
	ChainNode* p1;

	

	
	p1 = GetAddr(lp,n);
	
	if(!(p1))
	{
		return 0;
	}
	
	
	*dp = p1->data;
	
	return 1;
	
	
	
	
	
}



int TraverseList(List* lp,int (*f)(EleType*))
{
	
	ChainNode* p;
	int a= 0;
	
	for(p=lp->head->next;p;p=p->next)
	{
		if(!f(&(p->data)))
		{
			
			return a+1;
		}
		
		a++;
		
		
	}
	
	
	return 0;
	
	
	
	
	
	
}














