#include <stdio.h>
main()
{int i,j,k,t,a[10];
 for(i=0;i<10;i++) 
       scanf("%d",&a[i]); /*输入数据到数组*/
 for(i=0;i<9;i++)
  { for(j=0;j<9-i;j++)
	if(a[j]<a[j+1]) {t=a[j];a[j]=a[j+1];a[j+1]=t;}
  }
 putchar('\n');
 for(i=0;i<10;i++)printf("%6d",a[i]);/*输出排序后的数据*/
}
