#include <stdio.h>
 int compare(int a,int b)
 { if(a>b) return a;
   else return b; 	
 }
main()
{ int a[10]={23,-14,8,0,36,-44,19,38,99,-50};
  int i,max=a[0];
  for(i=1;i<10;i++) max=compare(max,a[i]);
  printf("max=%d",max);
}

