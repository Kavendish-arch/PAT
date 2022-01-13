
#include <stdio.h>
#define Max 100



typedef struct Link
{
	int value;
	struct Link * next;
}SqlList;

template <typename T>
Link InitList(int num){
	Link sq;
	int len = sizeof(num) / sizeof(num[0]);
	printf("%d ",len);

	for (int i = 0; i < len; i++){
		// sq.data[i] = num[i];
		// printf("%d ",sq.data[i]);
		// sq.lenth ++;
	}
	return sq;
}

int Length(Link *L){
	return 1;
}
template<typename T>
void swap (T *a, T *b)
{
	T tmp = *a;
	*a = *b;
	*b = tmp;
}
int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,4,5};
	// printf("%d ", sizeof(a)/sizeof(a[0]));
	// Link sq = InitList(a);
	// printf("%d", Length(&sq));

	int c = 0, b = 5;
	swap(&c,&b);
	printf("%d,%d", c,b);

	return 0;
}
