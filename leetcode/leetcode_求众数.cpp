
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>

using namespace std;

int hash_code_1(int x, int size) {

    return x % size;
}

class Solution {
public:
/**
    int majorityElement(vector<int>& nums) {
        map<int, int> num_map;
        int k = nums[0], v = 0;
        for (int i = 0; i < nums.size(); i++){
            if (num_map.count(nums[i])){
                num_map[nums[i]] ++;
            } else {
                num_map.insert(pair<int,int>(nums[i], 1));
            }
            if (num_map[nums[i]] >= v){
                k = nums[i];
                v = num_map[nums[i]];
            }
        }

        return k;
    }
*/
    /**
     * 候选人算法
     */
/**
    int majorityElement(vector<int>& nums) {
        map<int, int> num_map;
        int k = nums[0], v = 0;
        for (int i = 0; i < nums.size(); i++){
            int index = nums[i];
            if (k == index){
                v ++;
            }
            else {
                v --;
            }
            if (v == 0){
                k = index;
                v = 1;
            }
        }
        if (v > 0){
            return k;
        }
        else {
            return -1;
        }
    }
*/ 
    int count_majority(vector<int>& nums, int target, int head, int tail) {
        int k = 0;
        for (int i = head; i <= tail; i++){
            if (nums[i] == target){
                k ++;
            }
        }
        return k;
    }

    int majority_head_to_tail(vector<int> & nums, int head, int tail){
        if (head == tail){
            return nums[head];
        }
        int mid = (head + tail) / 2;
        int left_majority = majority_head_to_tail(nums, head, mid);
        int right_majority = majority_head_to_tail(nums, mid+1, tail);

        int count_left = count_majority(nums, left_majority, head, mid);
        int count_right= count_majority(nums, right_majority, mid+1, tail);

        // if (count_majority(nums, left_majority, head, mid) > (mid - head + 1) / 2 ){
            // return left_majority;
        // }
        // if (count_majority(nums, right_majority, mid+1, tail) > (tail - mid) / 2 ){
            // return right_majority;
        // }
        return count_left > right_majority ? count_left:count_right;
    }
    int majorityElement(vector<int>& nums) {
        return majority_head_to_tail(nums, 0, nums.size() - 1);
    }
};

int main(int argc, char const *argv[])
{
    map<int,int> m ;

    vector<int> nums1 = {2,4,4,4,5,4,6};
    vector<int> nums2 = {3,4,3};
    // for (int i = 0; i < nums1.size(); i++){
    //     // printf("%d \t", nums1[i]);
        
    //     m.insert(pair<int, int>(nums1[i], 1));
    // }
    // m.insert(pair<int, int> (1,2));
    Solution s;

    int x = s.majorityElement(nums1);
    // printf("%d \n", hash_code_1(87, 30));
    printf("%d \n", x);
    return 0;
}
