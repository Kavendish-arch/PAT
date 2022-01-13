/**
 * @file 最大股票利润.cpp
 * @author chen ying tao (chen_yingtaou@126.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<vector>
#include<iostream>
using namespace std;

class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int ab_prices[size+1];
        int sum_price = 0;
        
        for (int i = 0; i < size + 1; i++)
        {
            ab_prices[i] = 0;
        }

        for (int i = 1; i < size; i++)
        {
            ab_prices[i] = prices[i] - prices[i - 1]; 
            if(ab_prices[i] > 0)
            {
                sum_price += ab_prices[i];
            }
        }
        for (int i = 0; i < size; i++)
        {
            if(ab_prices[i] > 0)
            {
                sum_price += ab_prices[i];
            }
        }
         
        return sum_price;
    }
    ~Solution();
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}


int main(int argc, char const *argv[])
{
    int nums[] = {7,6,5,4,3,2,1};
    // int nums[] = {7,1,5,3,6,4};
    // 0 -6 4 -2 3 -2
    // int nums[] = {1,2,3,4,5};
    vector<int> num(nums, nums+sizeof(nums)/sizeof(int));
    Solution solution;
    cout << solution.maxProfit(num) << endl;
    return 0;
}
