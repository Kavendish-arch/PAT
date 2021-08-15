#include <iostream>
#include <memory.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define N 6

int p[N+1] = {30,35,15,5,10,20,25};

// A0 ~ An-1个矩阵，Aj的维度，p[j] x p[j+1]

// 第i行，第j列，代表，从Aj开始，到Aj+i结束，一共i+1个矩阵，的最小计算代价 
// 对第i行，最大下标的N-i-1       ====>      0 < j < N-i， 
// 	举例：0行，2列，A2 自己的计算代价，都是0 
int Cost[N][N];


// 对第i行，第j列，代表计算得到Aj ~ Aj+i的矩阵相乘计算时，从哪里切分：Rj表示，从A(Rj)的尾部切分
// 对于i，j来说，切分计算公司是： Aj ~ A(Rj)，前一部分长度就是 Rj- j + 1, i + 1 - （Rj - j + 1） = i + j - Rj 
int Route[N][N];

int getL1(int i, int j, int Rj)
{
	return Rj - j + 1;
}

int getL2(int i, int j, int Rj)
{
	return i + 1 - getL1(i, j, Rj);
}

int getI1(int i, int j, int Rj)// 切分后，第一分组在Cost中的行号 
{
	return getL1(i, j, Rj) - 1;
}

int getJ1(int i, int j, int Rj)// 切分后，第一分组在Cost中的列号
{
	return j;
}

int getI2(int i, int j, int Rj)// 切分后，第二分组在Cost中的行号
{
	return getL2(i, j, Rj) - 1; 
}

int getJ2(int i, int j, int Rj)// 切分后，第二分组在Cost中的列号
{
	return Rj + 1; 
}

int getMatrixLines(int j)
{
	return p[j];
}

int getMatrixColumns(int j)
{
	return p[j+1];
}

int main(int argc, char** argv) {
	return 0;
}
