#include <stdlib.h>
#include <stdio.h>

typedef struct Link
{
	int value;
	struct Link * next;
}Node;

int replace(Node * a, Node * b){
	Node tmp = *a;
	*a = *b;
	*b = tmp;
	return 0;
}

void append(Node * head, int data){
	Node *p = (Node*) malloc (sizeof(Node));
	p->value = data;
	p->next = NULL;
	Node * last = head;
	if (last) {
		while (last->next)
		{
			last = last->next;
		}
		last->next = p;	
	} else {
		head = p;
	}
}
int main(int argc, char const *argv[])
{
	Node * head = NULL;
	append(head, 20);
	
	printf("%d", head->value);
	return 0;
}
