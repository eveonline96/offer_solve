#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;
/*从上往下打印出二叉树的每个节点，同层节点从左至右打印。*/
class Solution
{
public:
    vector Print(TreeNode * root)
    {
        vector<int> v1;
        queue<TreeNode*> que;
        TreeNode *fr;
        if (root==NULL)
            return v1;
        que.push(root);
        while(!que.empty())
        {
            fr=que.front();
            v1.push_back(fr->val);
            if (fr->left)
                que.push(fr->left);
            if (fr->right)
                que.push(fr->right);
            que.pop();
        }
        return v1;
    }
};
int main(int argc, char const *argv[])
{
	
	return 0;
}