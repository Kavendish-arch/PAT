#include <stdio.h>
void main( ) {
  int i,n;
  long fact=1;
  printf("input n:");
  scanf("%d",&n);
  for(i=1;i<=n;i++) fact*=i;
  printf("%d!=%ld\n",n,fact);
} 

