#include <stdio.h>
void main( )
{ int a,b,*pa=&a,*pb=&b,t;
   scanf("%d,%d",&a,&b);        
   if (*pa<*pb) 
   { t=*pa;*pa=*pb;*pb=t;}   /*ab±äÁ¿½»»»*/
   printf("a=%d,b=%d\n",a,b);
   printf("max=%d,min=%d",*pa,*pb);     
}

