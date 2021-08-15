#include <stdio.h>
 void sort(int a[],int b)
 { int i,j,max,t;
   for(i=0;i<b-1;i++)
    for(j=0;j<b-1-i;j++)
      if(a[j]>a[j+1])
       {t=a[j];a[j]=a[j+1];a[j+1]=t;}
 }
 main()
{ int b[10]={23,-14,8,0,36,-44,19,38,99,-50};
  int i;
  sort(b,10);                               // 改为sort(&b[0],10)可以吗？
  for(i=0;i<10;i++)
  printf("%d,",b[i]);
}

