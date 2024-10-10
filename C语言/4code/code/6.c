#include <stdio.h>
main()
{int i,j,t,a[10];
 for(i=0;i<10;i++) 
      scanf("%d",&a[i]); /*输入数据到数组*/
 for(i=0;i<9;i++)           /*找9次最小值*/
	for(j=i+1;j<10;j++)
	if(a[i]>a[j])       /*假设a[i]是最小值*/
	{t=a[i];a[i]=a[j];a[j]=t;
	}
 putchar('\n');
 for(i=0;i<10;i++)printf("%6d",a[i]);/*输出排序后的数据*/
}

