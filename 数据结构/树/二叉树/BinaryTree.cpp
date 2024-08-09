/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> results;

        inorderTraversal2(&results, root);

        return results;
    }

    void inorderTraversal2(vector<int> *result, TreeNode *root)
    {
        if (root != nullptr)
        {
            inorderTraversal2(result, root->left);
            result->push_back(root->val);
            inorderTraversal2(result, root->right);
        }
    }
    void inorderTraversal3(vector<int> *result, TreeNode *root)
    {
        stack<TreeNode> tmp_stack;

        TreeNode *pNode = root;
        while (pNode != nullptr || !tmp_stack.empty())
        {
            if (pNode != nullptr)
            {
                tmp_stack.push(*pNode);
                pNode = pNode->left;
            }
            else
            {
                TreeNode node = tmp_stack.top();
                tmp_stack.pop();
                result->push_back(node.val);
                pNode = node.right;
            }
        }
    }

    void preTraversal2(vector<int> *result, TreeNode *root)
    {
        if (root != nullptr)
        {
            result->push_back(root->val);
            inorderTraversal2(result, root->left);
            inorderTraversal2(result, root->right);
        }
    }
    void preTraversal3(vector<int> *result, TreeNode *root)
    {
        stack<TreeNode> tmp_stack;

        TreeNode *pNode = root;
        while (pNode != nullptr || !tmp_stack.empty())
        {
            if (pNode != nullptr)
            {
                result->push_back(pNode->val);
                tmp_stack.push(*pNode);
                pNode = pNode->left;
            }
            else
            {
                TreeNode node = tmp_stack.top();
                tmp_stack.pop();
                pNode = node.right;
            }
        }
    }
    void postTraversal2(vector<int> *result, TreeNode *root)
    {
        if (root != nullptr)
        {
            inorderTraversal2(result, root->left);
            inorderTraversal2(result, root->right);
            result->push_back(root->val);
        }
    }
    void postTraversal2(vector<int> *result, TreeNode *root)
    {
        stack<TreeNode> tmp_stack;

        TreeNode *pNode = root;
        while (pNode != nullptr || !tmp_stack.empty())
        {
            if (pNode != nullptr)
            {
                result->push_back(pNode->val);
                tmp_stack.push(*pNode);
                pNode = pNode->left;
            }
            else
            {
                TreeNode node = tmp_stack.top();
                tmp_stack.pop();
                pNode = node.right;
            }
        }
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        queue<TreeNode> level;

        vector<vector<int>> ret;
        level.push(*root);
        while (!level.empty())
        {
            int currentSize = level.size();
            ret.push_back(vector<int>());
            for (int i = 1; i <= currentSize; ++i)
            {
                TreeNode node = level.front();
                level.pop();
                ret.back().push_back(node.val);

                if (node.left != nullptr)
                {
                    level.push(node.left);
                }

                if (node.right != nullptr)
                {
                    level.push(node.right)
                }
            }
        }

        return ret;
    }
};