#include <stdio.h>
void main( ) {
  int i,j,count;
  count=0;
  for(i=3;i<=1000;i++)
   { for(j=2;j<=i-1;j++)
        if(i%j==0) break;
     if(j>i-1)
       { printf("%4d",i);
         count++;
         if(count%10==0) printf("\n");
	}
   }
} 

