/**
    * 给定一个二叉树，判断它是否是高度平衡的二叉树。
    本题中，一棵高度平衡二叉树定义为：
    一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
 * };
 */
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
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        // int left = maxDeep(root->left);
        // int right = maxDeep(root->right);
        // // if ((left - right) > 1 || (right - left) > 1)
        // if (abs(left - right) > 1)
        // {
        //     return false;
        // }
        // if (isBalanced(root->left) && isBalanced(root->right))
        // {

        //     return true;
        // }

        // // return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);

        // // return false;
        else
        {
            return abs(maxDeep(root->left) - maxDeep(root->right) <= 1 && isBalanced(root->left) && isBalanced(root->right));
        }
    }

    bool isBalanced_tree(TreeNode *root)
    {
        return afterOrder(root) > 0;
    }

    int afterOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 1;
        }
        int left = afterOrder(root->left);
        if (left < 0)
        {
            return -1;
        }
        int right = afterOrder(root->right);
        if (right < 0)
        {
            return -1;
        }
        if ((left - right) > 1 || (right - left) > 1)
        {
            return -1;
        }
        else
        {
            return left > right ? left + 1 : right + 1;
        }
    }

    int maxDeep(TreeNode *root)
    {
        /**
         * 递归计算最大深度 左右子树
         */
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            int left = maxDeep(root->left);
            int right = maxDeep(root->right);
            return left > right ? left + 1 : right + 1;
        }
    }
    int height(TreeNode *root)
    {
        int 
    }
};