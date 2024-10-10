
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* HuffmanCode;/*动态分配数组，存储哈夫曼编码*/

typedef struct 
{
	unsigned int weight ; /* 用来存放各个结点的权值*/
	unsigned int parent, LChild,RChild ; /*指向双亲、孩子结点的指针*/
}HTNode, * HuffmanTree;   /*动态分配数组，存储哈夫曼树*/

void select(HuffmanTree *ht,int n, int *s1, int *s2)
{
	int i;
	int min;
	for(i=1; i<=n; i++)
	{
		if((*ht)[i].parent == 0)
		{
			min = i;
			i = n+1;
		}
	}
	for(i=1; i<=n; i++)
	{
		if((*ht)[i].parent == 0)
		{
			if((*ht)[i].weight < (*ht)[min].weight)
				min = i;
		}
	}
	*s1 = min;
	for(i=1; i<=n; i++)
	{
		if((*ht)[i].parent == 0 && i!=(*s1))
		{
			min = i;
			i = n+1;
		}
	}
	for(i=1; i<=n; i++)
	{
		if((*ht)[i].parent == 0 && i!=(*s1))
		{
			if((*ht)[i].weight < (*ht)[min].weight)
				min = i;
		}
	}
	*s2 = min;
}

void CrtHuffmanTree(HuffmanTree *ht , int *w, int n)
{ /* w存放已知的n个权值，构造哈夫曼树ht */
	int m,i;
	int s1,s2;
	m=2*n-1;
	*ht=(HuffmanTree)malloc((m+1)*sizeof(HTNode));  /*0号单元未使用*/
	for(i=1;i<=n;i++) 
	{/*1-n号放叶子结点，初始化*/
		(*ht)[i].weight = w[i];
		(*ht)[i].LChild = 0;
		(*ht)[i].parent = 0;
		(*ht)[i].RChild = 0;
	}		
	for(i=n+1;i<=m;i++)
	{
		(*ht)[i].weight = 0;
		(*ht)[i].LChild = 0;
		(*ht)[i].parent = 0;
		(*ht)[i].RChild = 0;
	}    /*非叶子结点初始化*/
/*	------------初始化完毕！对应算法步骤1---------*/
	
	for(i=n+1;i<=m;i++)    /*创建非叶子结点,建哈夫曼树*/
	{  /*在(*ht)[1]~(*ht)[i-1]的范围内选择两个parent为0且weight最小的结点，其序号分别赋值给s1、s2返回*/
		select(ht,i-1,&s1,&s2);
		(*ht)[s1].parent=i;
		(*ht)[s2].parent=i;
		(*ht)[i].LChild=s1;
		(*ht)[i].RChild=s2;
		(*ht)[i].weight=(*ht)[s1].weight+(*ht)[s2].weight;
	} 
}/*哈夫曼树建立完毕*/
void outputHuffman(HuffmanTree HT, int m)
{
	if(m!=0)
	{
		printf("%d  ", HT[m].weight);
		outputHuffman(HT,HT[m].LChild);
		outputHuffman(HT,HT[m].RChild);
	}
}

void CrtHuffmanCode(HuffmanTree *ht, HuffmanCode *hc, int n)
/*从叶子结点到根，逆向求每个叶子结点对应的哈夫曼编码*/
{
	char *cd;
	int i;
	unsigned int c;
	int start;
	int p;
	hc=(HuffmanCode *)malloc((n+1)*sizeof(char *));  /*分配n个编码的头指针*/
	cd=(char * )malloc(n * sizeof(char ));  /*分配求当前编码的工作空间*/
	cd[n-1]='\0';   /*从右向左逐位存放编码，首先存放编码结束符*/
	for(i=1;i<=n;i++)  /*求n个叶子结点对应的哈夫曼编码*/
	{
		start=n-1;    /*初始化编码起始指针*/
		for(c=i,p=(*ht)[i].parent; p!=0; c=p,p=(*ht)[p].parent) /*从叶子到根结点求编码*/
			if( (*ht)[p].LChild == c) 
				cd[--start]='0';  /*左分支标0*/
			else 
				cd[--start]='1';  /*右分支标1*/
	hc[i]=(char *)malloc((n-start)*sizeof(char));  /*为第i个编码分配空间*/
	strcpy(hc[i],&cd[start]);
	}
	free(cd);
	for(i=1;i<=n;i++)
		printf("%d编码为%s\n",(*ht)[i].weight,hc[i]);
}


void main() 
{ 
	HuffmanTree HT; 
	HuffmanCode HC; 
	int *w; 
	int i,n;      // the number of elements; 
	int wei;    // the weight of a element; 
	int m;
	
	printf("input the total number of the Huffman Tree:" ); 
	scanf("%d",&n); 
	w=(int *)malloc((n+1)*sizeof(int)); 
	for(i=1;i<=n;i++)
	{ 
		printf("input the %d element's weight:",i); 
		fflush(stdin);
		scanf("%d",&wei); 
		w[i]=wei; 
	} 

	CrtHuffmanTree(&HT,w,n); 
	m = 2*n-1;
	outputHuffman(HT,m); 
	printf("\n");
	CrtHuffmanCode(&HT,&HC,n);
	
} 
