#include <stdio.h>
void hanoi(int n, char a, char b, char c)  //n���̣�����b����a�Ƶ�c
{ if (n==1) 
 	 printf("%c-->%c\n",a,c);   //����̴�a�ƶ���c
 else
       { hanoi(n-1,a,c,b);    
	  printf("%c-->%c\n",a,c); 
	  hanoi(n-1,b,a,c); }     //n-1����Ų��c����ģ��С
} 
 main( )
 { int n;
   printf("input the layer:");
   scanf("%d",&n);
   hanoi(n,'A','B','C');  
 }

