#include <stdio.h>        //双向非循环链表 
#include <stdlib.h>
#define ElemType int
#define ERROR -1
#define OK 1

typedef struct DNode
{ ElemType data; 
  struct DNode  *prior,*next; 
}DNode,*DoubleList;

int DlinkIns(DoubleList L,int i,ElemType e)
{  DNode *s,*p;  //在p结点之前插入s结点
   int k;
   p=L;  k=0;       //从“头”开始，查找第i个结点，相当于头结点是0号结点
   while(p->next!=L&&k<i) //找到尾节点没找到跳出或k==i跳出
	{ p=p->next;
	  k=k+1; }							     
   if(p->next==L&&k!=i) //插入位置不合理，i的值不合适此链表
	{ printf("插入位置不合理!");
	  return ERROR;}
   s=(DNode*)malloc(sizeof(DNode)); //p已就位，开始申请s结点空间   
if (s) 				//s空间申请成功
	{
		s->data=e;
			
		p->prior->next=s;	//建立左边关系
			s->prior=p->prior;
				
		p->prior=s;		//建立右边关系
			s->next=p;	
		return OK;
	}
else 	return ERROR;
}


void Init_DLinklist(DoubleList *H) //LinkList为指针型
{ *H=(DoubleList)malloc(sizeof(DNode)); //申请一个结点空间
  (*H)->next=*H;                  
  (*H)->prior=*H; 
 }
void Creat_DLinkList(DoubleList L)
{   char c;
    static int i=1;
    DoubleList s;
    printf("请输入第%d个结点的值",i);
    scanf("%d",&c);
    if(c!=-1){
    s=(DNode*)malloc(sizeof(DNode)); 
    s->data=c;
    L->next=s;
    s->prior=L;
    L->prior=s;
    s->next=L;
	}
    
    printf("请输入第%d个结点的值",i+1);
	scanf("%d",&c);
	while(c!=-1)  //输入-1结束 
	 { 	DlinkIns(L,1,c); //在第一个结点之前插入，头插法 
	 	i++;
	 	printf("请输入第%d个结点的值",i+1);
	    scanf("%d",&c);
	 }
}
void Print_DLinkList(DoubleList L)
{  DoubleList p=L->next;
   while(p!=L) 
   {printf("%8d",p->data);
    p=p->next;
   }
	
}

int DlinkDel(DoubleList L,int i,ElemType *e)  //doublelinkdelete
{ DNode  *p;          //p指向要删除的结点
  int k;
  p=L;  k=0;    //从“头”开始，查找第i个结点，头结点相当于第0个结点
  while(p->next!=L && k<i) //找第i个结点
	{ p=p->next;
	  k=k+1; }
  if(p->next==L&&k<i)  return ERROR;  //到尾结点也未找到i结点，i太大
  else	{ *e=p->data;     //被删除结点的值由e指针带回给主调函数
	    p->next->prior=p->prior;
	  p->prior->next=p->next;
	
	  free(p);

	}
}

int main(int argc, char *argv[]) {
	int i,e;
	DoubleList DL;
	Init_DLinklist(&DL);
	Creat_DLinkList(DL);
	Print_DLinkList(DL);
	printf("\n请输入要删除结点的序号：");
	scanf("%d",&i); 
	DlinkDel(DL,i,&e);
	Print_DLinkList(DL);
	printf("\n要删除的结点的值为：%d",e);
	return 0;
}
