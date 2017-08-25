#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*

从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。

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
        vector<vector<int> > Print(TreeNode* pRoot) 
        {
        	vector<vector<int>> res;
            if(pRoot==NULL)
                return res;
            queue<TreeNode *>  que;
            que.push(pRoot);
            while(!que.empty())
            {
                vector<int>   vec;
                int size=que.size();
                for(int i=0;i<size;i++)
                {
                    TreeNode *tmp=que.front();
                    que.pop();
                    vec.push_back(tmp->val);
                    if(tmp->left)
                        que.push(tmp->left);
                    if(tmp->right)
                        que.push(tmp->right);
                }
                res.push_back(vec);
            }
            return res;
        }
    
};

int main(int argc, char const *argv[])
{
	
	return 0;
}