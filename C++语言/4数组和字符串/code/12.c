#include <stdio.h>
 int compare(int a[],int b)
 { int i,max;
   max=a[0];
   for(i=1;i<b;i++) 
     if(max<a[i]) max=a[i];
     
   a[3]=100;  
   return max; 	
 }
 main()
{ int a[10]={23,-14,8,0,36,-44,19,38,99,-50};
  printf("max=%d\n",compare(a,10));
  int i;
  for(i=0;i<10;i++) printf("%d,",a[i]);
}

