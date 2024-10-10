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
    *L=(LinkList)malloc(sizeof(Node)); /* ����ͷ���,��ʹLָ���ͷ��� */
    if(!(*L)) /* �洢����ʧ�� */
          return ERROR;
    (*L)->next=NULL; /* ָ����Ϊ�� */
    return OK;
}

 
/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */

int ListLength(LinkList L)
{   int i=0;
    LinkList p=L->next; /* pָ���һ����� */
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
  int  flag =1; //����һ����־��������"$"ʱ��flagΪ0���������
  r=L;         //rָ������ĵ�ǰ��β�����ֵָ��ͷ���
  while(flag)  //ѭ���������Ԫ��ֵ���������½��s�����β*/
	{ c=getchar();
	  if(c!='$')
		{ s=(Node*)malloc(sizeof(Node));
		  s->data=c;
		  r->next=s;
		  r=s;	}
	  else
		{ flag=0;
		  r->next=NULL; //���һ������next��Ϊ�գ���ʾ�������
		}
	}   
} 
 
int main()
{
    LinkList L;
    int i;
    if(InitList(&L))//ָ��ĵ�ַ 
    printf("����L��ʼ����ϣ�ListLength(L)=%d\n",ListLength(L));
    CreateFromTail(L);
    printf("����L��ʼ����ϣ�ListLength(L)=%d\n",ListLength(L));

}

