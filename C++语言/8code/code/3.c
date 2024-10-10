#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 1000  /*非零元素的个数最多为1000*/
#define ElementType int


typedef struct
{   
	int row,col;  /*该非零元素的行下标和列下标*/
    ElementType e; /*该非零元素的值*/
}Triple;

typedef struct
{  
	Triple data[MAXSIZE+1];   /* 非零元素的三元组表。data[0]未用*/
	int m,n,len;          /*矩阵的行数、列数和非零元素的个数*/
}TSMatrix;



void FastTransposeTSMatrix(TSMatrix A,TSMatrix *B)
{ 

	int col,t,p,q;
	int num[MAXSIZE], position[MAXSIZE];
	B->len=A.len; 
	B->n=A.m; 
	B->m=A.n;
	if(B->len)
	{
		for(col=1;col<=A.n;col++)
			num[col]=0;  
		for(t=1;t<=A.len;t++)
			num[A.data[t].col]++; 
		position[1]=1;
		for(col=2;col<=A.n;col++) 
			position[col]=position[col-1]+num[col-1]; 
		for(p=1;p<=A.len;p++)
		{  
			col=A.data[p].col;  
			q=position[col];
			B->data[q].row=A.data[p].col;
			B->data[q].col=A.data[p].row;
			B->data[q].e=A.data[p].e;
			position[col]++;
		}
	}
}


void main()
{
	int i;
	int a[8]={1,1,3,3,4,5,6,6};  //行标 
	int b[8]={2,3,1,6,3,2,1,4};//列标 
	int c[8]={12,13,14,15,16,17,18,19};//非零元素	
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
	FastTransposeTSMatrix(A,B);	
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
