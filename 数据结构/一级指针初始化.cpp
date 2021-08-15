
/**
 * fork 实例测试
 */
#include <unistd.h> 
#include <stdlib.h>
#include <stdio.h>

void init(int * p){
    printf("%p\n",p);
    p = (int*) malloc(sizeof(int) * 12);
    printf("%p\n",p);
}

int main(int argc, char const *argv[])
{
    /* code */
    int *p;
    init(p);
    return 0;
}
