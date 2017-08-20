// 输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,
// 则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;
struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

class Solution 
{
	vector<string> res;

public:
	void Per(int k,string str)
	{
		if (k==str.size()-1)
			res.push_back(str);
		for (int i = k; i <str.size(); ++i)
		{
			if (i!=k&&str[k]==str[i])
				continue;
			swap(str[k],str[i]);
			Per(k+1,str);
			swap(str[k],str[i]);
		}
	}
    vector<string> Permutation(string str) 
    {
    	Per(0,str);
    	sort(res.begin(),res.end());
    	return res;    
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}