
#include "stdio.h"
#include "stdlib.h"
main()
{
  int j,n,*p;
  printf("�������n:");
  scanf("%d",&n);
  p=(int *)malloc(n*sizeof(int));
  for(j=0;j<n;j++)
    {printf("�����%d������:",j+1);
     scanf("%d",p+j); } 
  for(j=0;j<n;j++)
     printf("%4d",*(p+j));
  printf("%d\n",p);   
  free(p);
  printf("%d\n",p);   
}

