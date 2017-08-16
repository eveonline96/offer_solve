#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
/*
操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
先前序遍历这棵树的每个结点，如果遍历到的结点有子结点，就交换它的两个子节点，
当交换完所有的非叶子结点的左右子结点之后，就得到了树的镜像
*/
class Solution 
{
public:
    void Mirror(TreeNode *pRoot) 
	{
        //递归实现
        /*if(pRoot==NULL)
            return;
        TreeNode *ptemp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=ptemp;
        if(pRoot->left)
            Mirror(pRoot->left);
        if(pRoot->right)
            Mirror(pRoot->right);*/
        //非递归实现
        if(pRoot==NULL)
            return;
        stack<TreeNode*> stackNode;
        stackNode.push(pRoot);
        while(stackNode.size())
        {
            TreeNode* tree=stackNode.top();
            stackNode.pop();
            if(tree->left!=NULL || tree->right!=NULL){
                TreeNode *ptemp=tree->left;
                tree->left=tree->right;
                tree->right=ptemp;
            }
            if(tree->left)
                stackNode.push(tree->left);
            if(tree->right)
                stackNode.push(tree->right);
        }
    }
};