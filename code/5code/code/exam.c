#include <stdio.h>
main (int  argc , char  *argv [ ])
{ int  i=1,n=argc;
  printf("argc=%d\n",n);
  printf("\n程序名：%s",*argv);
  argv++; n--;
  while(i<=n)  
  { printf("\n参数%d：%s",i,*argv);
    i++;argv++;}    
}  


