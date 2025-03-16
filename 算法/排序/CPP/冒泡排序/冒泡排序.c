#include <stdio.h>

#include <iostream>
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
bool cmp(int a, int b)
{
    return a > b;
}
void bubble_sort(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(&a[i], &a[j]);
            }
        }
    }
}

void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 5, 4, 6, 3, 7, 2, 8};
    // bubble_sort(a,8);
    // select_sort(a,8);
    // count_sort(a, 8);
    _merge_sort(a, 0, 7);
    print_array(a, 8);
    return 0;
}
