#include <stdio.h>
#include <stdlib.h>


typedef char DataType;

typedef struct Node
{
	DataType data;
	int      Ltag;
	int      Rtag;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode, *BiTree;

BiTree pre;

void CreateBiTree(BiTree *bt)//先序扩展 
{
	char ch;
	ch = getchar();
    if(ch=='.') *bt=NULL;
    else 
	{
		*bt=(BiTree)malloc(sizeof(BiTNode)); //生成一个新结点
        (*bt)->data=ch;
		(*bt)->Ltag=0;
		(*bt)->Rtag=0;
        CreateBiTree(&((*bt)->LChild)); //生成左子树
        CreateBiTree(&((*bt)->RChild)); //生成右子树
	}
}

void  Inthread(BiTree root)
/* 对root所指的二叉树进行中序线索化，其中pre始终指向刚访问过的结点，其初值为NULL*/
{
	if (root!=NULL)
	{ 
		Inthread(root->LChild);  /* 线索化左子树 */
		if (root->LChild==NULL)
		{
			root->Ltag=1; 
			root->LChild=pre;  /*置前驱线索 */
		}
		if (pre!=NULL&& pre->RChild==NULL)  /* 置后继线索 */
		{
			pre->RChild=root;
			pre->Rtag=1;
		}
	pre=root;
	Inthread(root->RChild);  /*线索化右子树*/
	}
}	

BiTNode * InPre(BiTNode *p)
/* 在中序线索二叉树中查找p的中序前驱, 并用pre指针返回结果 */
{  
	BiTNode *q;
	if(p->Ltag==1)
		pre = p->LChild;  /*直接利用线索*/
	else 
	{ /* 在p的左子树中查找"最右下端"结点 */
		for(q = p->LChild;q->Rtag==0;q=q->RChild);
		pre=q;
	}
	return(pre);
}


BiTNode * InNext(BiTNode * p) 
/*在中序线索二叉树中查找p的中序后继结点，并用next指针返回结果*/
{ 
	BiTNode *Next;
	BiTNode *q;
	if (p->Rtag==1)  
		Next = p->RChild;  /*直接利用线索*/
	else
	{ /*在p的右子树中查找"最左下端"结点*/
		if(p->RChild!=NULL)
		{
			for(q=p->RChild; q->Ltag==0 ;q=q->LChild);
			Next=q; 
		}
		else
			Next = NULL;
		
	} 
	return(Next);
}

BiTNode* TinFirst(BiTree root)//第一个访问的节点 
{
	BiTNode *p;
	p = root;
	if(p)
		while(p->LChild!=NULL)
			p=p->LChild;
	return p;
}

void TinOrder(BiTree root)  // 按中序输出序列 
{
	BiTNode *p;
	p=TinFirst(root);
	while(p!=NULL)
	{
		printf("%c  ",p->data);
		p=InNext(p);
	}
}

void InsNode(BiTNode *p ,  BiTNode *r)  //在线索树中，r插入p成为p的右孩子 
{
	BiTNode *s;
	if(p->Rtag==1)    /* p无右孩子 */
	{
		r->RChild=p->RChild;  /* p的后继变为r的后继 */
		r->Rtag=1;
		p->RChild=r;  /* r成为p的右孩子 */
		r->LChild=p;  /* p变为r的前驱 */
		r->Ltag=1;
	}
	else  /* p有右孩子 */
	{ 
		s=p->RChild;
		while(s->Ltag==0)
			s=s->LChild;  /* 查找p结点的右子树的"最左下端"结点 */
		r->RChild=p->RChild;  /* p的右孩子变为r的右孩子 */
		r->Rtag=0;
		r->LChild=p;  /* p变为r的前驱 */
		r->Ltag=1;
		p->RChild=r;  /* r变为p的右孩子 */
		s->LChild=r;  /* r变为p原来右子树的"最左下端"结点的前驱 */
	}
}

void main()
{
	BiTree T;
	BiTree p,q;
	BiTNode *r;
	printf("按扩展先序遍历序列建立二叉树，请输入序列:\n");
    CreateBiTree(&T);

	pre = NULL;
	Inthread(T);
    p=T->LChild->RChild;

	q =InPre(p);
	printf("\n前驱为%c",q->data);
	q =InNext(p);
	printf("\n后继为%c",q->data);
	printf("\n");

	q=TinFirst(T);
	printf("\n第一个结点为%c",q->data);

	r=(BiTNode*)malloc(sizeof(BiTNode));
	r->data = 'Q';
	r->LChild = NULL;
	r->RChild = NULL;
	r->Ltag = 0;
	r->Rtag = 0;
	InsNode(p,r);

	printf("插入Q之后遍历线索树:\n");
    TinOrder(T);//中序 


}
