#include <stdio.h>

void main( ) {
 float a,b,m; 
 float max(float ,float );
 scanf("%f,%f",&a,&b);
 m=max(a,b);   //����
 printf("max=%f\n",m); 
} 

float max(float a,float b)//����
{ float y;
  if(a>b) y=a;
  else y=b;
  return y; 
} 

