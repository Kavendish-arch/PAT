#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct tNode
{
	int key;
	int value;
	tNode* pLeft;
	tNode* pRight;
	tNode* pParent;
	int N;
	
	tNode(int k, tNode* pL, tNode* pR, tNode* pP, int v)
	{
		key = k;
		pLeft = pL;
		pRight = pR;
		pParent = pP;
		value = v;
		N = 1;
	}
	
	tNode(int k, tNode* pP, int v)
	{
		new (this)tNode(k, NULL, NULL, pP, v); 
	} 
};

void printTreeNode(tNode* root)
{
	tNode* pP = NULL;
	
	if(root != NULL)
	{
		pP = root->pParent;
		if(pP != NULL)
		{
			printf("(key=%d,pKey=%d,N=%d)", root->key, pP->key, root->N);
		}
		else
		{
			printf("(key=%d,pKey=(NULL),N=%d)", root->key, root->N);
		}
	}
	else
	{
		printf("(NULL)");
	}
}

void printTreeMiddle(tNode* root)
{
	if(root != NULL)
	{
		printTreeMiddle(root->pLeft);
		printTreeNode(root);
		printTreeMiddle(root->pRight);
	}
}

int size(tNode* x)
{
	if(x == NULL)
	{
		return 0;
	}
	else
	{
		return x->N;
	}
}

tNode* put(tNode* x, int key, int value)
{
	if(x == NULL)
	{
		return new tNode(key, NULL, value);
	}
	
	if(key < x->key)
	{
		x->pLeft = put(x->pLeft, key, value);
		
		if(x->pLeft->pParent == NULL)
		{
			x->pLeft->pParent = x;
		}
	}
	else if(key > x->key)
	{
		x->pRight = put(x->pRight, key, value);
		if(x->pRight->pParent == NULL)
		{
			x->pRight->pParent = x;
		}
	}
	else
	{
		x->value = value;
	}
	
	x->N = size(x->pLeft) + size(x->pRight) + 1;
	
	return x;
}

tNode* get(tNode* x, int key)
{
	if(x == NULL)
	{
		return NULL;
	}
	
	if(key < x->key)
	{
		return get(x->pLeft, key);
	}
	else if(key > x->key)
	{
		return get(x->pRight, key);
	}
	else
	{
		return x;
	}
	
}

int main(int argc, char** argv) {
	int array[] = {19,22,31,24,55,3,2,9,17,25,53};
	int len = sizeof(array)/sizeof(array[0]); 
	
	tNode* root = NULL;
	
	for(int i = 0; i < len; i++)
	{
		root = put(root, array[i], array[i]);
	}
	
	printTreeMiddle(root);
	
	printf("\n");
	printTreeNode(get(root, 31));
	printTreeNode(get(root, 30));
	
	return 0;
}
