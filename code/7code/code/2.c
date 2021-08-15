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
{  if(S->top==(StackSize-1))  return(0);  //栈已满
   S->top++;
   S->elem[S->top]=x;
   return(1);

 }

int Pop(SeqStack *S,StackElementType *x)
{ // 将栈S的栈顶元素弹出，放到x所指的存储空间中 
  if(S->top==-1) return(0);//栈为空
  else	{
	  *x=S->elem[S->top];
	  S->top--;    // 修改栈顶指针
  	  return(1);  }
 }

int GetTop(SeqStack *S, StackElementType *x)
{  // 读出栈顶元素赋值给x所指空间，但栈顶指针保持不变
	if(S->top==-1) return(0);  //栈为空
	else
	{ *x = S->elem[S->top];    //top不变
	  return(1);  }	
}   

int IsEmpty(SeqStack *S)  //也可SeqStack S
{   return(S->top==-1?1:0);   } 

 
void main()
{ SeqStack T;int i,x;
  InitStack(&T);
  printf("输入入栈的数据(整数型，0结束)：");
  scanf("%d",&x); 
  while(x!=0){
  	Push(&T,x)	;
  	printf("输入入栈的数据(整数型，0结束)：");
    scanf("%d",&x); 
  } 
  Pop(&T,&x);
  printf("出栈的数据为：%d\n",x);
   Pop(&T,&x);
  printf("出栈的数据为：%d\n",x); 
  
}
