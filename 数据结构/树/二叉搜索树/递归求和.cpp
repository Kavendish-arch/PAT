/**
 * @file 递归 求和 求积
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
/**
 * 递归求和 
 * @param n 
 * @return int 
 */
int sumNums(int n){
    if(n == 1)
    {
        return 1;
    }
    else
    {
        return n + sumNums(n-1);
    }
}
/*递归实现乘法*/
int _multiply(int A, int B){
    if(B == 1) {
        return A;
    }
    else {
        return A + _multiply(A, B-1);
    }
}
int multiply(int A, int B){
    int x = A > B ? A : B;
    int y = A > B ? B : A;
    return _multiply(x, y);
}
/**
 * @brief 
 * 递归求阶乘 
 * @param n 待求阶乘
 * @return int 返回阶乘的值
 */
int factorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n-1);
    }
}

int fibonacci(int n)
{
    if( n <= 1){
        return 1;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
/**
 * 递归算乘方
 * @param x 
 * @param n 
 * @return double 
 */
double _myPow(double x, int n){
    if(n == 0)
    {
        return 1.0;
    }
    else
    {
        double tmp = _myPow(x, n/2);
        if(n % 2 == 0)
        {
            return tmp * tmp;
        }
        else 
        {
            return tmp * tmp * x;
        }
    }
}
double myPow(double x, int n){
    return n >= 0 ? _myPow(x,n) : 1/_myPow(x, -n);
}
int move(int n, int from, int to, int by){
    printf("move %d from %d to %d by\n",n, from, to, by);
}
void hanoi(int n, int from, int to, int by){
    if(n == 1)
    {
        move(n, from, to, by);
    }
    else
    {
        hanoi(n-1, from, by, to);
        move(n, from, to, by);
        hanoi(n-1, by, to, from);
    }
}
void moveAtoC(int* A, int ASize, int** C, int* CSize){
    *C[*CSize] = A[ASize];
    *CSize++;
    ASize--;
}
void moveAtoB(int* A, int ASize, int* B, int BSize, int** C, int* CSize){
    B[BSize++]= A[ASize--];
}
void moveBtoC(int* A, int ASize, int* B, int BSize, int** C, int* CSize){
    *C[*CSize] = B[BSize--];
    *CSize++;
}
void hanota(int* A, int ASize, int* B, int BSize, int** C, int* CSize){
    if(ASize == 1)
    {
        moveAtoC(A, ASize, C, CSize);
    }
    else
    {
        moveAtoB(A, ASize, B, BSize, C, CSize);
        hanota(A, ASize, B, BSize, C, CSize);
        moveAtoC(A, ASize, C, CSize);
        moveBtoC(A, ASize, B, BSize, C, CSize);
        hanota(A, ASize, B, BSize, C, CSize);
    }
}
int main(int argc, char const *argv[])
{

    hanoi(3,1,3,2);
    return 0;
}
