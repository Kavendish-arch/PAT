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
  printf("ָ����ú���max=%d\n",m);
  printf("���������ú���max=%d\n",max(a,b));
}

