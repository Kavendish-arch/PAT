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
	// Cost�����ǵ� 0��1��2��3�У��ֱ��Ӧ��B��A��C��B��D��C��������D����һ����ĳ���ʱ�����
	int Route[LINE][STEPS];
	// Route�����ǵ� 0��1��2��3�У� �ֱ��Ӧ��B��A��C��B��D��C��������D�����Լ�ʱ����̵��Ǹ������ߵ�ǰ����ѡ��
	
	printf("A:\n");
	printMatrix(A);
	
	int CostForIJ[LINE];
	
	for(int j = 0; j < STEPS; j++)
	{
		for(int i = 0; i < LINE; i++)
		{
			for(int k = 0; k < LINE; k++)
			{
				if(j == 0) //��B��Aʱ��A�ĳ��Ŵ��۾���A���Լ���ʱ����� 
				{
					CostForIJ[k] = A[k][j];// ��B��Aʱ�����ʱ����� 
				}
				else
				{
					CostForIJ[k] = A[k][j] + Cost[k][j-1];
				}
				
				CostForIJ[k] += calMoveCost(i,k);// �ӵ�j+1����ĵ�iԪ�ؿ����� j����Ĵ��ۡ� 
			}
			
			int minValue = CostForIJ[0];
			int minIndex = 0;
			
			for(int k = 0; k < LINE; k++)// Ѱ����С���ۣ��Լ���Դ·��
			{
				if(CostForIJ[k] < minValue)
				{
					minValue = CostForIJ[k];
					minIndex = k;
				} 
			}
			
			// �Ѽ���������Cost��Route
			Cost[i][j] = minValue;
			Route[i][j] = minIndex; 
			 
		}
	}
	
	printf("Cost:\n");
	printMatrix(Cost);
	
	printf("Route:\n");
	printMatrix(Route);
	
	
	
	// �ҵ��ӳ�����������С���۵�D�ǵڼ��� 
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
