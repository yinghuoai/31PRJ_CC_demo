


int diao(int k)
{
	int value;
	
	if(k == 1)
	{
		value = 1;
	}
	else if(k == 2)
	{
		value = 2;
	}
	else
	{
		value = 2*diao(k-1) + diao(k-2);
		
	}
	
	return value;
	
	
}




int main()
{
	int n,i;
	int* p;
	int* result;
	char s1[20],s2[20];
	
	while(gets(s1)==0);
	n = atoi(s1);
	
	p = (int*)malloc(n*sizeof(int));
	result = (int*)malloc(n*sizeof(int));	
	
	for(i = 0;i < n; i++)
	{
		while(gets(s2)==0);
		p[i] = atoi(s2);
		
		result[i] = diao(p[i]);
		
		
		
		
	}
	
	for(i = 0;i < n; i++)
	{
		
			printf("%d\n",result[i]);
		
		
	}
	
	
	
	

	
	
	
	
	
	return 0;
}


























