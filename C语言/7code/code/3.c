#include "stdio.h"
#define  TRUE 1
#define  FALSE 0
#define MAXSIZE 50  /*队列的最大长度*/

typedef struct
{
	int element[MAXSIZE];  /* 队列的元素空间*/
	int front;  /*头指针指示器*/
	int rear;  /*尾指针指示器*/
}SeqQueue;


/*初始化操作*/
void InitQueue(SeqQueue *Q)
{  
	/* 将*Q初始化为一个空的循环队列 */
	Q->front=Q->rear=0;
}

int IsEmpty(SeqQueue *Q)
{
	if(Q->front==Q->rear)  //队列为空
		return(TRUE);
	else return FALSE;

}

/*入队操作*/
int EnterQueue(SeqQueue *Q, int x)
{  
	/*将元素x入队*/
	if((Q->rear+1)%MAXSIZE==Q->front)  /*队列已经满了*/
		return(FALSE);
	Q->element[Q->rear]=x;
	Q->rear=(Q->rear+1)%MAXSIZE;  /* 重新设置队尾指针 */
	return(TRUE);  /*操作成功*/
}

/*出队操作*/
int DeleteQueue(SeqQueue *Q, int *x)
{ 
	/*删除队列的队头元素，用x返回其值*/
	if(Q->front==Q->rear)  /*队列为空*/
		return(FALSE);
	*x=Q->element[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;  /*重新设置队头指针*/
	return(TRUE);  /*操作成功*/
}

int GetHead(SeqQueue *Q, int *x)
{ 
	/*提取队列的队头元素，用x返回其值*/
	if(Q->front==Q->rear)  /*队列为空*/
		return(FALSE);
	*x=Q->element[Q->front];
	return(TRUE);  /*操作成功*/
}

void YangHuiTriangle( )
{ 
	int n;
	int i;
	int temp;
	int x;
	int N;
	SeqQueue Q;
	InitQueue(&Q);
	EnterQueue(&Q,1);  /* 第一行元素入队*/
	printf("please input N:");
	scanf("%d",&N);
	for(n=2;n<=N;n++)   /* 产生第n行元素并入队，同时打印第n-1行的元素*/
	{
		EnterQueue(&Q,1);   /* 第n行的第一个元素入队*/
		for(i=1;i<=n-2;i++)  /* 利用队中第n-1行元素产生第n行的中间n-2个元素并入队*/
		{
			DeleteQueue(&Q,&temp);
			printf("%6d",temp);     /* 打印第n-1行的元素*/
			GetHead(&Q,&x);
			temp=temp+x;      /*利用队中第n-1行元素产生第n行元素*/
			EnterQueue(&Q,temp);  
		}
		DeleteQueue (&Q,&x);  
		printf("%6d",x);    /* 打印第n-1行的最后一个元素*/
		EnterQueue(&Q,1);   /* 第n行的最后一个元素入队*/
		printf("\n");
	}
  while(!IsEmpty(&Q))        //打印第n行元素
 { DeleteQueue(&Q,&x);         
   printf("%6d",x); }

}

void main()
{
	YangHuiTriangle( );
}
