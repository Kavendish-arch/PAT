#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef struct
{
	int *array;
	int size;
	int current;
} Array;

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
int array_size(const Array *a);
// current 当前
int array_current(const Array *a);
// 是否为空
int is_empty(Array *a);
// 是否满
int is_full(Array *a);
/**
 * 为什么需要他返回指针，
 */
// 初始化
Array array_create(int init_size);
// 销毁
void array_free(Array *a);
// 索引查找
int *array_at(Array *a, int index);
// 按值查找
int *array_locate(Array *a, int data);
// 插入
void array_insert(Array *a, int data, int index);
// 末尾追加
void array_append(Array *a, int data);
// 扩充
void array_inflate(Array *a, int more_size);

#endif
