#include<stdio.h>
#include<iostream>
using namespace std;
void Perm(char list[], int k, int m);
int main(){
	char list[4] = { 'a','b','c','d' };
//	Perm(list, 0, 3);
	system("pause");
}

void Perm(char list[], int k, int m){
	//��k��m��ʼȫ���� 
	if (k == m){
		for (int i = 0; i <= m; i++)
			cout << list[i];
		cout << endl;
	}
	else {
		for (int i = k; i <= m; i++){
			swap(list[k], list[i]);
			Perm(list, k + 1, m);
			swap(list[k], list[i]);
			}
	}
		
}
