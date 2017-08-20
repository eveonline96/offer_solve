#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <set>
#include <algorithm>
using namespace std;
/*
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
今天测试组开完会后,他又发话了:在古老的一维模式识别中,
常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
你会不会被他忽悠住？(子向量的长度至少是1)
*/

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) 
    {
    	int len=array.size();
    	if (len<=0)
    		return 0;
    	int result=array[0];
    	int pre=array[0];
    	for (int i = 1; i < len; ++i)
    	{
    		int tmp=array[i]+pre;	
    		if (tmp<array[i])
    		{
    			pre=array[i];
    			if(result<array[i])
    				result=array[i];
    		}
    		else
    		{
    			pre=tmp;
    			if(result<tmp)
    				result=tmp;
    		}
    	}
    	return result;
    }
};
int main(int argc, char const *argv[])
{
	Solution s1;
	vector<int> array;
	array.push_back(1);
	array.push_back(-2);
	array.push_back(3);
	array.push_back(10);
	array.push_back(-4);
	array.push_back(7);
	array.push_back(2);
	array.push_back(-5);
	int res=s1.FindGreatestSumOfSubArray(array);
	cout<<res<<endl;
	return 0;
}