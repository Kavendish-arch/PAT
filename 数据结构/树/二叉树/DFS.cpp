#include <iostream>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> result;
    vector<int> pathStack;
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        DFS(root, targetSum);
        return result;
    }

    void DFS(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return;
        }
        pathStack.push_back(root->val);
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr && root->val == targetSum)
        {
            vector<int> tmp;
            for (int i = 0; i < pathStack.size(); i++)
            {
                tmp.push_back(pathStack[i]);
            }
            // result.push_back(pathStack);
            this.result.push_back(tmp);
        }

        DFS(root->left, targetSum);
        DFS(root->right, targetSum);
        pathStack.pop_back();
    }
};
