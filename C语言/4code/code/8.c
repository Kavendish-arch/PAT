#include <stdio.h>
main()
{static int a[]={-12,0,6,16,23,56,80,100,110,115};
 int n,low,mid,high,found;
 low=0; high=9; found=0;
 printf("Input a number to be searched:");
 scanf("%d",&n);
 while(low<=high)
  { mid=(low+high)/2;
    if (n==a[mid]) {found=1;break;}/*�ҵ�������ѭ��*/
    else if(n>a[mid])   low=mid+1; 
    else   high=mid-1;  } 
 if (found==1) printf("The index of %d is %d",n,mid);
 else  printf("There is not %d",n); 
}

