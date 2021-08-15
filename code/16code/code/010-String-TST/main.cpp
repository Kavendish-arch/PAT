#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Node
{
	char ch;
	Node* pLeft;
	Node* pMid;
	Node* pRight;
	int value;
	
	Node(char c, int v):
		ch(c), value(v), pLeft(NULL), pMid(NULL), pRight(NULL)\
	{
	}
};

Node* get(Node* p, char* pKey, int d)
{
	if(p == NULL)
	{
		return NULL;
	}
	
	char c = *(pKey+d);
	
	if((unsigned int)c < (unsigned int)(p->ch))
	{
		return get(p->pLeft, pKey, d);
	}
	else if((unsigned int)c > (unsigned int)(p->ch))
	{
		return get(p->pRight, pKey, d);
	}
	else if(d < strlen(pKey) - 1)
	{
		return get(p->pMid, pKey, d+1);
	}
	else
	{
		return p;
	}
}

Node* put(Node* p, char* pKey, int v, int d)
{
	char c = *(pKey+d);
	
	if(p == NULL)
	{
		p = new Node(c,v);
	}
	
	if((unsigned int)c < (unsigned int)(p->ch))
	{
		p->pLeft = put(p->pLeft, pKey, v, d);
	}
	else if((unsigned int)c > (unsigned int)(p->ch))
	{
		p->pRight = put(p->pRight, pKey, v, d);
	}
	else if(d < strlen(pKey) - 1)
	{
		p->pMid = put(p->pMid, pKey, v, d+1);
	}
	else
	{
		p->value = v;
	}
	
	return p;
}

int main(int argc, char** argv) {
	
	Node* root = NULL;
	root = put(root, "abc", 1, 0);
	
	printf("[abc] = %d\n", get(root, "abc", 0)->value);
	printf("[ac] = %d\n", get(root, "ac", 0));
	return 0;
}
