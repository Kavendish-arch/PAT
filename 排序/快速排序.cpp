#include <stdio.h>
#define max 7

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
            --high;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            ++low;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}
void printf_array(int A[], int high)
{
    printf("[");
    for (int i = 0; i < high; i++)
    {
        printf("%d,", A[i]);
    }
    printf("%d]\n", A[high]);
}

void quick_sort(int a[], int low, int high)
{
    if (low < high)
    {
        printf_array(a, max);
        int pivo = partition(a, low, high);
        quick_sort(a, low, pivo - 1);
        quick_sort(a, pivo + 1, high);
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {34, 13, 15, 12, 56, 54, 46, 36};
    quick_sort(a, 0, 7);
    return 0;
}
