#include <stdio.h>
int max(int x,int y)
{int m;
 if (x>y) m=x;
 else m=y; 
 return(m);
}
main( )
{ int a,b,m,(*p)();
  scanf("%d,%d",&a,&b);
  p=max;
  m=(*p)(a,b);
  printf("指针调用函数max=%d\n",m);
  printf("函数名调用函数max=%d\n",max(a,b));
}

