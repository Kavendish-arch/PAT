#include <stdio.h>        //˫���ѭ������ 
#include <stdlib.h>
#define ElemType int
#define ERROR -1
#define OK 1

typedef struct DNode
{ ElemType data; 
  struct DNode  *prior,*next; 
}DNode,*DoubleList;

int DlinkIns(DoubleList L,int i,ElemType e)
{  DNode *s,*p;  //��p���֮ǰ����s���
   int k;
   p=L;  k=0;       //�ӡ�ͷ����ʼ�����ҵ�i����㣬�൱��ͷ�����0�Ž��
   while(p->next!=L&&k<i) //�ҵ�β�ڵ�û�ҵ�������k==i����
	{ p=p->next;
	  k=k+1; }							     
   if(p->next==L&&k!=i) //����λ�ò�����i��ֵ�����ʴ�����
	{ printf("����λ�ò�����!");
	  return ERROR;}
   s=(DNode*)malloc(sizeof(DNode)); //p�Ѿ�λ����ʼ����s���ռ�   
if (s) 				//s�ռ�����ɹ�
	{
		s->data=e;
			
		p->prior->next=s;	//������߹�ϵ
			s->prior=p->prior;
				
		p->prior=s;		//�����ұ߹�ϵ
			s->next=p;	
		return OK;
	}
else 	return ERROR;
}


void Init_DLinklist(DoubleList *H) //LinkListΪָ����
{ *H=(DoubleList)malloc(sizeof(DNode)); //����һ�����ռ�
  (*H)->next=*H;                  
  (*H)->prior=*H; 
 }
void Creat_DLinkList(DoubleList L)
{   char c;
    static int i=1;
    DoubleList s;
    printf("�������%d������ֵ",i);
    scanf("%d",&c);
    if(c!=-1){
    s=(DNode*)malloc(sizeof(DNode)); 
    s->data=c;
    L->next=s;
    s->prior=L;
    L->prior=s;
    s->next=L;
	}
    
    printf("�������%d������ֵ",i+1);
	scanf("%d",&c);
	while(c!=-1)  //����-1���� 
	 { 	DlinkIns(L,1,c); //�ڵ�һ�����֮ǰ���룬ͷ�巨 
	 	i++;
	 	printf("�������%d������ֵ",i+1);
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
{ DNode  *p;          //pָ��Ҫɾ���Ľ��
  int k;
  p=L;  k=0;    //�ӡ�ͷ����ʼ�����ҵ�i����㣬ͷ����൱�ڵ�0�����
  while(p->next!=L && k<i) //�ҵ�i�����
	{ p=p->next;
	  k=k+1; }
  if(p->next==L&&k<i)  return ERROR;  //��β���Ҳδ�ҵ�i��㣬i̫��
  else	{ *e=p->data;     //��ɾ������ֵ��eָ����ظ���������
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
	printf("\n������Ҫɾ��������ţ�");
	scanf("%d",&i); 
	DlinkDel(DL,i,&e);
	Print_DLinkList(DL);
	printf("\nҪɾ���Ľ���ֵΪ��%d",e);
	return 0;
}
