#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
void printf_array(vector<int> &A)
{
    int high = A.size();
    printf("[");
    for (int i = 0; i < high; i++)
    {
        printf("%2d,", A[i]);
    }
    printf("]\n");
}
class Solution
{
public:
    // vector<int> sortArray(vector<int> &nums)
    // {
    //     int low = 0, high = nums.size() - 1;
    //     quick_sort(nums, low, high);
    //     return nums;
    // }
    // void quick_sort(vector<int> &nums, int low, int high)
    // {
    //     if (low < high)
    //     {
    //         int pivo = Partition(nums, low, high);
    //         // printf_array(nums);
    //         quick_sort(nums, low, pivo - 1);
    //         quick_sort(nums, pivo + 1, high);
    //     }
    // }
    // int Partition(vector<int> &nums, int low, int high)
    // {
    //     int pivot = nums[low];
    //     while (low < high)
    //     {
    //         while (low < high && nums[high] >= pivot)
    //         {
    //             high--;
    //         }
    //         nums[low] = nums[high];
    //         while (low < high && nums[low] <= pivot)
    //         {
    //             low++;
    //         }
    //         nums[high] = nums[low];
    //     }
    //     nums[low] = pivot;
    //     return low;
    // }
    void HeapAdjust(vector<int> &nums, int s, int m)
    {
        int top = nums[s];
        for (int j = 2 * s + 1; j <= m; )
        {
            if (j < m && nums[j] < nums[j + 1])
            {
                j++;
            }
            if (top >= nums[j])
            {
                break;
            }
            nums[s] = nums[j];
            s = j;

            j =  j * 2 + 1;
        }
        nums[s] = top;
    }
    void swap(int &a, int &b)
    {
        int x = a;
        a = b;
        b = x;
    }

    vector<int> sortArray(vector<int> &nums)
    // void HeapSort(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            HeapAdjust(nums, i, n - 1);
        }
        for (int i = n - 1; i > 0; i--)
        {
            swap(nums[0], nums[i]);
            HeapAdjust(nums, 0, i - 1);
        }

        return nums;
    }
};

int main(int argc, char const *argv[])
{
    // vector<int> a = {1, 4, 2, 3, 5, 6, 7, 8};
    vector<int> a = {5, 2, 3, 1};
    // vector<int> a = {5};
    Solution so;
    so.sortArray(a);
    printf_array(a);
    return 0;
}
