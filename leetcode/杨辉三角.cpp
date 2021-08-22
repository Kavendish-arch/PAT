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
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int> > yanghui;
        vector<int> row;
        row.push_back(1);
        yanghui.push_back(row);
       

        for(int i = 1; i < numRows; i++){
            row.clear();
            for(int j = 0; j <= i; j ++){
                if (j == 0){
                    row.push_back(yanghui[i-1][j]);
                } else if (j == i){
                    row.push_back(yanghui[i-1][j-1]);
                } else {
                    row.push_back(yanghui[i-1][j-1] + yanghui[i-1][j]);
                }
            }
            yanghui.push_back(row);
        }
        return yanghui;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {2,4,4,4,5,4,6};
    vector<int> nums2 = {3,4,4,3};
    
    vector<vector<int> > nums3;
    Solution s;
    nums3 = s.generate(5) ;
    for (int i = 0; i < nums3.size(); i++)
    {
        for (int j = 0; j < nums3[i].size(); j++){
            printf("%d ", nums3[i][j]);
        }
        printf("\n");
    } 
    return 0;
}
