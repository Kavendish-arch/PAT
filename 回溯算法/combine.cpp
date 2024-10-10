#include <iostream>
#include <vector>
using namespace std;
// 定义全局变量来存储结果
/**
 * 时间复杂度: O(n * 2^n)
 * 空间复杂度: O(n)
 */
class Solution
{
public:
    vector<vector<int>> results;
    vector<int> path;
    /**
     * @brief 生成所有可能的组合
     *
     * 从1到n的整数中选择k个整数的所有组合，以二维向量的形式返回。
     * 此函数通过回溯算法实现，逐步构建组合并将其添加到结果列表中。
     *
     * @param n 整数范围的上限
     * @param k 每个组合中整数的数量
     * @return vector<vector<int>> 包含所有可能组合的二维向量
     */
    vector<vector<int>> combine(int n, int k)
    {
        // 清空结果列表，准备进行新的组合生成
        results.clear();
        // 清空路径，为新的组合生成做准备
        path.clear();
        // 遍历从1到n的每个整数，作为组合中的第一个元素
        for (int i = 1; i <= n; i++)
        {
            // 将当前整数添加到路径中，作为组合的第一个元素
            path.push_back(i);
            // 以当前整数为起点，开始回溯，生成包含k个元素的组合
            backtrack(n, k, i + 1);
            // 从路径中移除当前整数，准备处理下一个整数
            path.pop_back();
        }
        // 返回所有可能的组合
        return results;
    }

    /**
     * 回溯函数，用于生成所有可能的组合
     * @param n 整数n，组合中的最大值
     * @param k 整数k，组合的长度
     * @param start 当前开始搜索的起始值
     */
    void backtrack(int n, int k, int start)
    {
        // 当路径长度达到k时，将当前路径添加到结果集中
        if (path.size() == k)
        {
            results.push_back(path);
            return;
        }

        // 从start开始遍历，尝试每一种可能的值
        for (int i = start; i <= n; i++)
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
    cout << "Hello World!" << endl;
    Solution s;
    vector<vector<int>> results = s.combine(4, 2);
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