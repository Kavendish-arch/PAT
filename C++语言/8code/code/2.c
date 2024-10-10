#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 1000  /*����Ԫ�صĸ������Ϊ1000*/
#define ElementType int


typedef struct
{   
	int row,col;  /*�÷���Ԫ�ص����±�����±�*/
    ElementType e; /*�÷���Ԫ�ص�ֵ*/
}Triple;

typedef struct
{  
	Triple data[MAXSIZE+1];   /* ����Ԫ�ص���Ԫ���data[0]δ��*/
	int m,n,len;          /*����������������ͷ���Ԫ�صĸ���*/
}TSMatrix;



void TransposeTSMatrix(TSMatrix A,TSMatrix *B)
{ /*�Ѿ���Aת�õ�B��ָ��ľ�����ȥ����������Ԫ����ʾ*/
	int i,j,k;
	B->m=A.n; 
	B->n=A.m; 
	B->len=A.len;
	if(B->len>0)
	{
		j=1;				
		for(k=1; k<=A.n; k++) 
			for(i=1; i<=A.len; i++)
				if(A.data[i].col==k)
				{
					B->data[j].row=A.data[i].col;
					B->data[j].col=A.data[i].row;
					B->data[j].e=A.data[i].e;
					j++;		
				}
	}
}


void main()
{
	int i;
	int a[8]={1,1,3,3,4,5,6,6};  //�б� 
	int b[8]={2,3,1,6,3,2,1,4};//�б� 
	int c[8]={12,13,14,15,16,17,18,19};//����Ԫ��	
	TSMatrix A;
	TSMatrix *B;
	A.n=8; 
	A.m=8; 
	A.len=8;
	B=(TSMatrix *)malloc(sizeof(TSMatrix));
	for(i=0;i<8;i++)
	{
		A.data[i+1].row=a[i];	
		A.data[i+1].col=b[i];
		A.data[i+1].e=c[i];
	}
	TransposeTSMatrix(A,B);	
	for(i=1;i<=8;i++)
	{
		printf("%3d",B->data[i].row);	
	}
	printf("\n");
	for(i=1;i<=8;i++)
	{	
		printf("%3d",B->data[i].col);
	}
	printf("\n");
	for(i=1;i<=8;i++)
	{
		printf("%3d",B->data[i].e);
	}
	printf("\n");
	getchar();
}
