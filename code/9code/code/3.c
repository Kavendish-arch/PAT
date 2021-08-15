#include <stdio.h>
#define MAX_VERTEX_NUM 20             /*��ඥ�����*/
#define AdjType int             /*��ඥ�����*/
#define INFINITY 32768             /*��ʾ����ֵ������*/
#define True 1
#define False 0
#define Error -1
#define Ok 1

typedef enum{DG, DN, UDG, UDN} GraphKind;  /*ͼ�����ࣺDG��ʾ����ͼ, DN��ʾ������, UDG��ʾ����ͼ, UDN��ʾ������*/
typedef char VertexData;    /*���趥������Ϊ�ַ���*/

typedef struct ArcNode
{
	AdjType adj;   /*������Ȩͼ����1��0��ʾ�Ƿ����ڣ��Դ�Ȩͼ����ΪȨֵ����*/
	int info;
}ArcNode;

typedef struct
{
	VertexData vexs[MAX_VERTEX_NUM];                        /*��������*/
	ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];   /*�ڽӾ���*/
	int vexnum,arcnum;          /*ͼ�Ķ������ͻ���*/
	GraphKind kind;                 /*ͼ�������־*/
}AdjMatrix;      /*(Adjacency Matrix Graph)*/

int LocateVertex(AdjMatrix *G,VertexData v)    /*�󶥵�λ�ú���*/
{
	int j=Error,k;
	for(k=0;k<G->vexnum;k++)
		if(G->vexs[k]==v)
		{ 
			j=k; 
			break; 
		}
	return(j);
}

int CreateDN(AdjMatrix *G)  /*����һ�����������ڽӾ���*/
{ 
	int i,j,k,weight; 
	VertexData v1,v2;
	printf("����ͼ�Ķ������ͻ���\n");
    scanf("%d,%d",&G->arcnum,&G->vexnum); /*����ͼ�Ķ������ͻ���*/
    for(i=0;i<G->vexnum;i++)       /*��ʼ���ڽӾ���*/
		for(j=0;j<G->vexnum;j++)
			G->arcs[i][j].adj=INFINITY;
	getchar();
    for(i=0;i<G->vexnum;i++)
	{
        printf("����ͼ�Ķ���\n");
    
		scanf("%c",&G->vexs[i]);  /* ����ͼ�Ķ���*/
		getchar();
	}
	for(k=0;k<G->arcnum;k++)
	{ 
		printf("����һ�������������㼰Ȩֵ\n");
	    
		scanf("%c,%c,%d",&v1,&v2,&weight);/*����һ�������������㼰Ȩֵ*/
		getchar();
	  	i=LocateVertex(G,v1);
	    j=LocateVertex(G,v2); 
	    G->arcs[i][j].adj=weight;  /*������*/
	} 
	return(Ok);
}

void main()
{
	AdjMatrix G;
	CreateDN(&G);
	 
}
