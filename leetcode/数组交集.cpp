/**
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 利用hash表，收集数组之间出现的次数
 * hash 映射
 */
#include <stdio.h>
#include <vector>
#include <set>
#include <map>

using namespace std;


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> hash_map;

        vector<int> short_1, long_1, result;
        short_1 = nums1.size() <= nums2.size() ? nums1 : nums2;
        long_1 = nums1.size() > nums2.size() ? nums1 : nums2;

        for (int i = 0; i < short_1.size(); i++){
            hash_map[short_1[i]] ++;
        }
        for (int i = 0; i < long_1.size(); i++){
            if (hash_map[long_1[i]] > 0){
                result.push_back(long_1[i]);
                hash_map[long_1[i]] --;
            }
        }

        return result;
        // for (map<int,int> ::iterator it = hash_map.begin(); it != hash_map.end(); it ++){
        //     printf("%d,%d\t",it->first, it->second);
        // }


    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {2,4,4,4,5,4,6};
    vector<int> nums2 = {3,4,4,3};
    Solution s;
    vector<int> re = s.intersect(nums1, nums2);
    for (vector<int> ::iterator it = re.begin(); it != re.end(); it ++){
        printf("%d\t", *it);
    }
    return 0;
}
