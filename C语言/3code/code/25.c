#include <stdio.h>
int main() {
int a=1;
#if 1
    printf("%d",a);
#else
     printf("%d",a+1);
#endif
     printf("\nHello World!");
}


