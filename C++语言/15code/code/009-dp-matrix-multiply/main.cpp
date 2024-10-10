#include <iostream>
#include <memory.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define N 6

int p[N+1] = {30,35,15,5,10,20,25};

// A0 ~ An-1������Aj��ά�ȣ�p[j] x p[j+1]

// ��i�У���j�У�������Aj��ʼ����Aj+i������һ��i+1�����󣬵���С������� 
// �Ե�i�У�����±��N-i-1       ====>      0 < j < N-i�� 
// 	������0�У�2�У�A2 �Լ��ļ�����ۣ�����0 
int Cost[N][N];


// �Ե�i�У���j�У��������õ�Aj ~ Aj+i�ľ�����˼���ʱ���������з֣�Rj��ʾ����A(Rj)��β���з�
// ����i��j��˵���зּ��㹫˾�ǣ� Aj ~ A(Rj)��ǰһ���ֳ��Ⱦ��� Rj- j + 1, i + 1 - ��Rj - j + 1�� = i + j - Rj 
int Route[N][N];

int getL1(int i, int j, int Rj)
{
	return Rj - j + 1;
}

int getL2(int i, int j, int Rj)
{
	return i + 1 - getL1(i, j, Rj);
}

int getI1(int i, int j, int Rj)// �зֺ󣬵�һ������Cost�е��к� 
{
	return getL1(i, j, Rj) - 1;
}

int getJ1(int i, int j, int Rj)// �зֺ󣬵�һ������Cost�е��к�
{
	return j;
}

int getI2(int i, int j, int Rj)// �зֺ󣬵ڶ�������Cost�е��к�
{
	return getL2(i, j, Rj) - 1; 
}

int getJ2(int i, int j, int Rj)// �зֺ󣬵ڶ�������Cost�е��к�
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
