#include "stdio.h"
#include "stdlib.h"
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 
typedef int Status;
typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;

}Node;

typedef struct Node *LinkList;

int InitList(LinkList *L)
{
    *L=(LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
    if(!(*L)) /* 存储分配失败 */
          return ERROR;
    (*L)->next=NULL; /* 指针域为空 */
    return OK;
}

 
/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */

int ListLength(LinkList L)
{   int i=0;
    LinkList p=L->next; /* p指向第一个结点 */
    while(p)
    {
        i++;
        p=p->next;
    }
    return i;
}
void CreateFromTail(LinkList L)
{ Node *r, *s;
  char c;
  int  flag =1; //设置一个标志，当输入"$"时，flag为0，建表结束
  r=L;         //r指向链表的当前表尾，其初值指向头结点
  while(flag)  //循环输入表中元素值，将建立新结点s插入表尾*/
	{ c=getchar();
	  if(c!='$')
		{ s=(Node*)malloc(sizeof(Node));
		  s->data=c;
		  r->next=s;
		  r=s;	}
	  else
		{ flag=0;
		  r->next=NULL; //最后一个结点的next置为空，表示链表结束
		}
	}   
} 
 
int main()
{
    LinkList L;
    int i;
    if(InitList(&L))//指针的地址 
    printf("链表L初始化完毕，ListLength(L)=%d\n",ListLength(L));
    CreateFromTail(L);
    printf("链表L初始化完毕，ListLength(L)=%d\n",ListLength(L));

}

