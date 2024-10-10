#include <stdio.h>
#include <stdlib.h>
int LeafCount; //ȫ�ֱ���������Ҷ�ӽ��ĸ��� 
typedef char DataType;

typedef struct Node
{
	DataType data;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode, *BiTree;


void leaf(BiTree root)
{
	if(root!=NULL)
	{
		leaf(root->LChild);
		leaf(root->RChild);
		if (root ->LChild==NULL && root ->RChild==NULL)
			LeafCount++;
	}
}
void CreateBiTree(BiTree *bt)
{
	char ch;
	ch = getchar();
    if(ch=='.') *bt=NULL;
    else 
	{
		*bt=(BiTree)malloc(sizeof(BiTNode)); //����һ���½��
        (*bt)->data=ch;
        CreateBiTree(&((*bt)->LChild)); //����������
        CreateBiTree(&((*bt)->RChild)); //����������
	}
}

void PrintTree(BiTree bt,int nLayer)  /* ��������״��ӡ�Ķ����� */
{
	int i;
	if(bt == NULL) return;
	PrintTree(bt->RChild,nLayer+1);
	for(i=0;i<nLayer;i++)
		printf("  ");
	printf("%c\n",bt->data);
	PrintTree(bt->LChild,nLayer+1);
}
void  PreOrder(BiTree root)    //rootΪָ�������������ָ�몤
 {  if (root!=NULL)
      {PreOrder(root ->LChild); //���������������
	   printf("%c  ",root ->data); //��������            
	   PreOrder(root ->RChild); //���������������
      }
 } 

int  main( )
{
	BiTree T;
	int layer;
	layer = 10;
	printf("����չ����������н���������������������:\n");
    CreateBiTree(&T);
	PrintTree(T,layer);
	leaf(T); 
	printf("\n��������Ҷ�ӽڵ����Ϊ��%d",LeafCount);
	printf("\n");
	PreOrder(T);
	 
    return 1;

}
