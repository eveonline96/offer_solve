#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
给定一颗二叉搜索树，请找出其中的第k大的结点。
例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，
按结点数值大小顺序第三个结点的值为4。
*/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
思路：遍历找到要找的数字，然后层次遍历找到则返回，否则返回为空
//思路二：二叉搜索树按照中序遍历的顺序打印出来正好就是排序好的顺序。
//     所以，按照中序遍历顺序找到第k个结点就是结果。
*/
// class Solution {
// public:
//     void inorder(TreeNode* root,TreeNode* &ans){
//         if(root){
//             inorder(root->left,ans);
//             count--;
//             if(!count) ans = root;
//             inorder(root->right,ans);
//         }
//     }
//     TreeNode* KthNode(TreeNode* pRoot, int k)
//     {
//         if(!pRoot || k < 1) return nullptr;
//         TreeNode* ans = NULL;
//         count = k;
//         inorder(pRoot,ans);
//         return ans;
//     }
// private:
//     int count;
     
// };
class Solution {
public:
    void dfs(TreeNode *root)
    {
        if(root!=NULL)、
        {
            vec.push_back(root->val);
            dfs(root->left);
            dfs(root->right);
        }
    }

    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        TreeNode *res=(TreeNode*)malloc(1*sizeof(TreeNode));
       res->left=res->right=NULL;
        res->val=0;
        if(pRoot==NULL ||k==0 )
            return NULL;
        dfs(pRoot);
        sort(vec.begin(),vec.end());
        res->val=vec[k-1];
		queue<TreeNode*> que;
        que.push(pRoot);
        while(!que.empty())
        {
        	int size=que.size();
            TreeNode *tmp=que.front();
            que.pop();
            if(tmp->val==res->val)
                return res;
            if(tmp->left)
                que.push(tmp->left);
            if(tmp->right)
                que.push(tmp->right);
        }
        return NULL;
    }
	 vector<int> vec; 
};

int main(int argc, char const *argv[])
{
	
	return 0;
}