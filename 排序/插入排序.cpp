#include <stdio.h>

void printf_array(int A[], int high)
{
    printf("[");
    for (int i = 0; i < high; i++)
    {
        printf("%d,", A[i]);
    }
    printf("%d]\n", A[high]);
}

// int binary_search(int a[], int low, int high, int target)
// {
//     while (low <= high)
//     {
//         int mid = low + (high - low) / 2;
//         if (a[mid] <= target && a[mid + 1] > target)
//         {
//             return mid + 1;
//         }
//         if (a[mid] > target)
//         {
//             high = mid - 1;
//         }
//         if (a[mid] < target)
//         {
//             low = mid;
//         }
//     }
//     return -1;
// }
void insert_sort(int a[], int len)
{
    int i, j, tmp;
    for (i = 1; i <= len; i++)
    {
        if (a[i] < a[i - 1])
        {
            tmp = a[i];
            for (j = i - 1; a[j] >= tmp; --j)
            {
                a[j + 1] = a[j];
            }
            a[j + 1] = tmp;
        }
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {3, 34, 13, 15, 12, 56, 54, 46, 36};
    insert_sort(a, 8);
    printf_array(a, 8);
    return 0;
}
