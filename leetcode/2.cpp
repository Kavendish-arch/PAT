#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * 动态规划算法
 * 
 */
int maxSubArray(int* nums, int numsSize){
    int array[numsSize] = {0};
    array[0] = nums[0];
    
    for (int i = 1; i < numsSize; i++)
    {
        if (array[i-1] <= 0){
            array[i] = nums[i];

        } else {
            array[i] = nums[i] + array[i-1];

        }
    }
    
    for (int i = 0; i < numsSize; i++)
    {
        // printf("%d, ",array[i]);
    }
    // printf("\n");
    int x = 0, max = array[0], h = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (array[i] > 0 && array[i-1] <= 0){
            h = i;
        }
        if (array[i] > max) {
            max = array[i];
            x = i;
        }
    }
    // printf("%d - > %d = %d",h, x, max);
    return array[numsSize-1];
}
/**
 * 0 1 2 3 
 * 1 2 3 4
 */
int fib(int n){
    int * array = (int*) malloc (sizeof(int) * n);
    for (int i = 0; i <= n; i++) {
        array[i] = 1;
    }
 
    for (int i = 2; i < n; i++)
    {
        array[i] = array[i-1] + array[i-2];
    }
    return array[n-1];
}
int tribonacci(int n){
    int * array = (int*) malloc (sizeof(int) * (n + 1));
    for (int i = 0; i <= n + 1; i++) {
        array[i] = 1;
    }
    array[0] = 0;
 
    for (int i = 3; i <= n; i++)
    {
        array[i] = array[i-1] + array[i-2] + array[i-3];
    }
    return array[n];
}
int main(int argc, char const *argv[])
{
    int num[10];
    // memset(num, 20, 10);
    // for (int i = 0; i < 10; i++) {
        // printf("%d, ", num[i]);
    // }
    
    // printf("\n\n%d ", maxSubArray(num, 4));
    // printf("%d \t ", fib(0));
    // tribonacci(5);
    printf("%d", tribonacci(5));
    return 0;
}
