#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,
求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
输入描述:
题目保证输入的数组中没有的相同的数字
数据范围：
	对于%50的数据,size<=10^4
	对于%75的数据,size<=10^5
	对于%100的数据,size<=2*10^5
示例1
输入

1,2,3,4,5,6,7,0
输出

7
*/

/*参考《剑指offer》，有两种思路。第一就是暴力求解法，时间复杂度为o（n^2）,空间复杂度o(1)
第二种思路就是使用归并排序的思想进行处理，时间复杂度o(nlog(n)),空间复杂度0（n）*/
class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.size()<=1) return 0;//如果少于等于1个元素，直接返回0
        int* copy=new int[data.size()];
        //初始化该数组，该数组作为存放临时排序的结果，最后要将排序的结果复制到原数组中
        for(unsigned int i=0;i<data.size();i++)
            copy[i]=0;
        //调用递归函数求解结果
        int count=InversePairCore(data,copy,0,data.size()-1);
        delete[] copy;//删除临时数组
        return count;
    }
     //程序的主体函数
    int InversePairCore(vector<int>& data,int*& copy,int start,int end)
    {
        if(start==end)
        {
            copy[start]=data[start];
            return 0;
        }
        //将数组拆分成两部分
        int length=(end-start)/2;//这里使用的下标法，下面要用来计算逆序个数；也可以直接使用mid=（start+end）/2
        //分别计算左边部分和右边部分
        int left=InversePairCore(data,copy,start,start+length)%1000000007;
        int right=InversePairCore(data,copy,start+length+1,end)%1000000007;
        //进行逆序计算
        int i=start+length;//前一个数组的最后一个下标
        int j=end;//后一个数组的下标
        int index=end;//辅助数组下标，从最后一个算起
        int count=0;
        while(i>=start && j>=start+length+1)
        {
            if(data[i]>data[j])
            {
                copy[index--]=data[i--];
                //统计长度
                count+=j-start-length;
                if(count>=1000000007)//数值过大求余
                    count%=1000000007;
            }
            else
            {
                copy[index--]=data[j--];
            }
        }
        for(;i>=start;--i)
        {
            copy[index--]=data[i];
        }
        for(;j>=start+length+1;--j)
        {
            copy[index--]=data[j];
        }
        //排序
        for(int i=start; i<=end; i++) {
            data[i] = copy[i];
        }
        //返回最终的结果
        return (count+left+right)%1000000007;
    }
};

int main(int argc, char const *argv[])
{
	Solution s1;
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(0);
	int res=s1.InversePairs(v1);
	cout<<res<<endl;
	return 0;
}