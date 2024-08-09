#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/**
 * 可变数组
 */
#define MAX_SIZE 20

// 初始化
Array array_create(int init_size)
{
	Array a;
	a.size = init_size;
	a.current = 0;
	a.array = (int *)malloc(sizeof(int) * a.size);
	return a;
}
/**
 * 知识点
 * 指针可以指向空，引用不行
Array array_create(Array *a, int init_size){
	如果 a 为空
	或者 a 指向存在的数组 需要free
	a->size = init_size;
	a->array =
	return a;
}
*/
void array_free(Array *a)
{
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
/**
 * 为什么需要他返回指针，
 */
// 索引查找
int *array_at(Array *a, int index)
{
	if (index < 0 || index >= a->current)
	{
		printf("no data");
		// return -1;
	}
	return &(a->array[index]);
}

void array_inflate(Array *a, int more_size)
{
	int *p = (int *)malloc(sizeof(int) * (a->size + more_size));
	int i;
	// 库函数内存拷贝优化
	for (i = 0; i < a->size; i++)
	{
		p[i] = a->array[i];
	}
	free(a->array);
	a->array = p;
	a->size += more_size;
}

/**
Array array_create(Array *a, int init_size){
	如果 a 为空
	或者 a 指向存在的数组 需要free
	a->size = init_size;
	a->array =
	return a;
}
 * 为了封装，隐藏实现细节
 */
// 最大max
int array_size(const Array *a)
{
	return a->size;
}
// current 当前
int array_current(const Array *a)
{
	return a->current;
}
// 是否为空
int is_empty(Array *a)
{
	return a->current == 0;
}
// 是否满
int is_full(Array *a)
{
	return a->current == a->size;
}
// 按值查找
int *array_locate(Array *a, int data)
{
	for (int i = 0; i < a->current; i++)
	{
		if (a->array[i] == data)
		{
			return &(a->array[i]);
		}
	}
}
// 插入
void array_insert(Array *a, int data, int index)
{
	if (index + a->current >= a->size)
	{
		int more_size = (index / MAX_SIZE + 2) * MAX_SIZE - a->size;
		array_inflate(a, more_size);
	}
	else
	{
		for (int i = a->current; i > index; i--)
		{
			a->array[i] = a->array[i - 1];
		}
		a->array[index] = data;
		a->current++;
	}
}
// 末尾追加
void array_append(Array *a, int data)
{
	if (is_full(a))
	{
		printf("array is full\n");
	}
	else
	{
		a->array[a->current] = data;
		a->current++;
	}
}

int main(int argc, char const *argv[])
{
	Array a = array_create(100);
	for (int i = 0; i < 20; i++)
	{
		a.array[i] = i;
		a.current++;
	}
	printf("array max = %d\n", array_size(&a));
	printf("array current = %d\n", array_current(&a));
	// *(array_at(&a, 0)) = 20;
	printf("%d\n", *(array_at(&a, 19)));
	printf("%d\n", *(array_at(&a, 20)));

	array_append(&a, 30);
	printf("array max = %d\n", array_size(&a));
	printf("append , array current = %d\n", array_current(&a));
	printf("%d\n", *(array_at(&a, 20)));

	array_inflate(&a, 20);
	printf("扩容后 array.size = %d\n", array_size(&a));

	for (int i = 0; i < a.current; i++)
	{
		printf("%d\t", a.array[i]);
	}
	printf("\n");
	array_insert(&a, -2, 8);
	for (int i = 0; i < a.current; i++)
	{
		printf("%d\t", a.array[i]);
	}
	printf("\n");
	printf(" %d ", array_at(&a, 8));
	printf(" %d ", array_locate(&a, -2));

	return 0;
}
