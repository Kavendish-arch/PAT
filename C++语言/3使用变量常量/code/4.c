#include <stdio.h>
void main( ) {
 int i;
 for(i=1;i<=100;i++)
  { if(i>50) break;
    if(i%5!=0) continue;
    printf("%4d",i);
  }
} 

