#include <iostream>
#include <stdio.h>

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
	// 排序数组
	int array[] = {19,22,31,24,55,3,2,9,17,25,53};
	
	int iArrayLen = sizeof(array)/sizeof(array[0]);
	
	int iTmp = 0;
	
	// i 从 1 ~ iArray - 1 作为每次插入到前面升序序列的参考数 
	for(int i = 1; i < iArrayLen; i++)
	{
		// j 从 i ~  0 比较 array[j-1] 和 array[i]，如果 array[j-1] > array[i]说明不是插入位置，前移
		// 如果j = 1是最后一个，到j = 1时，说明要插到最前面。 
		printArray(i, array, iArrayLen);
		for(int j = i; j > 0; j--)
		{
			if(array[j-1] <= array[i])
			{
				if(j != i)
				{
					iTmp = array[i];
					memmove(((int*)array) + j + 1, ((const int*)array) + j, (i-j)*sizeof(int));
					
					array[j] = iTmp;
					printf("%d:Found position: %d\n",i, j);
				}
				break;
			}
			
			// if not hit any break;
			if(j == 1)
			{
				iTmp = array[i];
				memmove(((int*)array) + 1, ((const int*)array), i * sizeof(int));
				
				array[0] = iTmp;
				printf("%d:Found position: 0\n", i);
				break;
			}
		}
		
		printArray(i, array, iArrayLen);
		system("pause");
	} 
	
	return 0;
}
