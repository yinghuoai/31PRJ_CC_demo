
int add(int a,int b)
{
	return a+b;
}

int sub(int a,int b)
{
	return a-b;
	
}


int (*f[2])(int,int) = {add,sub};


void p()
{
	printf("%p\n",&f[0]);

	printf("%p\n",&f[1]);

	printf("%p\n",f);
	
	printf("%d\n",sizeof(f));

	
}
















