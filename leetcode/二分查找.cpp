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
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                right = mid;
            }
            if (nums[mid] < target) {
                left = mid;
            }
        }
        return -1; 
    }

    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                right = mid-1;
            }
            if (nums[mid] < target) {
                left = mid+1;
            }
        }
        return left;
    }
    
    bool isBadVersion(int n){
        if(n < 6){
            return true;
        }
        return false;
    }
    int firstBadVersion(int n) {
        int left = 1, right = n;
        int mid = 0;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (isBadVersion(mid)) {
                left = mid;
            }else{
                right = mid + 1;
            }
        }
        return left;        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> num = {1,2,3,4,5,6,7};
    printf("\n%d",s.searchInsert(num,9));
    return 0;
}

