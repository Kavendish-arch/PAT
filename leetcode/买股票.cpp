/**
 * 最小，最大
 * hash 映射
 */
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * 找对最小的，与最大的
     * 且，最小的天数 < 最大的天数
     * 
     * 2 4 5 1
     * 
     * 1: min = min(1e9,2), max = max(0, 2 - 2 = 0) = 0
     * 2: min = min(2, 4) = 2, max = max(0, 4 - 2 = 2) = 2
     * 3: min = min(2, 5) = 2, max = max(2, 5 - 2 = 3) = 3
     * 4: min = min(2, 1) = 1, max = max(3, 1 - 1 = 0) = 3
     * 
     */
    int maxProfit(vector<int>& prices) {
        int min_price, max_price;
        min_price = 1e9;
        max_price = 0;

        for (int i = 0; i < prices.size(); i++){
            min_price = min(min_price, prices[i]);
            max_price = max(max_price, prices[i] - min_price); 
        }
        printf("%d\n", max_price);
        return max_price;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {2,4,1};
    Solution s;
    s.maxProfit(nums1);
    return 0;
}
