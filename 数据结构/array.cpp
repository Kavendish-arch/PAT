#include <stdio.h>
#include <stdlib.h>

#include "array.h"
/**
 * 可变数组
 */
#define MAX_SIZE 20


Array array_create(int init_size){
	Array a;
	a.size = init_size;
	a.current = 0;
	a.array = (int*) malloc (sizeof(int)*a.size);
	return a;
}
/**
 * 知识点
Array array_create(Array *a, int init_size){
	如果 a 为空
	或者 a 指向存在的数组 需要free
	a->size = init_size;
	a->array = 
	return a;
}
*/
void array_free(Array * a){
	free(a->array);
	a->size = 0;
	// free(0) free(null)是无害的
	a->array = NULL;
}
/**
 * 读取数组长度
 * 传入不可变数组指针
 * 为了封装，隐藏实现细节
 */
int array_size(const Array * a){
	return a->size;
}
/**
 * 为什么需要他返回指针， 
 */
int * array_at(Array * a, int index){
	if (index >= a->size){
		int more_size = (index / MAX_SIZE + 2) * MAX_SIZE - a->size;
		array_inflate(a, more_size);
	}
	return &(a->array[index]);
}

void array_inflate(Array * a, int more_size){
	int *p = (int*) malloc (sizeof(int) * (a->size + more_size));
	int i;
	// 库函数内存拷贝优化
	for (i = 0; i < a->size; i++){
		p[i] = a->array[i];
	}
	free(a->array);
	a->array = p;
	a->size +=  more_size;
}

int main(int argc, char const *argv[])
{
	Array a = array_create(100);
	for (int i = 0; i < a.size; i++){
		a.array[i] = i;
		;
	}
	printf("%d\n",array_size(&a));
	*(array_at(&a, 0)) = 20;
	printf("%d\n",*(array_at(&a, 0)));
	array_inflate(&a, 20);	
	printf("扩容后 array.size = %d\n",array_size(&a));
	return 0;
}

