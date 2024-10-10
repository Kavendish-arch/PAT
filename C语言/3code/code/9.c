#include <stdio.h>
void main( ) {
 int i,j;
 for(i=1;i<=4;i++)
  { for(j=1;j<=5-i;j++)
      putchar(' '); //先输出空格 
    for(j=1;j<=2*i-1;j++)
      putchar('*'); //再输出*     
    putchar('\n'); 
  }
   for(i=1;i<=3;i++)
  { for(j=1;j<=i+1;j++)
      putchar(' '); //先输出空格 
    for(j=1;j<=7-2*i;j++)
      putchar('*'); //再输出*     
    putchar('\n'); 
  }
	
} 

