#include <stdio.h>
#include <stdlib.h>

#include "array.h"
/**
 * 可变数组
 */
#define MAX_SIZE 20
// 初始化

int replace(Array *a, int data){
	a->array[0] = data;
	return 0;
}

int main(int argc, char const *argv[])
{
	Array a;
	a.current = 0;
	a.size = MAX_SIZE;
	a.array = (int*) malloc (sizeof(int) * a.size);

	replace(&a, 3);
	printf("%d",*(a.array + 0));
	return 0;
}
