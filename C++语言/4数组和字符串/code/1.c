#include <stdio.h>
  main( )
{ int i,j,k,max,min;     
  int a[10];
  for (i=0;i<10;i++)  scanf("%d",&a[i]);  //%d%d%d%d
  max=min=a[0];    /*�ٶ���һ��Ԫ�ؼ������ģ�Ҳ����С��*/   
  j=k=0;           /*j��¼���k��¼��СԪ���±� */  
  for (i=1;i<10;i++) 
    {  if (max<a[i]) { max=a[i];j=i;}/*�ѵ�ǰ���ֵ��max,�±���j*/
       else if (min>a[i]){ min=a[i];k=i;}
    }
 printf("max:a[%d]=%d,min:a[%d]=%d",j,max,k,min);
 }       

