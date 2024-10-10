#include <stdio.h>
void main( ) {
  int i=1,s=0;
  for( ; ; )
    if(i<=100) { s=s+i;i++;}
    else break;
  printf("%d",s);
} 
 

