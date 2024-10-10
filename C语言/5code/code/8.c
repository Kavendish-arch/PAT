#include <stdio.h>
int add(int a, int b)
{return a+b;  }
int sub(int a, int b)
{return a-b;  }
int compute(int x, int y, int (*p)())
{ int result;
  result=(*p)(x, y);    //调用地址所指的函数
  return result;
}
void  main()
{int x=8,y=3;
 printf("%d+%d=%d\n", x, y, compute(x, y, add));
 printf("%d-%d=%d\n", x, y, compute(x, y, sub));
}

