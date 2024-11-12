/**
 * 简单
 * 1006 换个格式输出整数 (15 分)
 * 让我们用字母 B 来表示“百”、字母 S 表示“十”，用 12...n 来表示不为零的个位数字 n（<10），换个格式来输出任一个不超过 3 位的正整数。例如 234 应该被输出为 BBSSS1234，因为它有 2 个“百”、3 个“十”、以及个位的 4。
 */

#include<stdio.h>
int main(){
    int n = 0;
    scanf("%d",&n);
    int g = 0, s = 0, b = 0;
    g = n % 10;
    b = n / 100; 
    s = (n-b*100) / 10;
    for (int i = 0; i < b; i++)
    {
        printf("B");
    }
    for (int i = 0; i < s; i++)
    {
        printf("S");
    }
    for (int i = 0; i < g; i++)
    {
        printf("%d",i+1);
    }
    printf("\n");
    return 0;
}
