#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
{[2,3,4],2,6,2,5,1}， 
{2,[3,4,2],6,2,5,1}，
{2,3,[4,2,6],2,5,1}，
{2,3,4,[2,6,2],5,1}，
{2,3,4,2,[6,2,5],1}，
{2,3,4,2,6,[2,5,1]}。
*/

class Solution 
{
public:
	int Max(int a,int b,int c)
	{
		int temp;
		temp=(a>b?a:b);
		temp=(c>temp?c:temp);
		return temp;
	}
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
    	vector<int> res;
        unsigned int n_size=num.size();
        if (n_size<0 || size<=0)
        {
        	return res;
        }
        if(n_size<size)
        	return res;
        int cnt=n_size-size+1;
        for (int i = 0; i <=cnt-1; ++i)
        {
        	int max=num[i];
            for(int j=i;j<i+size;j++)
            {
                if(max<num[j])
                {
                    max=num[j];
                }
            }
       		res.push_back(max);
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
	Solution s1;
	vector<int> v1;
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(2);
	v1.push_back(6);
	v1.push_back(2);
	v1.push_back(5);
	v1.push_back(1);
	vector<int> result=s1.maxInWindows(v1,3);
	for (int i = 0; i < result.size(); ++i)
	{
		cout<<result[i]<<endl;
	}
	return 0;
}