#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int cout = 0;
        int len = s.length();
        for(char c: s)
        {
            if(c == ' ')
            {
                cout ++;
            }
        }
        s.resize(cout * 3);
        int sz = s.size();

        for(int j = sz-1, i = len-1; j >= 0; j--)
        {
            if(s[i] != ' ')
            {
                s[j] = s[i];
            }
            else{
                s[j--] = '0';
                s[j--] = '2';
                s[j] = '%';
            }
        }

        // string ret;
        // for(int i = 0; i < s.size(); i++){
        //     if(s[i] == ' ')
        //     {
        //         ret += "%20";
        //     }
        //     else 
        //     {
        //         ret += s[i];
        //     }
        // }
        return s;
    }
    int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
        int left = 0, right = numbersSize-1;
        *returnSize = 0;
        int * ret = (int*) malloc(sizeof(int) * 2);
        while (left <= right)
        {
            int tmp = numbers[left] + numbers[right];
            if(numbers[left] + numbers[right] == target)
            {
                ret[0] = left;
                ret[1] = right;
                *returnSize = 2;
                return ret;
            }
            else if(tmp > target)
            {
                right --;
            }
            else if(tmp < target)
            {
                left++;
            }
        }
        return ret;
    }
    int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size();
        vector<int> ret;
        vector<vector<int>> retu_v;
        for(int i = 0; i < nums.size(); i++)
        {
            while (left <= right)
            {
                if(left == i || right == i || left == right)
                {
                    continue;
                }
                int tmp = nums[left] + nums[right];
                if(tmp == 0 - nums[i])
                {
                    ret.push_back(nums[i]);
                    ret.push_back(nums[left]);
                    ret.push_back(nums[right]);
                    retu_v.push_back(ret);
                    ret.clear();
                }
                else if(tmp > 0 - nums[i])
                {
                    right --;
                }
                else if(tmp < 0 - nums[i])
                {
                    left++;
                }
            }
            
        }
        return retu_v;
    }
};

int main(int argc, char const *argv[])
{
    Solution so;
    string str = "We are happy.";
    string s = so.replaceSpace(str);
    cout << s << endl;


    return 0;
}
