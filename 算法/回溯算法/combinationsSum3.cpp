#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> results;
    vector<int> path;
    vector<vector<int>> combinationSum3(int k, int n)
    {
        for (int i = 1; i <= 9; i++)
        {
            path.push_back(i);
            backtrack(n, k, i + 1);
            path.pop_back();
        }
        return results;
    }
    int sum(vector<int> result)
    {
        int ans = 0;
        for (int i : result)
        {
            ans += i;
        }
        return ans;
    }
    void backtrack(int n, int k, int start)
    {
        // 当路径长度达到k时，将当前路径添加到结果集中
        if (sum(path) == n && path.size() == k)
        {
            results.push_back(path);
            return;
        }

        // 从start开始遍历，尝试每一种可能的值
        for (int i = start; i <= 9; i++)
        {
            // 将当前值添加到路径中
            path.push_back(i);
            // 递归调用backtrack函数，尝试下一个值
            backtrack(n, k, i + 1);
            // 回溯，将之前添加的值从路径中移除，尝试其他可能
            path.pop_back();
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> results = s.combinationSum3(3, 7);
    for (vector<int> v : results)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}