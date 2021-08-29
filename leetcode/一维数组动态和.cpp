#include <stdio.h>
#include <string>
#include <map>
#include <vector>

/**
 * 1        1 
 * 2 1,2    2
 * 3 1 1 1, 1,2, 2,1 3
 * 因为一次只能爬两步，所以，爬n阶 = 爬到 n-1 + 爬到n-2 的方法数之和 
 */
using namespace std;


class Solution {
public:

    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        int sum = 0;

        for (int n : nums) {
            sum += n;
            result.push_back(sum);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {1,2,3,4,5,};
    vector<int> result;
    result = s.runningSum(nums);
    printf("[");
    for (int n : result) {
        printf("%d,",n);
    }
    printf("]\n");
    return 0;
}

