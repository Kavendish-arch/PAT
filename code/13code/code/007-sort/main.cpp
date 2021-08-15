#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void printArray(int iLine, int* pArray, int len)
{
	printf("%d: array[] = {", iLine);
	
	for(int i = 0; i < len; i++)
	{
		if(i != len - 1)
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

int main(int argc, char** argv) {
	//��������
	int array[] = {19,22,31,24,55,3,2,9,17,25,53};
	
	int iArrayLen = 0;
	
	iArrayLen = sizeof(array)/sizeof(array[0]);
	
	
	// Ѱ�ҵ�iС��Ԫ�أ�i �� 0 ~ iArrayLen-1 
	for(int i = 0; i < iArrayLen; i++)
	{
		//�ҵ�iС��Ԫ��
		int iMinIndex = i;
		for(int j = i + 1; j < iArrayLen; j++)
		{
			if(array[iMinIndex] > array[j])
			{
				iMinIndex = j; 
			}
		}
		
		printArray(i, array, iArrayLen);
		//�����Ԫ�غ͵�i��Ԫ�ؽ��� 
		if(iMinIndex != i)
		{
			int iTmp = array[i];
			array[i] = array[iMinIndex];
			array[iMinIndex] = iTmp;
		}
		
		printf("i = %d, iMinIndex = %d\n", i, iMinIndex);
		printArray(i, array, iArrayLen);
	}
	return 0;
}
