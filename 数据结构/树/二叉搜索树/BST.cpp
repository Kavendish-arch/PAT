#include<stdio.h>

struct  BTNode
{
    int data;
    struct BTNode *left;
    struct BTNode *right;
};


int _search(BTNode *root, int target)
{
    if(!root)
    {
        return - 1;
    }
    if(target == root->data)
    {
        return root->data;
    }
    if(target > root->data)
    {
        return _search(root->right, target);
    }
    if(target < root->data)
    {
        return _search(root->left, target);
    }
    return -1;
}
int countNode(BTNode *root)
{
    if(!root)
    {
        return 0;
    }
    else
    {
        return 1 + countNode(root->left) + countNode(root->right);
    }
}
int maxDeepBSTree(BTNode *root)
{
    if(!root)
    {
        return 0;
    }
    else
    {
        int left_deep = maxDeepBSTree(root->left);
        int right_deep = maxDeepBSTree(root->right);
        return left_deep > right_deep ? left_deep + 1 : right_deep + 1;
    }
}

int main(int argc, char const *argv[])
{
    printf("--------");
    struct BTNode *A;
    struct BTNode *B;
    struct BTNode *C;
    // B->data = 2;
    // B->left = nullptr;
    // B->right = nullptr;
    // C->left = nullptr;
    // C->right = nullptr;
    // C->data = 3;
    A->data = 1;
    A->left = B;
    A->right = C;
    printf("%d", A->data);
    // int x = _search(A, 3);
    // printf("%d", x);
    return 0;
}

