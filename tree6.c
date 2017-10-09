#include "13demo6.h"

char str1[3][20];

char text1[20] = "(1)  preorder";
char text2[20] = "(2)  inorder";
char text3[20] = "(3)  postorder";
char text4[20] = "(4)  leaf";
char text5[20] = "(5)  find a p/i/l";
char text6[20] = "(6)  del a";
char text7[20] = "(7)  insert z w l/r";
char text8[20] = "(8)  exit";


list flist[] = {
	
	{ text1,'1', (void*)add2,2  },
	{ text2,'2', (void*)add3,3 },
	{ text3,'3', (void*)mul2,2 },
	{ text4,'4', (void*)mul3,3   },
	{ text5,'5', (void*)value,1},
	{ text6,'6', (void*)f1 ,0 },
	{ text7,'7', (void*)value,1},
	{ text8,'8', (void*)f1 ,0 }
		

	
};



manage fmanage ={
	
	flist,

	menu,
	
	sizeof(flist)/sizeof(list)
	

	
	
};

void change()
{
	choose(&fmanage);
	
}



void choose(manage* cpfmanage)    
{
	
	 


	switch(cpfmanage->item[a].pnum)
	{
		case 1:
		
			printf("%d",(   *(int (*)(int))cpfmanage->item[a].func)(atoi(str1[0]))  );
			break;
		case 2:
		
			printf("%d",( *(int (*)(int,int) )cpfmanage->item[a].func)(atoi(str1[0]),atoi(str1[1])) );
			break;
			
		case 3:
		
			printf("%d",( *(int (*)(int,int,int) )cpfmanage->item[a].func)(atoi(str1[0]),atoi(str1[1]),atoi(str1[2]))  );
			break;
		
		case 0:	
		default:
			
			( *(void (*)() )cpfmanage->item[a].func)() ;
			break;
			
		
		
	}
    	
	
	

	
}





















