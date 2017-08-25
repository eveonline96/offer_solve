#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
请实现两个函数，分别用来序列化和反序列化二叉树
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

1234” =〉 1234
从头开始解析
首先是1
然后1*10+2 = 12
12*10+3 = 123
123*10+4 = 1234
*/
// class Solution
// {
// private:
//     TreeNode* decode(char *&str) 
//     {
//         if(*str=='#')
//         {
//             str++;
//             return NULL;
//         }
//         int num = 0;
//         while(*str != ',')
//             num = num*10 + (*(str++)-'0');
//         str++;
//         TreeNode *root = new TreeNode(num);
//         root->left = decode(str);
//         root->right = decode(str);
//         return root;
//     }
// public:
//     char* Serialize(TreeNode *root) 
//     {   
//         if(!root) return "#";
//         string r = to_string(root->val);
//         r.push_back(',');
//         char *left = Serialize(root->left);
//         char *right = Serialize(root->right);
//         char *ret = new char[strlen(left) + strlen(right) + r.size()];
//         strcpy(ret, r.c_str());
//         strcat(ret, left);
//         strcat(ret, right);
//         return ret;
//     }
//     TreeNode* Deserialize(char *str) {
//         return decode(str);
//     }
// };


typedef TreeNode node;
typedef TreeNode* pnode;
typedef int* pint;
class Solution {
    vector<int> buf;
    void dfs(pnode p)
	{
        if(!p) buf.push_back(0x23333);
        else{
            buf.push_back(p -> val);
            dfs(p -> left);
            dfs(p -> right);
        }
    }
    pnode dfs2(pint& p)
	{
        if(*p == 0x23333){
            ++p;
            return NULL;
        }
        pnode res = new node(*p);
        ++p;
        res -> left = dfs2(p);
        res -> right = dfs2(p);
        return res;
    }
public:
    char* Serialize(TreeNode *p) 
{
        buf.clear();
        dfs(p);
        int *res = new int[buf.size()];
        for(unsigned int i = 0; i < buf.size(); ++i) res[i] = buf[i];
        return (char*)res;
    }
    TreeNode* Deserialize(char *str) {
        int *p = (int*)str;
        return dfs2(p);
    }
};

int main(int argc, char const *argv[])
{
	
	return 0;
}


