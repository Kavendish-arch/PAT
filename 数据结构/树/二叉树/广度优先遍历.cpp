/**
 * @brief 
 *  广度优先遍历 求路径 
 */
struct TreeNode
{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(): val(0), left(nullptr), right(nullptr){};
    TreeNode(int x): val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode * left, TreeNode * right): val(x), left(left), right(right){};
};

#include <stdio.h>
#include <queue>
#include<set>

using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        queue<TreeNode> Q;
        set<TreeNode> visited;

        Q.push(root);

        while (!Q.empty())
        {
            TreeNode tmp = Q.pop();
            printf(tmp.val);
            Q.push(tmp.left);
            Q.push(tmp.right);
        }
        
    }
};
    int main(int argc, char const *argv[])
    {
        Solution solution;
        TreeNode A = new TreeNode(1);
        TreeNode B = new TreeNode(2);
        TreeNode C = new TreeNode(3);
        TreeNode D = new TreeNode(4);
        A.left = B;
        A.right = C;
        B.left = D;
        solution.hasPathSum(A, 1);
        return 0;
    }
