#include <stdio.h>
main()
{int j,k;
 int a[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
 int b[4][4];
 for (j=0;j<4;j++)
	for(k=0;k<4;k++) 
	      b[j][k]=a[k][j];
for(j=0;j<4;j++)
	{for(k=0;k<4;k++)
	      printf("%6d",a[j][k]);
	 printf("\n");   }
putchar('\n');
for(j=0;j<4;j++)
      {for(k=0;k<4;k++)
	printf("%6d",b[j][k]);
       printf("\n");  }
}		

