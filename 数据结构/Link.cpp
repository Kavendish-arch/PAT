
#include <stdio.h>
#define Max 100
struct Link
{
	int data[Max];
	int lenth = 0;
}SqlList;


Link InitList(int* num){
	Link sq;
	int len = sizeof(num) / sizeof(num[0]);
	printf("%d ",len);

	for (int i = 0; i < len; i++){
		sq.data[i] = num[i];
		// printf("%d ",sq.data[i]);
		sq.lenth ++;
	}
	return sq;
}

int Length(Link *L){
	return L->lenth;
}
void swap (int *a, int *b){

}
int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,4,5};
	// printf("%d ", sizeof(a)/sizeof(a[0]));
	// Link sq = InitList(a);
	// printf("%d", Length(&sq));

	int b = 23;
	int &b = b;
	int *p = a;
	// *p = 12;
	
	printf("%p", p);

	return 0;
}
