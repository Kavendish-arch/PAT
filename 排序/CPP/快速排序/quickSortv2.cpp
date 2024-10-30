
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
    void quickSort(vector<int> &nums, int low, int high)
    {
        if (low >= high)
        {
            return;
        }
        int pivot = nums[low + high >> 1];
        int left = low, right = high;
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
        // nums[low] = pivot;
        quickSort(nums, left, low - -1);
        quickSort(nums, low + 1, right);
    }

    // void printf_array(vector<int> A)
    // {
    //     int high = A.size();
    //     printf("[");
    //     for (int i = 0; i < high; i++)
    //     {
    //         printf("%d,", A[i]);
    //     }
    //     printf("%d]\n", A[high]);
    // }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {5, 2, 3, 1};
    Solution so;

    cout << "hell" << endl;
    so.sortArray(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << " " << nums[i];
    }
    cout << endl;
    return 0;
}
