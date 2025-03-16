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
    // 75
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

    void sortColors(vector<int> &nums)
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
                int minValue = nums[idx];
                nums[idx] = nums[i];
                nums[i] = minValue;
            }
        }
    }

    /**
    4. 寻找两个正序数组的中位数
    困难
    给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和
    nums2。请你找出并返回这两个正序数组的 中位数 。

    算法的时间复杂度应该为 O(log (m+n)) 。

    @todo 目前时间复杂度 O(m+n)^2
 */
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        for (int i = 0; i < nums2.size(); ++i)
        {
            nums1.push_back(nums2[i]);
        }
        sortColors(nums1);
        int n = nums1.size();
        if (n % 2)
        {
            return nums1[n / 2];
        }
        else
        {
            return (nums1[n / 2 - 1] + nums1[n / 2]) / 2.0;
        }
    }

    /*
    747. 至少是其他数字两倍的最大数
    请你找出数组中的最大元素并检查它是否 至少是数组中每个其他数字的两倍 。如果是，则返回 最大元素的下标 ，否则返回 -1 。
    */
    int dominantIndex(vector<int> &nums)
    {
        int idx = 0;
        int max = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > max)
            {
                idx = i;
                max = nums[i];
            }
        }
        for (int j = 0; j < nums.size(); ++j)
        {
            if (j != idx && nums[idx] < nums[j] * 2)
            {
                return -1;
            }
        }
        return idx;
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
