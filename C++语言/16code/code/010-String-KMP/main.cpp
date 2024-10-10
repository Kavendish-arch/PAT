#include <iostream>
#include <memory.h>
#include <malloc.h>
#include <string.h>

#define R 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void KMP(int* dfa, int* pX, int M, char* pPat)
{
	memset(dfa, 0, R*M*sizeof(int));
	memset(pX, 0, M*sizeof(int));
	
	int r = (unsigned int)*(pPat) - (unsigned int)'A';
	
	*(dfa + r * M) = 1;
	
	for(int X = 0, j = 1; j < M; j++)
	{
		for(int c = 0; c < R; c++)
		{
			*(dfa + c * M + j) = *(dfa + c * M + X);
		}
		
		r = (unsigned int)*(pPat+j) - (unsigned int)'A';
		
		*(dfa + r * M + j) = j + 1;
		
		*(pX + j - 1) = X;
		
		X = *(dfa + r * M + X);
	}
	
}

int search(char* pText, int N, int* dfa, int M)
{
	int i, j, r;
	
	for(i = 0, j = 0; i < N && j < M; i++)
	{
		r = (unsigned int)*(pText+i) - (unsigned int)'A';
		j = *(dfa + r * M + j);
	}
	
	if(j == M)
	{
		return i - M;
	}
	else
	{
		return N;
	}
}

printDFA(int* dfa, int r, int M)
{
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < M; j++)
		{
			printf("%d ", *(dfa + i * M + j));
		}
		printf("\n");
	}
}

printX(int *pX, int M)
{
	for(int j = 0; j < M; j++)
	{
		printf("%d ", *(pX + j));
	}
	printf("\n");
}

int main(int argc, char** argv) {
	char text[] = "AAABBBCCABABABCABABCDB"; // A
	int N = strlen(text);
	
	char pat[] = "ABABCABABCD";
	int M = strlen(pat);
	
	int* dfa = (int*)malloc(R*M*sizeof(int));
	int* pX = (int*)malloc(M*sizeof(int));
	
	KMP(dfa, pX, M, (char*)&pat);
	printDFA(dfa, R, M);
	printf("\n");
	printX(pX, M);
	
	printf("\n%d%n", search((char*)&text, N, dfa, M));
	
	return 0;
}
