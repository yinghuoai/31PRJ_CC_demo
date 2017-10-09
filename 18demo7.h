


typedef struct node
{
	void* datap;
	struct node* next;
	
}ChainNode;

typedef struct
{
	int length;
	ChainNode* head;
	ChainNode* tail;

	
}List;


List* CreateList(int);

void DestroyList(List*);

void ClearList(List*);

int ListAppend(List*,...);

int ListInsert(List*,int,...);

int ListDelete(List*,int);

int GetElement(List*,int,void*);

ChainNode* GetAddr(List*,int);

int TraverseList(List*,int (*)(void*));

ChainNode* NewChainNode(void*);


List* CreateList(int size)
{
	List* p;
	void* datap = 0;
	
	p = (List*)malloc(sizeof(List));
	if(!p)
	{
		return 0;
		
		
	}
	p->tail = p->head = NewChainNode(datap);
	
	p->length = size;
	
	if(!p->head)
	{
		free(p);
		return 0;
		
	}
	
	return p;
	
}

void DestroyList(List* lp)
{
	ClearList(lp);
	free(lp->head);
	free(lp->tail);

	lp->head = lp->tail = 0;
	
	free(lp);
	
	lp = 0;
	
	
}

void ClearList(List* lp)
{
	
	while(ListDelete(lp,1));
	
	
}


int ListAppend(List* lp,...)
{
	void* pt;
	void* ps;
	ChainNode* newp;
	
	ps = &lp + 1;
	if(!ps)
	{
		return 0;
		
	}
	
	pt = (void *)malloc(lp->length);
	if(!pt)
	{
		return 0;
		
	}
	memcpy(pt, ps , lp->length);
	
	newp = NewChainNode(pt);
	if(!newp)
	{
		
		return 0;
	}
	
	
	
	lp->tail->next = newp;
	
	lp->tail = newp;
	
	return 1;
	
	
}

int ListInsert(List* lp,int n, ...)
{
	ChainNode* p;
	ChainNode* newp;
	void* pt;
	void* ps;
	
	ps = &lp + 2; 
	

	p = GetAddr(lp,n-1);
	
	if(!p)
	{
		return 0;
	}
	
	
	pt = (void*)malloc(lp->length);
	
	if(!pt)
	{
		return 0;
		
	}
	
	memcpy(pt,ps,lp->length);
	
	
	
	newp = NewChainNode(pt);
	
	if(!newp)
	{
		
		return 0;
	}
	
	newp->next = p->next;
	p->next = newp;
	
	return 1;
	
	
	
	
}

int ListDelete(List* lp,int n)
{
	ChainNode* p;
	ChainNode* p1;
	
	if(!lp->head->next)
	{
		return 0;
	}
	
	p = GetAddr(lp,n-1);
	
	if(!(p&&p->next))
	{
		return 0;
		
	}
	
	p1 = p->next;
	p->next = p->next->next;
	
	free(p1);
	
	return 1;
	
	
	
}


int GetElement(List* lp,int n,void* datapp)
{
	ChainNode* p;
	
	p = GetAddr(lp,n);
	
	if(!p)
	{
		return 0;
		
	}
	
	datapp = (void*)malloc(lp->length);

	if(!datapp)
	{
		return 0;
	}
	
	
	
	datapp = p->datap;
	
	return 1;
	
	
	
}

int TraverseList(List* lp,int (*f)(void*))
{
	ChainNode* p;
	int a=0;
	
	p = (ChainNode*)malloc(sizeof(ChainNode));
	
	if(!p)
	{
		return 0;
	}
	
	for(p = lp->head->next;p;p=p->next)
	{
		if(!f( p->datap ))
		{
			
			return a+1;
			
		}
		
		a++;
		
	}
	
	return 0;
	
	
}


ChainNode* NewChainNode(void* pt)
{
	ChainNode* p;
	
	
	
	p = (ChainNode*)malloc(4);
	
	if(!p)
	{
		return 0;
		
	}
	
	p->datap = pt;
	p->next = 0;
	
	return p;
	
	
	
	
}


ChainNode* GetAddr(List* lp,int n)
{
	ChainNode* p;
	int a;
	
	if(n<0)
	{
		return 0;
	}
	
	p = lp->head;
	a = 0;
	
	while(p&&a<n)
	{
		
		p = p->next;
		a++;
		
	}
	
	return p;
	
	
}





















