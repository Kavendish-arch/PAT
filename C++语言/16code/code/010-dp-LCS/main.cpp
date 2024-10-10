#include <iostream>
#include <memory.h>
#include <malloc.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define S1Length 7
#define S2Length 6

char S1[S1Length] = {'A','B','C','B','D','A','B'};
char S2[S2Length] = {'B','D','C','A','B','A'};

int LCS[S1Length + 1][S2Length + 2];//LCS是当前最长子串的长度。
int Route[S1Length + 1][S2Length + 2];// 1：S1是连续的，S2有间隔 2，S2是连续的，S1有间隔 3，结尾是一样，长度加1

void printMatrix(char* prompt, int (&m)[S1Length + 1][S2Length + 2])
{
	printf("%s\n", prompt);
	for(int i = 0; i <= S1Length; i++)
	{
		for(int j = 0; j <= S2Length; j++)
		{
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}
 
int main(int argc, char** argv) {
	memset(LCS, 0, sizeof(int)*(S1Length+1)*(S2Length+1));
	memset(Route, 0, sizeof(int)*(S1Length+1)*(S2Length+1));
	
	for(int i = 1; i <= S1Length; i++)
	{
		for(int j = 1; j <= S2Length; j++)
		{
			int S1p = i - 1;
			int S2p = j - 1;
			
			if(S1[S1p] == S2[S2p])
			{
				LCS[i][j] = LCS[i-1][j-1] + 1;
				Route[i][j] = 3;
			}
			else if(LCS[i-1][j] >= LCS[i][j-1])
			{
				LCS[i][j] = LCS[i-1][j];
				Route[i][j] = 2;
			}
			else
			{
				LCS[i][j] = LCS[i][j-1];
				Route[i][j] = 1;
			}
		}
	}
	
	printMatrix("LCS:", LCS);
	printMatrix("Route:", Route);
	
	char* lcs = (char*)malloc(sizeof(char)*LCS[S1Length][S2Length]);
	memset(lcs, 0, sizeof(char)*LCS[S1Length][S2Length]);
	
	int i = S1Length;
	int j = S2Length;
	int k = LCS[i][j] - 1;
	
	while(1)
	{
		if(i == 0 || j == 0)
		{
			break;
		}
		
		if(Route[i][j] == 3)
		{
			lcs[k] = S1[i - 1];// 从第一个字符串里拿出字符出来。
			k--;
			i--;
			j--; 
		}
		else if(Route[i][j] == 2)
		{
			i--;
		} 
		else
		{
			j--;
		}
		

	}
	printf("lcs:\n");
	for(k = 0; k < LCS[S1Length][S2Length]; k++)
	{
		printf("%c ", lcs[k]);
	}
	
	free(lcs);
	return 0;
}
