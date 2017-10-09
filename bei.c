typedef char EleType;

typedef struct{
	
	EleType* buf;
	
	unsigned int n;
	unsigned int max;
	
}List;

List* CreateList(int);

void DestroyList(List*);

void ClearList(List*);

int ListAppend(List*,EleType);

int ListDelete(List*,int);

int ListInsert(List*,int,EleType);


int GetElement(List*,int,EleType*);


int TraverseList(List*,int (*)(EleType*));

int IsEmpty(List*);

int IsFull(List*);



List* CreateList(int max)
{
	List* lp;
	
	if(max<1)
	{
		
		return 0;
		
	}
	
	lp = (List*)malloc(sizeof(List));
	
	if(!lp)
	{
		return 0;
		
	}
	
	lp->buf = (EleType*)malloc(sizeof(EleType)* max);
	
	if(!lp->buf)
	{
		return 0;
		
	}
	
	lp->n = 0;
	lp->max = (unsigned int)max;
	
	return lp;
	
	
	
	
	
	
}

void DestroyList(List* lp)
{
	ClearList(lp);
	free(lp->buf);
	free(lp);
	
	
	
}

void ClearList(List* lp)
{
	while(ListDelete(lp,1));
	lp->n = 0;
	
	
	
}

int ListAppend(List* lp,EleType data)
{
	if(IsFull(lp))
	{
		return 0;
		
	}
	
	lp->buf[lp->n] = data;
	
	lp->n++;
	
	return 1;
	
	
	
	
}

int ListDelete(List* lp,int n)
{
	int i;
	
	if(n<1  ||  n>lp->n)
	{
		
		return 0;
		
	}
	
	if( n < lp->n)
	{
		for(i = n; i < lp->n; i++ )
		{
			lp->buf[i-1] = lp->buf[i];
			
		}
		
	}
	
	lp->n--;
	
	return 1;
	
	

	
}

int ListInsert(List* lp,int n,EleType data)
{
	int i;
	
	if(  n<1 || n>lp->n+1 )
	{
		return 0;
		
	}
	
	if(IsFull(lp))
	{
		return 0;
		
	}
	
	
	if( n<= lp->n)
	{
		for(i = lp->-1; i >= n-1; i--)
		{
			
			lp->buf[i+1] = lp->buf[i];
			
		}
		
	}
	
	lp->buf[n-1] = data;
	lp->n++;
	
	return 1;
	
	
	
	
	
}


int GetElement(List* lp,int n,EleType* dp)
{
	if(lp->n == 0 || n<1 || n>lp->n)
	{
		return 1;
		
		
	}
	
	*dp = lp->buf[n-1];
	
	return 1;
	
	
	
}


int TraverseList(List* lp,int (*f)(EleType*))
{
	int i;
	
	for(i=1;i<= lp->n;i++)
	{
		if(!f(&(lp->buf[i-1])))
		{
			return i;
			
		}
		
	}
	
	return 0;
	
	
}

int IsEmpty(List* lp)
{
	return lp->n == 0;
	
	
}

int IsFull(List* lp)
{
	
	return lp->n == lp->max;
	
	
}



















