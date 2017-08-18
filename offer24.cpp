/*
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

/非递归版本
//思路：
1.按先序遍历把当前节点cur的左孩子依次入栈同时保存当前节点，每次更新当前路径的和sum；
2.判断当前节点是否是叶子节点以及sum是否等于expectNumber，如果是，把当前路径放入结果中。
3.遇到叶子节点cur更新为NULL，此时看栈顶元素，如果栈顶元素的把栈顶元素保存在last变量中，
同时弹出栈顶元素，当期路径中栈顶元素弹出，sum减掉栈顶元素，这一步骤不更改cur的值；
4.如果步骤3中的栈顶元素的右孩子存在且右孩子之前没有遍历过，当前节点cur更新为栈顶的右孩子，此时改变cur=NULL的情况。
 
递归思路：
为了从根节点开始找到，则使用前序遍历
递归到叶子节点如果还没有找到路径，就要回退到父节点继续寻找，依次类推
*/

#include <iostream>
#include <vector>
 
using namespace std;
 
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};
 
class Solution {
public:
    vector<vector<int> > buffer;
    vector<int> tmp;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root==NULL)
            return buffer;
        tmp.push_back(root->val);
        int least=expectNumber-root->val;
        if(least==0 && root->left==NULL && root->right==NULL)
            {
            buffer.push_back(tmp);
        }
        FindPath(root->left,least);
        FindPath(root->right,least);
        if(tmp.size()!=0)
            tmp.pop_back();
        return buffer;
    }
};
