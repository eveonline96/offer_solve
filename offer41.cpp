#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。另一组连续正数和为100的序列:18,19,20,21,22。
找出所有和为S的连续正数序列? 
输出描述:
输入一个整数；
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
*/
class Solution 
{
public:
    vector<vector<int> > FindContinuousSequence(int sum) 
    {
        vector<vector<int>> res;
        vector<int> v1;
        if(sum<3)
        	return res;
        int small=1;
        int big=2;
        int mid=(1+sum)/2;
        int curSum=small+big;
        while(small<mid)
        {
        	if(curSum==sum)
        	{
        		for (int i = small; i < big+1; ++i)
        		{
        			v1.push_back(i);
        		}
        		res.push_back(v1);
        		v1.clear();
        	}
        	while(curSum>sum && small<mid)
        	{
        		curSum-=small;
        		small++;
        		if(curSum==sum)
        		{
        			for (int i = small; i < big+1; ++i)
	        		{
	        			v1.push_back(i);
	        		}
	        		res.push_back(v1);
	        		v1.clear();
        		}
        	}

        	big++;
        	curSum+=big;
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
	
	return 0;
}