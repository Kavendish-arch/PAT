#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
	ElemType elem[MAXSIZE];
	int last;
}SeqList;

SeqList *InitList(  ) 
{  SeqList *p;
   p=(SeqList *)malloc(sizeof(SeqList));
   p->last = -1;
   return p;   }

int Locate(SeqList *L, ElemType e)
{ int i;
  for (i=0;i<=L->last;i++)
      if (L->elem[i]==e) return i+1;
  return -1;
}
ElemType GetData(SeqList *L,int i)
{
  if(i<=L->last+1) return L->elem[i-1];
  else printf("%d is wrong\n",i);
}

void main()
{ int i;
  SeqList *p;
  p=InitList( );
  printf("%d\n",p->last);//显示-1 
  for(i=0;i<10;i++) p->elem[i]=i+50;//50，51，52，53。。。59 
  p->last=i-1;//9写入last，表示最后一个元素下标 
  i=Locate(p,53); //返回4 
  printf("%d\n",i);
  printf("%d\n",GetData(p,5));  //显示54 
}
