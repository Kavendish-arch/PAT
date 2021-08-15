#include <stdio.h>
int  *max(int x,int y)
{int m,*p;
 if (x>y) m=x;
 else m=y;
 p=&m;
 return(p);
}
main( )
{ int a,b,*p;
  scanf("%d,%d",&a,&b);
  p=max(a,b);
  printf("max=%d",*p);
}

