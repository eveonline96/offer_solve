#include <iostream>
#include <vector>
using namespace std;
/*输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
则重建二叉树并返回。*/
struct TreeNode 
{
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution 
{
	public:
	TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) 
	{
		TreeNode* root=reTree(pre,0,pre.size()-1,vin,0,vin.size()-1);  //按照下标填写
		return root;
	}	
	public:
	TreeNode* reTree(vector<int> pre,int prest,int preend,vector<int> vin,int vinst,int vinend)  
	{
		if ((prest>preend)||(vinst>vinend))  //回溯终点为开始下标均大于终点下标，直接返回NULL不再创建新的根节点
		{
			return NULL;
		}
		TreeNode *root=new TreeNode(pre[prest]);
		for (int i = vinst; i <= vinend; ++i)  //中序遍历为限制条件
		{
			if (pre[prest]==vin[i])      //先找到根节点，再中序遍历
			{
				root->left=reTree(pre,prest+1,prest+i-vinst,vin,vinst,i-1);  //左子树长度为i-vinst
				root->right=reTree(pre,prest+i-vinst+1,preend,vin,i+1,vinend);		
			}
		}
		return root;
	}

};
int main(int argc, char const *argv[])
{
	Solution s1;
	vector<int> pre;
	vector<int> vin;
	pre.push_back(1);
	pre.push_back(2);
	pre.push_back(4);
	pre.push_back(7);
	pre.push_back(3);
	pre.push_back(5);
	pre.push_back(6);
	pre.push_back(8);

	vin.push_back(4);
	vin.push_back(7);
	vin.push_back(2);
	vin.push_back(1);
	vin.push_back(5);
	vin.push_back(3);
	vin.push_back(8);
	vin.push_back(6);
	
	TreeNode* head1=s1.reConstructBinaryTree(pre,vin);

	return 0;
}
