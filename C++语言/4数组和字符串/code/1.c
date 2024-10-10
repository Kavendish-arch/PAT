#include <stdio.h>
  main( )
{ int i,j,k,max,min;     
  int a[10];
  for (i=0;i<10;i++)  scanf("%d",&a[i]);  //%d%d%d%d
  max=min=a[0];    /*假定第一个元素既是最大的，也是最小的*/   
  j=k=0;           /*j记录最大，k记录最小元素下标 */  
  for (i=1;i<10;i++) 
    {  if (max<a[i]) { max=a[i];j=i;}/*把当前最大值送max,下标送j*/
       else if (min>a[i]){ min=a[i];k=i;}
    }
 printf("max:a[%d]=%d,min:a[%d]=%d",j,max,k,min);
 }       

