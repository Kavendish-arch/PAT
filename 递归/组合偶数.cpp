#include <stdio.h>
#include <stdlib.h>

int partition(int *A, int low ,int high) {
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
void quick_sort(int *a, int low, int high) {
    if (low < high) {
        int pivo = partition(a, low, high);
        quick_sort(a, low, pivo-1);
        quick_sort(a, pivo+1, high);
    }
}
int* findEvenNumbers(int* digits, int digitsSize, int* returnSize){

    int *ret = (int*) malloc(sizeof(int) * digitsSize);
    int top = 0;
    quick_sort(digits,0,digitsSize);
    for(int i = 0;i < digitsSize; i++){
        if(digits[i] == 0)
        {
            continue;
        }
        for(int j = 0; j <digitsSize; j++)
        {   
            if(j == i)
            {
                continue;
            }
            for(int k = 0; k < digitsSize; k++){
                if(digits[k] % 2 != 0 || k == j || k == i)
                {
                    continue;
                }
                int re = digits[i] * 100 + digits[j] * 10 + digits[k];
                ret[top++] = re;
            }
        }
    }
    *returnSize = top;
    return ret;
}


int main(int argc, char const *argv[])
{
    int a[] = {1,2,3};
    int sz = 0;
    int *f = findEvenNumbers(a, 3, &sz);
    for(int i = 0; i < sz; i++)
    {
        printf("%d, ",f[i]);
    }
    return 0;
}
