#include "stdio.h"
#define StackSize 50 
#define StackElementType int
typedef struct
{ StackElementType elem[StackSize]; 
  int  top;
 }SeqStack; 

void InitStack(SeqStack *S)
{  S->top = -1;}

int Push(SeqStack *S,StackElementType x)
{  if(S->top==(StackSize-1))  return(0);  //ջ����
   S->top++;
   S->elem[S->top]=x;
   return(1);

 }

int Pop(SeqStack *S,StackElementType *x)
{ // ��ջS��ջ��Ԫ�ص������ŵ�x��ָ�Ĵ洢�ռ��� 
  if(S->top==-1) return(0);//ջΪ��
  else	{
	  *x=S->elem[S->top];
	  S->top--;    // �޸�ջ��ָ��
  	  return(1);  }
 }

int GetTop(SeqStack *S, StackElementType *x)
{  // ����ջ��Ԫ�ظ�ֵ��x��ָ�ռ䣬��ջ��ָ�뱣�ֲ���
	if(S->top==-1) return(0);  //ջΪ��
	else
	{ *x = S->elem[S->top];    //top����
	  return(1);  }	
}   

int IsEmpty(SeqStack *S)  //Ҳ��SeqStack S
{   return(S->top==-1?1:0);   } 

 
void main()
{ SeqStack T;int i,x;
  InitStack(&T);
  printf("������ջ������(�����ͣ�0����)��");
  scanf("%d",&x); 
  while(x!=0){
  	Push(&T,x)	;
  	printf("������ջ������(�����ͣ�0����)��");
    scanf("%d",&x); 
  } 
  Pop(&T,&x);
  printf("��ջ������Ϊ��%d\n",x);
   Pop(&T,&x);
  printf("��ջ������Ϊ��%d\n",x); 
  
}
