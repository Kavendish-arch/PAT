#include <stdio.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        quick_sort(nums, 0, nums.size() - 1);

        return nums[nums.size() - k];
    }
    void quick_sort(vector<int> &nums, int low, int high)
    {
        if (low < high)
        {
            int pivo = Partition(nums, low, high);
            quick_sort(nums, low, pivo - 1);
            quick_sort(nums, pivo + 1, high);
        }
    }
    int Partition(vector<int> &nums, int low, int high)
    {
        int pivot = nums[low];
        while (low < high)
        {
            while (low < high && nums[high] >= pivot)
            {
                high--;
            }
            nums[low] = nums[high];
            while (low < high && nums[low] <= pivot)
            {
                low++;
            }
            nums[high] = nums[low];
        }
        nums[low] = pivot;
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
    void SelectSort(int a[], int len)
    {
        int minValue = a[0];
        int minValueIdx = 0;
        for (int i = 0; i < len; i++)
        {
            minValueIdx = i; // 每一轮检查都需要记录当前轮最小的值，默认为当前
            minValue = a[i];
            for (int j = i + 1; j < len; j++)
            {
                if (a[j] < minValue)
                {
                    minValueIdx = j;
                    minValue = a[j];
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

    void SelectSort(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int idx = i;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] < nums[idx])
                {
                    idx = j;
                }
            }
            if (idx != i)
            {
                int minValue = a[idx];
                a[idx] = a[i];
                a[i] = minValue;
            }
        }
    }
};

/**
 * O(n^2)
 *
 */

int main(int argc, char const *argv[])
{
    int a[] = {0, 34, 13, 15, 12, 56, 54, 46, 36, 120};
    SelectSort(a, 9);
    printf_array(a, 9);
    return 0;
}
