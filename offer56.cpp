#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
请实现一个函数，用来判断一颗二叉树是不是对称的。
注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
//这种方法有bug
class Solution {
public:
    void mid_order(TreeNode *root)
	{
		if(root!=NULL)
		{
			mid_order(root->left);
			v1.push_back(root->val);
			cout<<v1.back();
			mid_order(root->right);
		}
        else{
            v1.push_back(1);
            cout<<v1.back();
        }
	}
	void mid_order1(TreeNode *root)
	{
		if(root!=NULL)
		{
			mid_order1(root->left);
            v2.push_back(root->val);
            cout<<v2.back();
			mid_order1(root->right);
		}
         else{
            v2.push_back(1);
        }
	}
	void Mirror(TreeNode *pRoot)
	{
		if(pRoot==NULL)
			return ;
		TreeNode *ptmp=pRoot->left;
		pRoot->left=pRoot->right;
		pRoot->right=ptmp;
		if(pRoot->left)
			Mirror(pRoot->left);
		if(pRoot->right)
			Mirror(pRoot->right);
	}
    bool isSymmetrical(TreeNode* pRoot)
    {
    	int num[1000];
    	if(pRoot==NULL)
    			return true;
    	if(pRoot!=NULL)
    	{
    		mid_order(pRoot);
    		Mirror(pRoot);
    		mid_order1(pRoot);
    	}
    	for (int i = 0; i < v1.size(); ++i)
    	{
            if (v1[i]=='#')
    		{
    			return false;
    		}
    		if (v1[i]!=v2[i])
    		{
    			return false;
    		}
    	}
    	return true;
    }
	vector<int> v1;
	vector<int> v2;

};
//左子树的右子树和右子树的左子树相同即可，采用递归
// class Solution {
// public:
//     bool isSymmetrical(TreeNode* pRoot)
//     {
//         return isSymmetrical(pRoot,pRoot);
//     }
//     bool isSymmetrical(TreeNode* pRoot1,TreeNode* pRoot2)
//     {
//         if(pRoot1==nullptr&&pRoot2==nullptr)
//             return true;
//         if(pRoot1==nullptr||pRoot2==nullptr)
//             return false;
//         if(pRoot1->val!=pRoot2->val)
//             return false;
//         return isSymmetrical(pRoot1->left,pRoot2->right)&& isSymmetrical(pRoot1->right,pRoot2->left);
//     }
 
// };
int main(int argc, char const *argv[])
{
	TreeNode *pRoot1=(TreeNode *)malloc(1*sizeof(TreeNode));
	TreeNode *pRoot2=(TreeNode *)malloc(1*sizeof(TreeNode));
	TreeNode *pRoot3=(TreeNode *)malloc(1*sizeof(TreeNode));
	pRoot1->val=8;
	pRoot1->left=pRoot2;
	pRoot1->right=pRoot3;
	pRoot2->val=6;
	pRoot2->left=NULL;
	pRoot2->right=NULL;
	pRoot3->val=6;
	pRoot3->left=NULL;
	pRoot3->right=NULL;
	Solution s1;
	bool res;
	res=s1.isSymmetrical(pRoot1);
	cout<<res<<endl;
	return 0;
}