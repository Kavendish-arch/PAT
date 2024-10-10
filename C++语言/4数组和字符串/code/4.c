#include <stdio.h>
main()
{int i,fib[20];  //fib[0]--fib[19]
 fib[0]=1;
 fib[1]=1;
 for(i=2; i<=19;i++)
        fib[i]= fib[i-1]+ fib[i-2];
 printf(" Fibonaci Numbers are:\n");
 for(i=0;i<20;i++)
   {  if(i%5==0)   printf("\n");
      printf("%7d",fib[i]);
   }
}

