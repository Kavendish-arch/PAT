#include <iostream>
#include <stdio.h>

const int MaxVal = 9999;

const int n = 5;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double p[n+1] = {-1, 0.15, 0.1, 0.05, 0.1, 0.2};
double q[n+1] = {0.05, 0.1, 0.05, 0.05, 0.05, 0.1};

//Ϊʲô��n+1���� p[1] ~ p[n] �� n��key�����и��ʣ�p[0]����
// q[0] ~ q[n]��n+1��α�ؼ��ֵ����и��ʡ�

int root[n+1][n+1];//��¼�����
//���� root[i][j]�����е�ֵ��r��k[r]���������d[i-1]k[i]d[i]~ k[j]d[j] ���ڵ� 

double w[n+2][n+2];
double dp[n+2][n+2];
// dp[i][j] ����k[i]��k[j] => d[i-1]k[i]~k[j]d[j]����С����
// dp[i][i-1] ����ʲô�� d[i-1] ��������� d[n] => dp[n+1][n]


void optimalBST(double *p, double *q, int n)
{
	// ��ʼ�����е�d
	for(int i = 1; i <= n; i++)
	{
		w[i][i - 1] = q[i - 1];
		dp[i][i - 1] = q[i - 1];
	}
	
	// ���µ��ϣ������ң��𲽼���
	for(int len = 1; len <= n; len++)
	{
		for(int i = 1; i <= n - len + 1; i++)// ���Ŵ����ȱ䳤��i�ǵݼ���
		{
			int j = i + len - 1;
			
			dp[i][j] = MaxVal;
			w[i][j] = w[i][j-1] + p[j] + q[j];
			
			
			// ��ȡ��С���۵������ĸ� 
			for(int k = i; k <= j; k++)
			{
				double temp = dp[i][k-1] + dp[k+1][j] + w[i][j];
				
				if(temp < dp[i][j])
				{
					dp[i][j] = temp;
					root[i][j] = k;
				}
			}
		} 
	}
}

void printRoot()
{
	printf("root of sub tree:\n");
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			printf("%d ", root[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
}

void printOptimalBST(int i, int j, int r)
{
	int rootChild = root[i][j];
	if(i == 1 && j == n)
	{
		printf("k%d is root\n", rootChild);
		printOptimalBST(i, rootChild - 1, rootChild);
		printOptimalBST(rootChild + 1, j, rootChild);
		return;
	}
	
	if(j < i - 1)
	{
		return;
	}
	else if(j == i - 1)
	{
		if(j < r)
		{
			printf("d%d is a left child of k%d\n", j, r);
		}
		else
		{
			printf("d%d is a right child of k%d\n", j, r);
		}
		return;
	}
	else
	{
		if(rootChild < r)
		{
			printf("k%d is a left child of k%d\n", rootChild, r);
		}
		else
		{
			printf("k%d is a right child of k%d\n", rootChild, r);
		}
	}
	
	printOptimalBST(i, rootChild - 1, rootChild);
	printOptimalBST(rootChild + 1, j, rootChild);
}

int main(int argc, char** argv) {
	optimalBST(p, q, n);
	printRoot();
	
	printf("Tree:\n");
	printOptimalBST(1,n, -1);
	return 0;
}
