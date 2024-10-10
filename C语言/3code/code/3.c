#include <stdio.h>
void main( ) {
 long a,i,t=0;
 scanf("%ld",&a);
 while(a>0)
 { i=a%10;
   t=t*10+i;
   a=a/10;
 }
  printf("\n%ld",t);
} 

