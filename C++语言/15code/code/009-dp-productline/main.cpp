#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define LINE 3
#define STEPS 4
#define MOVECOST 2

int A[LINE][STEPS] = {{9,7,9,3}, {9,11,5,2}, {7,9,7,6}};

void printMatrix(int (&m)[LINE][STEPS])
{
	for(int i = 0; i < LINE; i++)
	{
		for(int j = 0; j < STEPS; j++)
		{
			if(j == 0)
			{
				printf("(%d", m[i][j]);
			}
			else
			{
				printf(",%d", m[i][j]);
			}
		}
		
		printf(")\n");
	}
}

int calMoveCost(int l1, int l2)
{
	int gap = l2 - l1;
	
	if(gap < 0)
	{
		gap = -gap;
	}
	
	return gap * MOVECOST; 
}

int main(int argc, char** argv) {
	int Cost[LINE][STEPS];
	// Cost数组是第 0，1，2，3列，分别对应，B看A，C看B，D看C，出厂看D，上一工序的出门时间损耗
	int Route[LINE][STEPS];
	// Route数组是第 0，1，2，3列， 分别对应，B看A，C看B，D看C，出厂看D，到自己时间最短的那个生产线的前序工序选择。
	
	printf("A:\n");
	printMatrix(A);
	
	int CostForIJ[LINE];
	
	for(int j = 0; j < STEPS; j++)
	{
		for(int i = 0; i < LINE; i++)
		{
			for(int k = 0; k < LINE; k++)
			{
				if(j == 0) //在B看A时，A的出门代价就是A列自己的时间代价 
				{
					CostForIJ[k] = A[k][j];// 在B看A时，获得时间代价 
				}
				else
				{
					CostForIJ[k] = A[k][j] + Cost[k][j-1];
				}
				
				CostForIJ[k] += calMoveCost(i,k);// 从第j+1工序的第i元素看来， j工序的代价。 
			}
			
			int minValue = CostForIJ[0];
			int minIndex = 0;
			
			for(int k = 0; k < LINE; k++)// 寻找最小代价，以及来源路径
			{
				if(CostForIJ[k] < minValue)
				{
					minValue = CostForIJ[k];
					minIndex = k;
				} 
			}
			
			// 把计算结果放入Cost和Route
			Cost[i][j] = minValue;
			Route[i][j] = minIndex; 
			 
		}
	}
	
	printf("Cost:\n");
	printMatrix(Cost);
	
	printf("Route:\n");
	printMatrix(Route);
	
	
	
	// 找到从出厂看来，最小代价的D是第几个 
	int minValue = Cost[0][STEPS-1];
	int minIndex = 0;
	for(int k = 0; k < LINE; k++)
	{
		if(Cost[k][STEPS-1] < minValue)
		{
			minValue = Cost[k][STEPS-1];
			minIndex = k;
		}
	}
	
	printf("\nmin Cost: %d\n", minValue); 

	int r[STEPS];
	
	for(int k = STEPS - 1; k >= 0; k--)
	{
		r[k] = Route[minIndex][k];
		minIndex = Route[minIndex][k-1];
	}
	
	for(int k = 0; k < STEPS; k++)
	{
		printf("%d ->", r[k]);
	}
	return 0;
}
