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
	
	// piPre����ʼ��ΪNULL�����piPre��NULL����˵��������ǰ�Ǳ�ͷ��
	while(pi != NULL)
	{
		// Ѱ�ҵ�iС��Ԫ�أ�i �� 0 ~ iArrayLen-1 
		pMin = pi;
		
		pj = pi;
		pjPre = pj;
		pj = pj->pNext;
		
		while(pj != NULL)
		{
			//�ҵ�iС��Ԫ��
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
			
			
		//�����Ԫ�غ͵�i��Ԫ�ؽ��� 
		if(pMin != pi)
		{
			piNext = pi->pNext;
			pMinNext = pMin->pNext;
			
			// ���piPre��NULL��˵��pi�Ǳ�ͷ��������pHead��Ҫ���� 
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
