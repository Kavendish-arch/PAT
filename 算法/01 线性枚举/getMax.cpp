//
//  getMax.cpp
//  Demo
//
//  Created by chenyingtao on 2025/3/16.
//
#include <vector>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
    
        for(int i = 1; i + 1 < arr.size(); ++i){
            int a = arr[i-1];
            int b = arr[i];
            int c = arr[i+1];
            if( a % 2&& b %2 && c % 2){
                return true;
            }
        }
        return false;
    }
    
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int pre = 0;
        int max = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 1){
                pre ++;
            }
            else{
                pre = 0;
            }
            
            if(max < pre){
                max = pre;
            }
        }
        return max;
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i+=2){
            if(nums[i] == nums[i-1]){
                
            } else {
                if(i+1 < nums.size() && nums[i] == nums[i+1]){
                    return nums[i-1];
                } else{
                    return nums[i];
                }
            }
            
        }
        return nums[nums.size()-1];
    }
    
    vector<int> buildArray(vector<int>& nums) {
        // ans[i] = nums[nums[i]] 。返回构建好的数组 ans 。
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i){
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
    /**
     存在一种仅支持 4 种操作和 1 个变量 X 的编程语言：

     ++X 和 X++ 使变量 X 的值 加 1
     --X 和 X-- 使变量 X 的值 减 1
     最初，X 的值是 0

     给你一个字符串数组 operations ，这是由操作组成的一个列表，返回执行所有操作后， X 的 最终值 。
     */
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for(string s:operations){
            if(s == "++X" || s == "X++"){
                X++;
            }
            if(s == "--X" || s == "X--")
            {
                X--;
            }
        }
        return X;
    }
    
    // 模拟题目
    int addDigits(int num) {
        while(num >= 10){
            int sum = 0;
            while(num != 0){
                sum += num %10;
                num /= 10;
            }
            num = sum;
            //sum != 0
            //累加 个位，
            //sum / 10
        }
        return num;
    }
};
