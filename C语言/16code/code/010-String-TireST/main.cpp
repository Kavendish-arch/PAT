#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define R 256

struct Node
{
	int value;
	Node** pNext;
	
	Node(int v):
		value(v)
	{
		pNext = new Node*[R];
		memset(pNext, 0, sizeof(Node*)*R);
	}
	
	~Node()
	{
		delete[] pNext;
		pNext = NULL;
	}
};

Node* get(Node* p, char* pKey, int d)
{
	if(p == NULL)
	{
		return NULL;
	}
	
	if(d == strlen(pKey))
	{
		return p;
		
	}
	
	char c = *(pKey+d);
	
	return get(*(p->pNext+(unsigned int)c), pKey, d+1);
}

Node* put(Node* p, char* pKey, int v, int d)
{
	if(p == NULL)
	{
		p = new Node(-1);
	}
	
	if(d == strlen(pKey))
	{
		p->value = v;
		return p;
	}
	
	char c = *(pKey+d);
	
	*(p->pNext + (unsigned int)c) = put(*(p->pNext + (unsigned int)c), pKey, v, d+1);
	
	return p;
}

int main(int argc, char** argv) {
	Node* root = NULL;
	
	root = put(root, "abc",1, 0);
	
	printf("[abc] = %d\n", get(root, "abc", 0)->value);
	printf("[ac] = %d\n", get(root, "ac", 0));
	
	return 0;
}
