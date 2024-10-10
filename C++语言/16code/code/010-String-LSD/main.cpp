#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <assert.h>
#define LENGTH 4
#define WORDLENGTH 3
#define CHARLENGTH 256

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

printName(char *name[LENGTH])
{
	printf("\n");
	for(int i = 0; i < LENGTH; i++)
	{
		printf("%s\n", name[i]);
	}
}

void sort(char *name[LENGTH], int W)// W 深度，对哪一位进行比较
{
	for(int d = W - 1; d >= 0; d--)
	{
		int count[CHARLENGTH];
		memset(&count, 0, (CHARLENGTH)*sizeof(int));
		
		
		// 统计频率
		for(int i = 0; i < LENGTH; i++)
		{
			count[(unsigned int)name[i][d]]++;
		} 
		
		// 生成索引
		for(int i = 1; i < CHARLENGTH; i++)
		{
			count[i] = count[i] + count[i-1];
		}
		
		// 分类
		char *tmp[LENGTH];
		for(int i = 0; i < LENGTH; i++)
		{
			tmp[count[name[i][d]] - 1] = name[i];
			count[name[i][d]]--;
		}
		
		// 回写
		for(int i = 0; i < LENGTH; i++)
		{
			name[i] = tmp[i];
		}
		
		printName(name);
	}
} 

int main(int argc, char** argv) {
	char *name[LENGTH] = {
		"abc",
		"def",
		"ape",
		"apc"
	};
	
	sort(name, WORDLENGTH);
	
	return 0;
}
