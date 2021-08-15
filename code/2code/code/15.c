#include <stdio.h>
#include <math.h>
void main( )
{
  float a,b,c,disc,x1,x2,p,q;
  scanf("a=%f,b=%f,c=%f",&a,&b,&c);
  disc=b*b-4*a*c;
  p=-b/(2*a);
  q=sqrt(disc)/(2*a);
  x1=p+q;x2=p-q;
  printf("x1=%f\n",x1);
  printf("x2=%f\n",x2);
}

