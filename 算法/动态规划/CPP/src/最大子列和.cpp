/**
 * @file 最大子列和
 * @author (chen_ying_tao@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();

    int rem[n+1];
    for (int i = 0; i < n+1; i++){
        rem[i] = 0;
    }
    rem[0] = nums[0];
    int max = rem[0];

    for (int i = 1; i < n; i++){
        if(rem[i-1] <= 0){
            rem[i] = nums[i];
        } else {
            rem[i] = rem[i-1] + nums[i];
        }

        max = max > rem[i] ? max : rem[i];
    }
    return max;
}

int main(int argc, char const *argv[])
{
    int a[10] = {1,2,-2,-3,5,3,-10,4,6,0};
    vector<int> num(a, a+sizeof(a)/sizeof(int));
    int max = maxSubArray(num);
    printf("%d", max);
    return 0;
}
