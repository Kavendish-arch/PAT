#include <stdio.h>
main (int  argc , char  *argv [ ])
{ int  i=1,n=argc;
  printf("argc=%d\n",n);
  printf("\n��������%s",*argv);
  argv++; n--;
  while(i<=n)  
  { printf("\n����%d��%s",i,*argv);
    i++;argv++;}    
}  


