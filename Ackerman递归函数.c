#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int Ackerman(int m, int n);
int main(){
	int m, n, sum;
	cin >> m >> n;
	sum = Ackerman(n, m);
	cout << sum;
	system("pause");
	return 0;
}
int Ackerman(int m, int n){
	if (n == 1 && m == 0)
		return 2;
	if (n == 0 && m >= 0)
		return 1;
	if (n >= 2 && m == 0)
		return n + 2;
	if (m >= 1 && n >= 1)
		Ackerman(Ackerman(n - 1, m), m - 1);
}