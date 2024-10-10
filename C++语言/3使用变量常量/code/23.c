#include <stdio.h>
void hanoi(int n, char a, char b, char c)  //n个盘，借助b，从a移到c
{ if (n==1) 
 	 printf("%c-->%c\n",a,c);   //这个盘从a移动到c
 else
       { hanoi(n-1,a,c,b);    
	  printf("%c-->%c\n",a,c); 
	  hanoi(n-1,b,a,c); }     //n-1个盘挪到c，规模减小
} 
 main( )
 { int n;
   printf("input the layer:");
   scanf("%d",&n);
   hanoi(n,'A','B','C');  
 }

