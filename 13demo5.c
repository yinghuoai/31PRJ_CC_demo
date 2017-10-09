#include "13demo3.h"




char text1[20] = "(1)  add";
char text2[20] = "(2)  sub";
char text3[20] = "(3)  mul";
char text4[20] = "(4)  div";
char text5[20] = "(5)  value";
char text6[20] = "(6)  hello world!";

int add(int,int);
int sub(int,int);
int mul(int,int);
int div(int,int);
int value(int);
void f1();
void putstr(char*);



ItemType item[]={
	
	
	{ text1,'1',2, {add}  },
	{ text2,'2',2, {sub}  },
	{ text3,'3',2, {mul}  },
	{ text4,'4',2, {div}   },
	{ text5,'5',1, {value }},
	{ text6,'6',0, {f1 } }
					

};








main()
{
	menu(item,6);
	
	
}



int add(int a,int b)
{
	return a+b;
}

int sub(int a,int b)
{
	return a-b;
	
}

int mul(int a,int b)
{
	return a*b;
}

int div(int a,int b)
{
	return a/b;
	
}

int value(int a)
{
	
	return a;
	
}


void f1()
{
	putstr("hello world!");
	
}



void putstr(char* str)
{
	
	int far* scr =(int far*)(0xb8000000+160*10+33*2);
	int n;
	
	for(n = 0;str[n];n++)
	{
		
		scr[n] = str[n]+(n+1)*0x100;
		
	}
	
}













































