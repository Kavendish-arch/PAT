#include <iostream>
#include <malloc.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int array[] = {19,22,31,24,55,3,2,9,17,25,53};
int len = sizeof(array)/sizeof(array[0]);

int indent = 0;

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

void exchange(int* array, int i, int j)
{
	if(i != j)
	{
		int iTmp = *(array + i);
		*(array + i) = *(array + j);
		*(array + j) = iTmp;
	}
}

void printIndent(int count)
{
	for(int i = 0; i < count; i++)
	{
		printf(" ");
	}
}



void sort(int* array, int lo, int hi)
{
	indent++;
	printIndent(indent);
	printf("sort£¨array, lo=%d, hi=%d)\n", lo, hi);
	printIndent(indent);
	printArray(lo*10000+hi, array, len);
	
	if(hi <= lo)
	{
		indent--;
		return;
	}
	
	int i = lo;
	int j = hi;
	
	int pivot = *(array + lo);
	
	while(1)
	{
		while(pivot < *(array+j) && i < j)
		{
			j--;
		}
		
		*(array + i) = *(array + j);
		
		while(*(array + i) < pivot && i < j)
		{
			i++;
		}
		
		*(array + j) = *(array + i);
		
		if(i >= j)
		{
			break;
		}
	}
	
	*(array + i) = pivot;
	printIndent(indent);
	printArray(lo*10000+hi, array, len);
	
	sort(array, lo, i-1);
	sort(array, i+1, hi);
	
	
	
	indent--;
}


int main(int argc, char** argv) {
	int array[] = {19,22,31,24,55,3,2,9,17,25,53};
	
	sort(array, 0, len - 1);
	
	return 0;
}
