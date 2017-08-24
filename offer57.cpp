#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
请实现一个函数按照之字形打印二叉树，
即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，
第三行按照从左到右的顺序打印，其他行以此类推。
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
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(pRoot == NULL)
            return res;
        queue<TreeNode*> que;
        que.push(pRoot);
        bool even = false;
        while(!que.empty())
		{
            vector<int> vec;
            const int size = que.size();
            for(int i=0; i<size; ++i)
			{
                TreeNode* tmp = que.front();
                que.pop();
                vec.push_back(tmp->val);
                if(tmp->left)
                    que.push(tmp->left);
                if(tmp->right)
                    que.push(tmp->right);
            }
            if(even)
                reverse(vec.begin(), vec.end());
            res.push_back(vec);
            even = !even;
        }
        return res;
    }    
};
int main(int argc, char const *argv[])
{
	
	return 0;
}