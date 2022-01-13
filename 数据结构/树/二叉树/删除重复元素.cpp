/**
 * @file 删除重复元素.cpp
 * @author chen ying tao (chen_yingtaou@126.com)
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
    int removeDuplicates(vector<int>& nums) {

        int size = nums.size();

        if (0 == size)
        {
            return 0;
        }

        // 慢指针
        int i = 1;
        // 快指针
        int j = 0;
        for (int j = 1; j < size; j++)
        {
            if(nums[j] != nums[j-1])
            {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};