#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void test(int ** nums){
    int n[] = {1,2,3,4};
    *nums = n;
}
void swap(int ** a, int ** b){
    printf("[%p, %p]\n",a,b);
    printf("[%p, %p]\n",*a,*b);
    printf("[%d, %d]\n",**a,**b);
    
    int *p = *a;
    *a = *b;
    *b = p;
}
void test_str(char ** str_d){
    char * str = (char*) malloc(sizeof(char) * 100);
    for (int i = 0; i < 27; i++) {
        str[i] = 'a' + i;
    }
    str[26] = '\0';
    printf("%s\n", str);
    printf("%p\n", str);
    *str_d = str;
}
int main(int argc, char const *argv[])
{
    int *array;
    test(&array);
    printf("%d\n",array[0]);

    int a = 2, b = 3;
    int *p = &a, *q = &b;
    // 指针p,q指向的值变了
    printf("befor [%d, %d]\n",*p,*q);
    printf("address [p,q]:[%p, %p]\n", p, q);
    swap(&p, &q);
    printf("after [%d, %d]\n",*p, *q);
    printf("address [p,q]:[%p, %p]\n", p, q);

    char * str; 
    test_str(&str);
    printf("%p\n", str);
    int i = 0;
    // for (int i = 0; i < 100; i++)
    while (*(str) != '\0')
    {
        printf("%c", *(str+i));
        i ++;
    }
    
    return 0;
}

