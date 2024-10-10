#include <stdio.h>
/**
 * O(n^2)
 *
 */
void printf_array(int A[], int high)
{
    printf("[");
    for (int i = 0; i < high; i++)
    {
        printf("%d,", A[i]);
    }
    printf("%d]\n", A[high]);
}
void SelectSort(int a[], int len)
{
    int minValue = a[0];
    int minValueIdx = 0;
    for (int i = 0; i < len; i++)
    {
        minValueIdx = i; // 每一轮检查都需要记录当前轮最小的值，默认为当前
        for (int j = i + 1; j < len; j++)
        {
            if (a[j] < a[minValueIdx])
            {
                minValueIdx = j;
            }
        }
        if (minValueIdx != i)
        {
            minValue = a[minValueIdx];
            a[minValueIdx] = a[i];
            a[i] = minValue;
        }
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {0, 34, 13, 15, 12, 56, 54, 46, 36, 120};
    SelectSort(a, 9);
    printf_array(a, 9);
    return 0;
}
