
/**
 *  二叉树的实现
 *	创建
 计算叶子结点
 中序，先序，后序遍历
 */

#include <stdio.h>
#include <stack>
using namespace std;


struct BinaryTreeNode {

	int data;
	BinaryTreeNode * left_child;
	BinaryTreeNode * right_child;

};

// 递归算法销毁二叉树
void BinaryTreeDestory(BinaryTreeNode * root){
	if (root){
		BinaryTreeDestory(root->left_child);
		BinaryTreeDestory(root->right_child);
		// free(root);
		root = NULL;
	}
}
/**
 * 先序遍历
 * 递归法 
 */

void BinaryTreePreOrder(BinaryTreeNode * root){
	if (root){
		printf("root");
	}	
	BinaryTreePreOrder(root->left_child);
	BinaryTreePreOrder(root->right_child);
}

void PreOrder2(BinaryTreeNode * root){
	stack<*BinaryTreeNode> S;
	BinaryTreeNode *p = root;		
	while (p || !S.empty()){
		if(p){
			S.push(p);
			p = p->left_child;
		}
		else {
			p = S.pop();
			printf(p->data);
			p = p->right_child;
		}
		/* code */
	}
	
}

void BinaryTreeInOrder(BinaryTreeNode * root){
	BinaryTreePreOrder(root->left_child);
	if (root){
		printf("root");
	}	
	BinaryTreePreOrder(root->right_child);
}
void InOrder(BinaryTreeNode * root){
	stack<BinaryTreeNode> s;
	BinaryTreeNode * p = root;
	while (p || !s.empty())
	{
		if(p){
			printf(p->data);
			s.push(p);
			p->left_child;
		}else{
			p = s.pop();
			p->right_child;
		}
	}
	
}
void BinaryTreePostOrder(BinaryTreeNode * root){
	BinaryTreePreOrder(root->left_child);
	BinaryTreePreOrder(root->right_child);
	if (root){
		printf("root");
	}	
}

int main(){
	int x = NULL;
	if (x){
		printf("x is not null");
	} else {
		printf("x is null");
	}
}

