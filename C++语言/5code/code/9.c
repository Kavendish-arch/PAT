#include <stdio.h>
main()
{
int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
int i,j,*p=a;//a[0]==&a[0][0]==a,a+1与a[0]+1不一样 
printf("a=:%d\na+1=:%d\na[0]+1=:%d\n",a,a+1,a[0]+1); 

for (i=0;i<3;i++)
  {	for (j=0;j<4;j++)
	printf("%-8d", *(p++)) ;
	putchar('\n');
   } 
}

