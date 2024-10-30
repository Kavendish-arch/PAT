#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
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
    // vector<int> sortArray(vector<int> &nums)
    void quickSort(vector<int> &nums, int low, int high)
    {
        // int low = 0, high = nums.size() - 1;
        int pivot = nums[(low + high) >> 1];
        int left = low, right = high;
        while (low < high)
        {
            // int pivo = Partition(nums, low, high);
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
        quickSort(nums, left, low - -1);
        quickSort(nums, low + 1, right);
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
    void printf_array(vector<int> A)
    {
        int high = A.size();
        printf("[");
        for (int i = 0; i < high; i++)
        {
            printf("%d,", A[i]);
        }
        printf("%d]\n", A[high]);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {5, 2, 3, 1};
    Solution so;

    vector<int> result = so.sortArray(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << " " << nums[i];
    }
    cout << endl;
    return 0;
}
