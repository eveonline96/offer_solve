#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
如何得到一个数据流中的中位数？
如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
*/
class Solution {
public:
    void Insert(int num)
    {
        vec.push_back(num);
    }

    double GetMedian()
    { 
    	double res;
    	sort(vec.begin(),vec.end());
    	int size=vec.size();
    	if(size%2==1)
    	{
    		res=vec[size/2];
    	}
    	else
    	{
    		res=((double)vec[size/2]+(double)vec[size/2-1])/2;
    	}
    	return res;
    }
    vector<int> vec;
};
int main(int argc, char const *argv[])
{
	
	return 0;
}