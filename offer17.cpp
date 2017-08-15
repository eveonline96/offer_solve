#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
/*
输入两棵二叉树A，B，判断B是不是A的子结构。
（ps：我们约定空树不是任意一个树的子结构）
*/
struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {}
};
class Solution 
{
	public:
		TreeNode* Tree_Create()
		{
			root=NULL;
			if (root->val==3)
			{
				return root;
			}
			root=(TreeNode*)malloc(1*sizeof(TreeNode));
			for (int i = 0; i < 5; ++i)
			{
		 		root->val=i;
				root->left=Tree_Create();
				root->right=Tree_Create();
			}
			return root;
		}

	public: bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2==NULL)
		{
			return true;
		}
		if (pRoot1==NULL)
		{
			return false;
		}
		if (pRoot1->val==pRoot2->val)
		{
			return isSubtree(pRoot1->right,pRoot2->right)&&isSubtree(pRoot1->left,pRoot2->left);
		}
		else
		{
			return false;
		}
	}
	public:bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	    {
	    	if (pRoot1==NULL||pRoot2==NULL)
	    	{
	    		return false;
	    	}
	    	return isSubtree(pRoot1,pRoot2)||HasSubtree(pRoot1->right,pRoot2)||HasSubtree(pRoot1->left,pRoot2);
	    }
	private:
		TreeNode *root;
};
int main(int argc, char const *argv[])
{
	Solution s1;
	TreeNode* head1=s1.Tree_Create();
	// TreeNode* head2=s1.Tree_Create();
	//bool b1=s1.HasSubtree(head1,head2);
	//cout<<b1<<endl;
	return 0;
}
