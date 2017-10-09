
extern int (**f)(int,int);

main()
{
	p();
	
	printf("compare..............\n\n",f);
	
	printf("%p\n",&f[0]);

	printf("%p\n",&f[1]);

	printf("%p\n",f);
	
	printf("%p\n",&f);
	
	printf("%d\n",sizeof(f));



}
















