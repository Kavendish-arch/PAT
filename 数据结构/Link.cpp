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


#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
    int value;
    struct _node * next;  
} Node;

typedef struct _link
{
    Node * head;
    Node * tail;
}Link;

// 传入的结构体指针 是结构体变量
/**
 * 全局变量
 * 返回值
 */
// void node_create(Node * head, int data) {
void node_append(Link * link_node, int data) {

    Node * tail = link_node->head;

    Node * p = (Node * ) malloc (sizeof(Node));
    p->value = data;
    p->next = NULL;

    if (tail){
        while (tail -> next){
            tail = tail->next;
        }
        tail->next = p;
        link_node->tail = p;
    } else {
        link_node->head = p;
    }
    // if (link_node->tail) {
        // while (tail -> next)
        // {
            // tail = tail->next;
        // }
        // tail->next = p; 
    // }
    // else {
        // link_node->tail=p;    
        // head = p;
    // }
}
void traverse(Link * p_head){
    for (Node *p = p_head->head; p; p=p->next){
        printf("value = %d addr = %p\n", p->value, p);
    }
}

void insert(Link * p_head, int data, int index){
    Node * tail = p_head->head;
    for(int i = 1; i < index; i ++){
        tail = tail->next;
    }
    Node * p = (Node * ) malloc(sizeof(Node));
    p->value = data;

    p->next = tail->next;
    tail->next = p;
}
void remove(Link * p_head, int * data, int index){
    Node * tail = p_head->head;
    for(int i = 1; i < index; i ++){
        tail = tail->next;
    }
    Node * p = tail->next; 
    *data = p->value;
    tail->next = p->next;
    free(p);
}
int main(int argc, char const *argv[])
{
    Link l_head;

    // Node * tmp = (Node *) malloc (sizeof(Node));
    // tmp->next = NULL;
    // tmp->value = 20;
    
    // l_head.head = tmp;
    printf("%d", sizeof(Node));
    l_head.head = l_head.tail = NULL;
    // Node * head = NULL;
    node_append(&l_head, 2);
    node_append(&l_head, 5);
    node_append(&l_head, 6);
    traverse(&l_head);
    printf("\n");
    insert(&l_head, 10, 2-1);
    traverse(&l_head);
    printf("\n");
    insert(&l_head, 30, 2-1);
    traverse(&l_head);
    printf("\n");
    int x = 0;
    remove(&l_head, &x, 2-1);
    printf("delete %d\n",x);
    traverse(&l_head);

    printf("head = %d\n", l_head.head->value);
    printf("p + 0 = %d\n", (l_head.head+0)->value);
    printf("p + 1 = %d\n", (l_head.head+1)->value);
    printf("tail = %d\n", l_head.tail->value);
    return 0;
}
