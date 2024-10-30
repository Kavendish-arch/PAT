#include <stdio.h>

#include <iostream>

#include <stdio.h>

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void bubbleSort(vector<int> &nums)
    {
        /**
         * 冒泡思想 ==0 冒泡
         *
         */
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    swap(&nums[j], &nums[j + 1]);
                }
            }
        }
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
    void print_array(int *a, int n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
    }
    void print_array(vector<int> nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            cout << " " << nums[i];
        }
        cout << endl;
    }
    void print_array(vector<int> &a, int n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        cout << endl;
    }
};

/**
 * @brief
 *
 * @param a
 * @param n
 */
void count_sort(int *a, int n)
{
    int *result = (int *)malloc(sizeof(int) * n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        result[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        result[a[i]]++;
    }
    for (int i = 0, k = 0; i < n + 1; i++)
    {
        if (result[i] > 0)
        {

            for (int j = 0; j < result[i]; j++)
            {
                a[k++] = i;
            }
        }
    }
}

void _merge(int *a, int l_a, int *b, int l_b, int *result);

void _merge_sort(int *a, int head, int tail)
{

    if (tail - head == 1)
    {
        _merge(a, 1, a, 1, a);
    }

    int mid = (tail - head) / 2 + head;
    _merge_sort(a, head, mid);
    _merge_sort(a, mid + 1, tail);
}

void _merge(int *a, int l_a, int *b, int l_b, int *result)
{
    int j = 0, k = 0;
    for (int i = 0; i < l_a + l_b; i++)
    {

        if (k < l_a && j < l_b)
        {
            if (a[k] <= b[j])
            {
                result[i] = a[k];
                k++;
            }
            else
            {
                result[i] = b[j++];
            }
        }
        else if (k >= l_a)
        {
            result[i] = b[j++];
        }
        else if (j >= l_b)
        {
            result[i] = a[k++];
        }
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 5, 4, 6, 3, 7, 2, 8};
    vector<int> nums = {1, 5, 4, 6, 3, 7, 2, 8};
    Solution so;
    so.bubbleSort(nums);
    so.print_array(nums);
    // bubble_sort(a,8);
    // select_sort(a,8);
    // count_sort(a, 8);
    // _merge_sort(a, 0, 7);
    // print_array(a, 8);
    return 0;
}
