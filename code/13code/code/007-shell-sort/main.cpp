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
	
	int array[] = {19,22,31,24,55,3,2,9,17,25,53};
	
	
	int iArrayLen = sizeof(array)/sizeof(array[0]);
	int iTmp = 0;
	
	int h = 1;
	while(h < iArrayLen/3)
	{
		h = 3 * h + 1;
	}
	
	while(h>=1)
	{
		for(int i = h; i < iArrayLen; i++)
		{
			for(int j = i; j >= h; j -= h)
			{
				if(array[j-h] > array[j])
				{
					iTmp = array[j-h];
					array[j-h] = array[j];
					array[j] = iTmp;
				}
				else
				{
					break;
				}
				
			}
		}
		
		printArray(h, array, iArrayLen);
		
		system("pause");
		h = h/3;
	}
	return 0;
}
