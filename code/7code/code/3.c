#include "stdio.h"
#define  TRUE 1
#define  FALSE 0
#define MAXSIZE 50  /*���е���󳤶�*/

typedef struct
{
	int element[MAXSIZE];  /* ���е�Ԫ�ؿռ�*/
	int front;  /*ͷָ��ָʾ��*/
	int rear;  /*βָ��ָʾ��*/
}SeqQueue;


/*��ʼ������*/
void InitQueue(SeqQueue *Q)
{  
	/* ��*Q��ʼ��Ϊһ���յ�ѭ������ */
	Q->front=Q->rear=0;
}

int IsEmpty(SeqQueue *Q)
{
	if(Q->front==Q->rear)  //����Ϊ��
		return(TRUE);
	else return FALSE;

}

/*��Ӳ���*/
int EnterQueue(SeqQueue *Q, int x)
{  
	/*��Ԫ��x���*/
	if((Q->rear+1)%MAXSIZE==Q->front)  /*�����Ѿ�����*/
		return(FALSE);
	Q->element[Q->rear]=x;
	Q->rear=(Q->rear+1)%MAXSIZE;  /* �������ö�βָ�� */
	return(TRUE);  /*�����ɹ�*/
}

/*���Ӳ���*/
int DeleteQueue(SeqQueue *Q, int *x)
{ 
	/*ɾ�����еĶ�ͷԪ�أ���x������ֵ*/
	if(Q->front==Q->rear)  /*����Ϊ��*/
		return(FALSE);
	*x=Q->element[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;  /*�������ö�ͷָ��*/
	return(TRUE);  /*�����ɹ�*/
}

int GetHead(SeqQueue *Q, int *x)
{ 
	/*��ȡ���еĶ�ͷԪ�أ���x������ֵ*/
	if(Q->front==Q->rear)  /*����Ϊ��*/
		return(FALSE);
	*x=Q->element[Q->front];
	return(TRUE);  /*�����ɹ�*/
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
	EnterQueue(&Q,1);  /* ��һ��Ԫ�����*/
	printf("please input N:");
	scanf("%d",&N);
	for(n=2;n<=N;n++)   /* ������n��Ԫ�ز���ӣ�ͬʱ��ӡ��n-1�е�Ԫ��*/
	{
		EnterQueue(&Q,1);   /* ��n�еĵ�һ��Ԫ�����*/
		for(i=1;i<=n-2;i++)  /* ���ö��е�n-1��Ԫ�ز�����n�е��м�n-2��Ԫ�ز����*/
		{
			DeleteQueue(&Q,&temp);
			printf("%6d",temp);     /* ��ӡ��n-1�е�Ԫ��*/
			GetHead(&Q,&x);
			temp=temp+x;      /*���ö��е�n-1��Ԫ�ز�����n��Ԫ��*/
			EnterQueue(&Q,temp);  
		}
		DeleteQueue (&Q,&x);  
		printf("%6d",x);    /* ��ӡ��n-1�е����һ��Ԫ��*/
		EnterQueue(&Q,1);   /* ��n�е����һ��Ԫ�����*/
		printf("\n");
	}
  while(!IsEmpty(&Q))        //��ӡ��n��Ԫ��
 { DeleteQueue(&Q,&x);         
   printf("%6d",x); }

}

void main()
{
	YangHuiTriangle( );
}
