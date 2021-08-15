#include <stdlib.h>
#include <stdio.h>

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
/**
 * 头插法 单链表
 */
void push(Link * p_head, int data){
	//建构结点
	Node * p = (Node * ) malloc(sizeof(Node));
    p->value = data;

	//结点下一个是原头节点
	p->next = p_head->head;
	// 头节点 变成 新结点
	p_head->head = p;
}
void pop(Link * p_head, int * data){
    Node * tail = p_head->head;
    tail = tail->next;
    
    Node * p = tail->next; 
    *data = p->value;
    tail->next = p->next;
    free(p);
}
// 查找 elem 头节点存数字
void get_elem(Link * p_head, Node * data, int index){
	
	//tail 头结点 
    Node * tail = p_head->head;

    for(int i = 1; i <= index; i ++){
        tail = tail->next;
    }
    data = tail;
}
void locate_elem(Link * p_head, int *index, int targe){
	Node * tail = p_head->head;
	int i = 0;
	while (tail != NULL && tail->value != targe)
	{
		tail = tail->next;
		i++;

		// if (tail->value != targe){
		// } else {
			// *index = i;
			// return;
		// }
	}	
	*index = i;
}
int main(int argc, char const *argv[])
{
    Link l_head;

    // Node * tmp = (Node *) malloc (sizeof(Node));
    // tmp->next = NULL;
    // tmp->value = 20;
    
    // l_head.head = tmp;
    printf("%d\n", sizeof(Node));
    l_head.head = l_head.tail = NULL;
    // Node * head = NULL;
    node_append(&l_head, 2);
    node_append(&l_head, 5);
    node_append(&l_head, 6);
	insert_from_head(&l_head, 9);
    traverse(&l_head);
    
	printf("\n");
    insert(&l_head, 10, 2);
    traverse(&l_head);

    printf("\n");
    insert(&l_head, 30, 2);
    traverse(&l_head);

    int x = 0;
    remove(&l_head, &x, 2);
    printf("\ndelete %d\n",x);
    traverse(&l_head);
    
	Node y;
    get_elem(&l_head, &y, 1);
	printf("\nread 2 num %d\n",y.value);
    // traverse(&l_head);
	int z = 0;
	locate_elem(&l_head, &z, 9);
	printf("locate elem = %d\n", z), 
	locate_elem(&l_head, &z, 10);
	printf("locate elem = %d\n", z), 


	printf("\nhead and tail\n");
    printf("head = %d\n", l_head.head->value);
    printf("tail = %d\n", l_head.tail->value);
    return 0;
}
