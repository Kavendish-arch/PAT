#include <stdio.h>
#include <vector>
/**
 * Definition for a binary tree node.
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
/**
 * 二叉树线序遍历
 */
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;

        return result;
    }

    void preorder(TreeNode *root, vector<int> *res)
    {
        if (root == nullptr)
        {
            return;
        }
        res.push_back(root->val);
        inOrder(root->left, res);
        inOrder(root->right, res);
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
int main(int argc, char const *argv[])
{
    TreeNode A;
    TreeNode B;
    TreeNode C;
    A.val = 1 return 0;
}
