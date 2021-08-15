#include <stdio.h>
#define N 10
 void yh(int a[][N],int n)
 { int i,j;
   for(i=0;i<n;i++)
    {a[i][0]=1;a[i][i]=1;}
   for(i=2;i<n;i++)
     for(j=1;j<i;j++)
	a[i][j]=a[i-1][j-1]+a[i-1][j]; 
 }
main()
{ int i,j,n,b[N][N];
  printf("enter n:");scanf("%d",&n);
  yh(b,n);
  for(i=0;i<n;i++)
  {for(j=0;j<=i;j++)
     printf("%-6d",b[i][j]);
   putchar('\n'); } 
}

