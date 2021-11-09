#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int * a = (int *) malloc (sizeof(int) * 20);
    int n = 10;
    for(int i = 0, j = 1; i < n; i++, j+=2)
    {
        a[i] = j;
    }
    
    for(int i = 0, j = 1; j <= n; i++, j+=2)
    {
        printf("%d ,", a[i]);
    }

    for(int i = -4; i < 2; i++){
        printf("%d, ",i);
    }
     
    return 0;
}
