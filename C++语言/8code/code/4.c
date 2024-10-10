#include <stdio.h>
#include <stdlib.h>
int LeafCount; //全局变量，计算叶子结点的个数 
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
		*bt=(BiTree)malloc(sizeof(BiTNode)); //生成一个新结点
        (*bt)->data=ch;
        CreateBiTree(&((*bt)->LChild)); //生成左子树
        CreateBiTree(&((*bt)->RChild)); //生成右子树
	}
}

void PrintTree(BiTree bt,int nLayer)  /* 按竖向树状打印的二叉树 */
{
	int i;
	if(bt == NULL) return;
	PrintTree(bt->RChild,nLayer+1);
	for(i=0;i<nLayer;i++)
		printf("  ");
	printf("%c\n",bt->data);
	PrintTree(bt->LChild,nLayer+1);
}
void  PreOrder(BiTree root)    //root为指向二叉树根结点的指针
 {  if (root!=NULL)
      {PreOrder(root ->LChild); //中序遍历左子树
	   printf("%c  ",root ->data); //输出根结点            
	   PreOrder(root ->RChild); //中序遍历右子树
      }
 } 

int  main( )
{
	BiTree T;
	int layer;
	layer = 10;
	printf("按扩展先序遍历序列建立二叉树，请输入序列:\n");
    CreateBiTree(&T);
	PrintTree(T,layer);
	leaf(T); 
	printf("\n二叉树的叶子节点个数为：%d",LeafCount);
	printf("\n");
	PreOrder(T);
	 
    return 1;

}
