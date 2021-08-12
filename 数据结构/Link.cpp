#include <stdlib.h>
#include <stdio.h>
#define Max 100
typedef struct Link
{
	int value;
	struct Link * next;
}Node;

int main(int argc, char const *argv[])
{
	Node * head = NULL;
	Node * p = (Node*) malloc (sizeof(Node));
	p->value = 2;
	head->next = p;
	p->next = NULL;
	return 0;
}
