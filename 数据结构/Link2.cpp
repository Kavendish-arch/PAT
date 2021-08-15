#include <stdlib.h>
#include <stdio.h>

typedef struct _node
{
    int value;
    struct _node * next;  
} Node;

typedef struct _link
{
    //头指针
    Node * head;
    //尾指针
    Node * tail;
}Link;

// 传入的结构体指针 是结构体变量
// 尾插法
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

    // 头指针，不动
    Node * head = link_node->head;
    // 尾指针
    Node * tail = link_node->tail;
    
    Node * p = (Node * ) malloc (sizeof(Node));
    p->value = data;
    p->next = head;

    if (tail){ 
        tail->next = p;
        link_node->tail = p;
    } else {
        link_node->head = p;
        link_node->tail = p;
    }
}

void traverse(Link * p_head){
    for (Node *p = p_head->head; p; p=p->next){
        printf("value = %d addr = %p\n", p->value, p);
    }
}

void traverse_by_tail(Link * p_head){
    
    for (Node *p = p_head->head; p != p_head->tail; p = p->next){
        printf("value = %d addr = %p\n", p->value, p);
    }
}
/**
 * 头插法 单链表
 */
void insert_from_head(Link * p_head, int data){
	//建构结点
	Node * p = (Node * ) malloc(sizeof(Node));
    p->value = data;
	//结点下一个是原头节点
	p->next = p_head->head;
	// 头节点 变成 新结点
	p_head->head = p;
}
// 单链表 尾插法
void insert(Link * p_head, int data, int index){
    Node * tail = p_head->head;

    // 找到链表尾部
    for(int i = 1; i < index; i ++){
        tail = tail->next;
    }
    Node * p = (Node * ) malloc(sizeof(Node));
    p->value = data;

    p->next = tail->next;
    tail->next =    p;
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
    printf("link head to tail\n");
    node_append(&l_head, 2);
    node_append(&l_head, 5);
    node_append(&l_head, 6);
	// insert_from_head(&l_head, 9);
    traverse_by_tail(&l_head);
    
    return 0;
}
