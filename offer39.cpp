#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
输入一棵二叉树，判断该二叉树是否是平衡二叉树
*/

//思路：从下往上走，并记录每一个深度，遇到一个根节点就进行判断，此方法节约性能！
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) 
    {
        int depth=0;
        return IsBalanced_Solution(pRoot,depth);
    }
    bool IsBalanced_Solution(TreeNode* pRoot,int& depth)//depth变量传引用或者传地址都行
    {
        if(pRoot==nullptr)
        {
            depth=0;
            return true;
        }
         
        int left=0,right=0;
        //会把每个根节点的每一条路到走到子节点，到子节点后，才开始执行if的内容（往上走到根节点）
        if(IsBalanced_Solution(pRoot->left,left)&&IsBalanced_Solution(pRoot->right,right))
        {
            if((left-right<=1)&&(left-right>=-1))
            {
                depth=1+((left>right)?left:right);
                return true;
            }
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{
	
	return 0;
}