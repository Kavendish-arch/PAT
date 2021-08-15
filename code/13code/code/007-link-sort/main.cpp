#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Node
{
	int iData;
	Node* pNext;
	
	Node(int i, Node* p):
		iData(i), pNext(p)
	{
	}
}; 

//public class Node
//{
//	public:
//		int iData;
//		Node* pNext;
//		
//		Node(int i, Node* p)
//		{
//			this.iData = i;
//			this.pNext = p;
//		}
//};

void printLink(int iLine, Node* p)
{
	printf("%d: array[] = {", iLine);
	
	Node* pTmp = p;
	
	while(pTmp != NULL)
	{
		printf("%d", pTmp->iData);
		
		if(pTmp->pNext != NULL)
		{
			printf(",");
		}
		else
		{
			printf("}\n");
		}
		
		pTmp = pTmp->pNext;
	}
	
	return;
	
	
}

int main(int argc, char** argv) {
	Node* p = new Node(53, NULL);
	p = new Node(25, p);
	p = new Node(17, p);
	p = new Node(9, p);
	p = new Node(2, p);
	p = new Node(3, p);
	p = new Node(55, p);
	p = new Node(24, p);
	p = new Node(31, p);
	p = new Node(22, p);
	p = new Node(19, p);
	
	Node* pHead = p;
	
	printLink(999, pHead);
	
	Node *pi = p, *piPre = NULL, *piNext;
	Node *pMin, *pMinPre, *pMinNext;
	Node *pj, *pjPre;
	
	int i = 0;
	
	// piPre被初始化为NULL，如果piPre是NULL，就说明交换以前是表头。
	while(pi != NULL)
	{
		// 寻找第i小的元素，i 从 0 ~ iArrayLen-1 
		pMin = pi;
		
		pj = pi;
		pjPre = pj;
		pj = pj->pNext;
		
		while(pj != NULL)
		{
			//找第i小的元素
			if(pMin->iData > pj->iData)
			{
				pMin = pj;
				pMinPre = pjPre;
			}
			
			pjPre = pj;
			pj = pj->pNext;
		}
		
		printf("array[min] = %d\n", pMin->iData);
		printLink(i, pHead);
			
			
		//把这个元素和第i个元素交换 
		if(pMin != pi)
		{
			piNext = pi->pNext;
			pMinNext = pMin->pNext;
			
			// 如果piPre是NULL，说明pi是表头，交换后，pHead需要更新 
			if(piPre != NULL)
			{
				piPre->pNext = pMin;
			}
			else
			{
				p = pHead = pMin; 
			}
			
			if(piNext != pMin)
			{
				pMin->pNext = piNext;
				pMinPre->pNext = pi;
				pi->pNext = pMinNext;
			}
			else
			{
				pMin->pNext = pi;
				pi->pNext = pMinNext;
			}
			
			pi = pMin;
		}
		
		printLink(i, pHead);	
			
		i++;
		
		piPre = pi;
		pi = pi->pNext;
		
		system("pause");
	}
	
	
	return 0;
}
