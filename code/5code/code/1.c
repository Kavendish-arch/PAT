#include "stdio.h"
void main()
{int a,b;
 int *p1,*p2;
 p1=&a; 
 p2=&b; 
 printf("a,b=");
 scanf("%d%d",p1,p2);  
 printf("%d,%d\n",a,b);
 printf("%d,%d\n",*p1,*p2);
 printf("%d,%d\n",a,b); 
}

