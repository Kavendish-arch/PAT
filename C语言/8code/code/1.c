

#include "stdio.h"
#include <stdlib.h> 
#define MAXSIZE 1000  /*����Ԫ�صĸ������Ϊ1000*/
#define ElementType int
/*ϡ�������Ԫ�������Ͷ���*/	
typedef struct
{   
	int row,col;  /*�÷���Ԫ�ص����±�����±�*/
    ElementType e; /*�÷���Ԫ�ص�ֵ*/
}Triple;

typedef struct
{  
	Triple data[MAXSIZE+1];   
	int m,n,len;          
}TSMatrix;

void TransMatrix(ElementType source[3][4],ElementType dest[4][3])
{
	
	int i,j;
	for(i=0;i<3;i++)
		for (j=0;j<4;j++)
			dest[j][i]=source[i][j];
}

main()
{
	int i,j;
	ElementType source[3][4]={{11,12,0,0},{13,14,0,0},{15,16,0,0}},dest[4][3];
	TransMatrix(source,dest);
	for( i=0;i<4;i++)
	{	
		for(j=0;j<3;j++)
	      printf("%5d ",dest[i][j]);
	
	    printf("\n");
	}

}
