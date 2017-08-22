#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
思路：递归
*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
    	if (pRoot==NULL)
    	{
    		return 0;
    	}
    	int nleft=TreeDepth(pRoot->left);
    	int nright=TreeDepth(pRoot->right);
    	return ( nleft>nright ) ?(nleft+1) : (nright+1);
    }
};
int main(int argc, char const *argv[])
{
	
	return 0;
}