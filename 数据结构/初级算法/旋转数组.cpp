/**
 * @file 旋转数组.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for (int i = 0; i < k; i++)
        {
            retate_one(nums);
        }
    }
    
    void retate_one(vector<int> &nums)
    {
        int size = nums.size();
        int tmp = nums[size - 1];
        for (int i = size - 1; i > 0; i--)
        {
            nums[i] = nums[i - 1];
        }
        nums[0] = tmp;
    }
};