#include <iostream>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int array[] = {0,19,22,31,24,55,3,2,9,17,25,53};
int len = sizeof(array)/sizeof(array[0]) - 1;

void printArray(int iLine, int* pArray, int len)
{
	printf("%d: array[] = {", iLine);
	
	for(int i = 1; i <= len; i++)
	{
		if(i != len)
		{
			printf("%d,", *(pArray+i));
		}
		else
		{
			printf("%d}\n", *(pArray+i));
		}
	}
	
	return;
}

void exchange(int* array, int i, int j)
{
	if(i != j)
	{
		int iTmp = *(array + i);
		*(array + i) = *(array + j);
		*(array + j) = iTmp;
	}
}

void sink(int* array, int k, int N) // �Ѵ�1��ʼ���������ԣ�N���Ǹ�����Ҳ�������±�
{
	while(2*k <= N)
	{
		int j = 2*k;
		if(2*k + 1 <= N)// ˵������������ 
		{
			if(*(array + j) < *(array + j + 1))
			{
				j = j + 1;//������ӽڵ�������ӽڵ㣬��ôjָ�����ӽڵ㣬˭������˭ 
			}
		} 
		
		if(*(array + k) >= *(array + j))
		{
			break;
		}
		
		exchange(array, k, j);
		
		k = j;
	}
} 

int main(int argc, char** argv) {
	
	printArray(0, array, len);
	
	for(int k = len/2; k >= 1; k--)
	{
		sink(array, k, len);
		printArray(k, array, len);
	}
	
	int N = len;
	
	while(N > 1)
	{
		exchange(array, 1, N);
		N--;
		printArray(N*10, array, len);
		sink(array, 1, N);
		printArray(N*10+1, array, len);
	}
	
	printArray(999, array, len);
	return 0;
}
