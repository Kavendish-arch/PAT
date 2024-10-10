// #include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
/**
 * Definition for a binary tree node.
 * 二叉树的层序遍历
 *
 * 方法
 * 1. 递归法：
 * 相同层次需要传入同一个数组，
 * 借助辅助函数level 决定层次
 *
 * 2. 迭代法
 * 关键词：层次遍历
 * 模式识别： 出现树的层次遍历，都可以用队列辅助
 */

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

class Solution
{
public:
    vector<vector<int>> levels;
    void helpLevelOrder(TreeNode *root, int level)
    {
        if (levels.size() == level)
        {
            vector<int> level_result;
            levels.push_back(level_result);
        }

        levels[level].push_back(root->val);

        if (root->left != nullptr)
        {
            helpLevelOrder(root->left, level + 1);
        }

        if (root->right != nullptr)
        {
            helpLevelOrder(root->right, level + 1);
        }
    }
    /**
     * 递归方法：
     * 节点，层级
     */
    // vector<vector<int>> levelOrder(TreeNode *root)
    // {
    //     if (root == nullptr)
    //     {
    //         return levels;
    //     }
    //     helpLevelOrder(root, 0);
    //     return levels;
    // }
    /**
     * 层序遍历
     * 广度优先搜索
     *
     * 迭代方法
     * 使用队列实现
     */
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
        {
            return result;
        }
        queue<TreeNode *> nodes; // TreeNode *
        TreeNode *endFlag = new TreeNode(-1);
        nodes.push(root);
        nodes.push(endFlag);

        vector<int> levelAns;
        while (!nodes.empty())
        {
            TreeNode *tmpNode = nodes.front();
            nodes.pop();
            if (tmpNode == endFlag)
            {
                result.push_back(levelAns);
                levelAns.clear();
                if (!nodes.empty())
                {
                    nodes.push(endFlag);
                }
            }
            else
            {
                levelAns.push_back(tmpNode->val);

                if (tmpNode->left != nullptr)
                {
                    nodes.push(tmpNode->left);
                }
                if (tmpNode->right != nullptr)
                {
                    nodes.push(tmpNode->right);
                }
            }
        }

        return result;
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        inOrder(root, result);
        return result;
    }

    void inOrder(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
        {
            return;
        }
        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (preOrder(p, q))
        {
            return true;
        }
        return false;
    }

    bool preOrder(TreeNode *p, TreeNode *q)
    {

        if (p != nullptr && q != nullptr)
        {
            if (p->val == q->val)
            {
                if (preOrder(p->left, q->left))
                {
                    if (preOrder(p->right, q->right))
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        return false;
    }

    bool isSymmetric(TreeNode *p, TreeNode *q)
    {

        if (p != nullptr && q != nullptr)
        {
            if (p->val == q->val)
            {
                if (preOrder(p->left, q->right))
                {
                    if (preOrder(p->right, q->left))
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        return false;
    }

    int maxDepth(TreeNode *root)
    {

        if (root == nullptr)
        {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return left > right ? left + 1 : right + 1;
    }

    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left == 0)
        {
            return right + 1;
        }
        if (right == 0)
        {
            return left + 1;
        }
        return left < right ? left + 1 : right + 1;
    }
};
// int main(int argc, char const *argv[])
int main()
{
    TreeNode *l1, *l2, *l3, *l4, *l5;
    l1->val = 3, l1->left = l2, l1->right = l3;
    l2->val = 9;
    l3->val = 20, l3->left = l4, l3->right = l5;
    l4->val = 15;
    l5->val = 7;
    Solution solution;
    vector<vector<int>> result = solution.levelOrder(l1);

    cout << "kaishi" << endl;
    // for (int i = 0; i < result.size(); i++)
    // {
    //     cout << "[";

    //     for (int j = 0; j < result[0].size(); j++)
    //     {
    //         cout << result[i][j] << ",";
    //     }
    //     cout << "]";
    // }
    // return 0;
}
