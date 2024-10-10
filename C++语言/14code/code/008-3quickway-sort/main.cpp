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
	printf("sort(array, lo=%d, hi=%d)\n", lo, hi);
	printIndent(indent);
	printArray(lo*10000+hi, array, len); 

	if(hi <= lo)
	{
		indent--;
		return;
	}
	
	int lt = lo;
	int i = lo + 1;
	int gt = hi;
	int pivot = *(array + lo);
	
	while(i <= gt)
	{
		if(*(array+i) < pivot)//i的位置小，把i位置的数填写到lt上
		{
			exchange(array, lt, i);
			lt++;
			i++; 
		}
		else if(*(array+i) == pivot)// 等于的时候，i就是相等的集合，所以不用动，i++ 
		{
			i++;
		}
		else // i的位置是大的 
		{
			if(*(array + gt) > pivot) // 大于，说明需要留在最右端
			{
				gt--; 
			}
			else if(*(array + gt) == pivot)// gt的位置是等于的，而i的位置是大的
			{
				exchange(array, i, gt);
				i++;
				gt--;
			}
			else // i是大的，gt是小的，lt是等于 
			{
				int iTmp = *(array + lt);
				*(array + lt) = *(array + gt); 
				*(array + gt) = *(array + i);
				*(array + i) = iTmp;
				
				lt++;
				i++;
				gt--;
				
			}
		}
	}
	
	printIndent(indent);
	printf("in sort: lt=%d, i=%d, gt=%d\n", lt, i, gt);
	
	
	printIndent(indent);
	printArray(lo*10000+hi, array, len);
	
	sort(array, lo, lt-1);
	sort(array, gt+1, hi);
	
	indent--;
}


int main(int argc, char** argv) {
	int array[] = {19,22,31,24,55,3,2,9,17,25,53};
	
	sort(array, 0, len - 1);
	
	return 0;
}
