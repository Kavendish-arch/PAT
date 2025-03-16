/**
 * @file 查找算法.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-01-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
using namespace std;

template <typename T>
int const &_mBinarySearch(T &nums, int left, int right, T const &target)
{
    int len = sizeof(nums) / sizeof(T);
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[mid] > target)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return target;
}
template <typename T>
bool cmp(T a, T b)
{
    return a > b ? true : false;
}
/**
 * @brief
 * 二分查找
 * @param nums
 * @param numsSize
 * @param target
 * @return int
 */
int search(int *nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        if (nums[mid] > target)
        {
            right = mid - 1;
        }
    }
    return -1;
}

/**
 * @brief
 * 求开方
 * 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
    由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
    注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5
 * @param x
 * @return int
 */
int mySqrt(int x)
{
    if (x < 0)
    {
        return -1;
    }
    int left = 1, right = x;
    if (x == 1 || x == 0)
    {
        return x;
    }
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mid == x / mid)
        {
            return mid;
        }

        if (mid < x / mid)
        {
            left = mid;
        }

        if (mid > x / mid)
        {
            right = mid;
        }

        if ((mid < x / mid) && ((mid + 1) > x / (mid + 1)))
        {
            return mid;
        }
    }
    return -1;
}

/**
 * @brief
 * 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
 * @param nums
 * @param numsSize
 * @return int
 */
int missingNumber(int *nums, int numsSize)
{
    int flag[numsSize] = {0};
    for (int i = 0; i < numsSize; i++)
    {
        flag[nums[i]] = 1;
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (flag[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief
 * 矩阵搜索
 * 1. M*N级别
 * 2. M * logn
 *
 * @param argc
 * @param argv
 * @return int
 */
int countNegatives(int **grid, int gridSize, int *gridColSize)
{
    int cout = 0;
    int row = 0, col = gridSize;
    {
        if (grid[row][col] >= 0)
        {
            row++;
            col++;
        }
        if (grid[row][col] < 0)
        {
        }
    }
}
/**
 * @brief
 * 峰值元素是指其值严格大于左右相邻值的元素。
    给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。
    你可以假设 nums[-1] = nums[n] = -∞ 。
    你必须实现时间复杂度为 O(log n) 的算法来解决此问题。

边界值处理：
    [1]
    [1,2]

方法一: 一个一个查找
方法二：
方法三：二分查找，关键在于如何决定查找方向：
    当 mid-1 < mid < mid + 1, 上坡时，向后走
    当 mid-1 < mid > mid + 1 返回，找到了
    当 mid-1 > mid > mid + 1 向前走，
    mid-1 > mid < mid + 1 随便走
    nums[-1] = nums[n] = -无穷
 * @param nums
 * @param numsSize
 * @return int
 */
int findPeakElement(int *nums, int numsSize)
{
    if (numsSize == 1)
    {
        return 0;
    }
    if (numsSize == 2)
    {
        return nums[0] > nums[1] ? 0 : 1;
    }
    if (nums[0] > nums[1])
    {
        return 0;
    }
    if (nums[numsSize - 1] > nums[numsSize - 2])
    {
        return numsSize - 1;
    }
    // for(int i = 1; i < numsSize - 1; i++)
    // {
    //     if(nums[i-1] < nums[i] && (nums[i] > nums[i+1]))
    //     {
    //         return i;
    //     }

    // }

    int left = 1, right = numsSize - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid + 1])
        {
            return mid;
        }
        if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1])
        {
            left = mid + 1;
        }
        if (nums[mid - 1] > nums[mid] && nums[mid] > nums[mid + 1])
        {
            right = mid;
        }
        else
        {
            right = mid;
        }
    }
}
bool cmp(int start, int mid, int end, int *nums, int numSize)
{
}
/**
 * @brief
 * 给你一个排序后的字符列表 letters ，列表中只包含小写英文字母。另给出一个目标字母 target，请你寻找在这一有序列表里比目标字母大的最小字母。
在比较时，字母是依序循环出现的。举个例子：
如果目标字母 target = 'z' 并且字符列表为 letters = ['a', 'b']，则答案返回 'a'
 * @param letters
 * @param lettersSize
 * @param target
 * @return char
 */
char nextGreatestLetter(char *letters, int lettersSize, char target)
{
    if (target < letters[0] || target >= letters[lettersSize - 1])
    {
        return letters[0];
    }

    int left = 1, right = lettersSize - 2;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (letters[mid] <= target && target < letters[mid + 1])
        {
            return letters[mid + 1];
        }
        else if (letters[mid] <= target)
        {
            left = mid + 1;
        }
        else if (letters[mid] > target)
        {
            right = mid;
        }
    }
    return letters[0];
}

int searchInsert(int *nums, int numsSize, int target)
{
    if (target <= nums[0])
    {
        return 0;
    }
    if (target > nums[numsSize - 1])
    {
        return numsSize;
    }
    if (target = nums[numsSize - 1])
    {
        return numsSize - 1;
    }
    int left = 0, right = numsSize - 2;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[mid] < target && nums[mid + 1] > target)
        {
            return mid + 1;
        }
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortedSquares(int *nums, int numsSize, int *returnSize)
{

    int zero = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0)
        {
            zero = i;
            break;
        }
    }

    int *res = (int *)malloc(sizeof(int) * numsSize);
    int left = 0, right = numsSize - 1;

    for (int i = 0; i < numsSize; i++)
    {
        nums[i] *= nums[i];
        res[i] = 0;
    }
    for (int i = numsSize - 1; i < numsSize, left <= right; i--)
    {
        if (nums[left] >= nums[right])
        {
            res[i] = nums[left++];
        }
        else
        {
            res[i] = nums[right--];
        }
    }
    *returnSize = numsSize;
    return res;
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int b[] = {0, 1, 3};
    cout << missingNumber(b, 3);

    // cout << mBinarySearch(a, 4);
    // cout << mySqrt(1) << endl;
    return 0;
}
