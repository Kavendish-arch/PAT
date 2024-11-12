#include<stdio.h>
/**
 * 问题一：一行内不定项输入
 * 
 * 错误一：数组一定要考虑 数组越界，段错误
 * 错误二：变量一定要赋初值，flag变量未赋初值，结果错误
 */
int main() {
    int n,a[1004];
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
    int flag1 = 0,flag2 = 0,flag3 = 0,flag4 = 0,flag5 = 0;
    int a2_n = 1, a4_len = 0;
    
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        int tab = a[i] % 5;
        switch (tab)
        {
        case 0:
            if (a[i] % 2 == 0)
            {
                a1 += a[i];
                flag1 = 1;
            }
            break;
        case 1:
            a2 += a[i] * a2_n;
            a2_n *= -1;
            flag2 = 1;
            break;
        case 2:
            a3++;
            flag3 = 1;
            break;
        case 3:
            a4 += a[i]; 
            a4_len++;
            flag4 = 1; 
            break;
        case 4:
            if (a[i] > a5)
            {
                a5 = a[i];
            }
            flag5 = 1; 
            break;
        }

    }
    if (flag1 == 1)
    {
        printf("%d ",a1);
    }
    else
    {
        printf("N ");
    }

    if (flag2 == 1)
    {
        printf("%d ", a2);
    }
    else
    {
        printf("N ");
    }
    if (flag3 == 1)
    {
        printf("%d ", a3);
    }
    else
    {
        printf("N ");
    }
    if (flag4 == 1)
    {
        float t = a4 * 1.0 / a4_len;
        printf("%.1f ", t);
    }
    else
    {
        printf("N ");
    }
    if (flag5 == 1)
    {
        printf("%d\n",a5);
    }
    else
    {
        printf("N\n");
    }
    return 0;
}
