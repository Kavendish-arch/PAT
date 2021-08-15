#include <stdio.h>
void main( ) {
 int i=1,s=0;
 loop:s=s+i;
      i++;
 if(i<=100) goto loop;
 printf("\ns=%d",s);
}
