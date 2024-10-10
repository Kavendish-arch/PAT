#include <iostream>
#include <malloc.h>
#include <memory.h>

#define N1 53
#define HASHSIZE 41

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Node
{
	int key;
	int value;
	Node* pNext;
	Node(int k, Node* p, int v):
		key(k), pNext(p), value(v){}
};


int hashInt(int key)
{
	int iTmp = key * N1 % HASHSIZE;
	
	return iTmp;
}

int hashString(char* s)
{
	int h = 0;
	for(; *s; s++)
	{
		h = ( h * 31 + (unsigned int)*s) % HASHSIZE;
	}
	
	return h;
}

int hashFloat(float f)
{
	int h = 0;
	char *s = (char*)&f;
	
	for(int i = 0; i < sizeof(f); i++)
	{
		h = ( h * 31 + (unsigned int)*(s+i)) % HASHSIZE;
	} 
	
	return h;
}

void putChaining(Node** hashTable, int key, int value)
{
	int index = hashInt(key);
	
	Node* p = NULL;
	
	if(*(hashTable + index) == NULL)
	{
		p = new Node(key, NULL, value);
		*(hashTable + index) = p;
		
		printf("new Node(key=%d, value=%d), index=%d\n", key, value, index);
	}
	else
	{
		p = *(hashTable + index);
		
		while(p->key != key && p->pNext != NULL)
		{
			p = p->pNext;
		}
		
		if(p->key != key)
		{
			p->pNext = new Node(key, NULL, value);
			printf("new Node(key=%d, value=%d), index=%d\n", key, value, index);
		}
		else
		{
			p->value = value;
			printf("duplicated key=%d, value is changed to %d\n", key, value);
		}
	}
}

int getChaining(Node** hashTable, int key)
{
	int index = hashInt(key);
	
	Node* p = *(hashTable + index);
	
	int value = -1;
	
	if(p != NULL)
	{
		while(p->key != key && p->pNext != NULL)
		{
			p = p->pNext;
		}
		
		if(p->key == key)
		{
			value = p->value;
		}
	}
	
	return value;
}

int main(int argc, char** argv) {
	
//	for(int i = 1000000; i < 2000000; i += 50000)
//	{
//		printf("%d,", hashInt(i));
//	}
//	
//	printf("\n");
//	printf("%d\n",hashString("hello World"));
//	printf("%d\n",hashString("Mark Tunes"));
//	printf("%d\n",hashString("Tom Jerry"));
//	
//	printf("%d\n",hashFloat(0.15));
//	printf("%d\n",hashFloat(0.45));

	Node** hashTable = NULL;
	hashTable = (Node**)malloc(HASHSIZE * sizeof(Node*));
	memset(hashTable, 0, HASHSIZE * sizeof(Node*));
	
	putChaining(hashTable, 22, 10);
	putChaining(hashTable, 27, 11);
	putChaining(hashTable, 29, 12);
	putChaining(hashTable, 33, 13);
	putChaining(hashTable, 35, 14);
	
	printf("%d\n", getChaining(hashTable, 27));
	
	
	return 0;
}
