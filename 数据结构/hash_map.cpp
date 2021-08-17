#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node * next;
    struct _node * pre;
}Node;

typedef struct _HashMap {
    Node * array;
    int size;
}HashMap;

int hash_fun(int x, int size){
    return x % size;
}

void init(HashMap *p){
    p->size = 20;
    p->array = (Node*) malloc(sizeof(Node) * p->size);
    for (int i = 0; i < p->size;i ++){
        p->array[i].data = NULL;
        p->array[i].next = NULL;
    }
}

void set(HashMap * head, int key, int value){

    Node * tmp = (Node*) malloc(sizeof(Node));
    tmp->data = value;
    tmp->next = NULL;
    
    int index = hash_fun(key,head->size);

    Node * node_head = &head->array[index];

    while (node_head->next)
    {
        node_head = node_head->next;
    }
    node_head->next = tmp;
}

void get(HashMap * head, int key, Node ** value){
    
    int index = hash_fun(key,head->size);

    *value = &head->array[index]; 
}

void traverse(Node * p){
    while (p->next){
        p = p->next;
        printf("%d ----> ",p->data);
    }
    printf("Null.\n") ;
}

int main(int argc, char const *argv[])
{
    HashMap ha;
    init(&ha);

    printf("%d\n", ha.size);
        
    set(&ha, 5,10);
    set(&ha, 6,10);
    set(&ha, 5,20);
    int index = hash_fun(5, ha.size);

    Node *p;
    get(&ha, 5, &p);
    traverse(p);
    return 0;
}
