#include <stdio.h>
main()
{int i,j,t,a[10];
 for(i=0;i<10;i++) 
      scanf("%d",&a[i]); /*�������ݵ�����*/
 for(i=0;i<9;i++)           /*��9����Сֵ*/
	for(j=i+1;j<10;j++)
	if(a[i]>a[j])       /*����a[i]����Сֵ*/
	{t=a[i];a[i]=a[j];a[j]=t;
	}
 putchar('\n');
 for(i=0;i<10;i++)printf("%6d",a[i]);/*�������������*/
}

