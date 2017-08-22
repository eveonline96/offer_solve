#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
统计一个数字在排序数组中出现的次数

思路：利用二分查找  O(logn)

*/
class Solution {
public:
		int GetFirst(vector<int> data,int length,int k,int start,int end)
	{
		if(start>end)
			return -1;
		int mid=(start+end)/2;
		int mid_data=data[mid];
		if (mid_data==k)
		 {
			if((mid>0 &&data[mid-1]!=k) || mid==0)
				return mid;
			else
				end=mid-1;		 	
		 } 
		 else if(mid_data>k)
		 		end=mid-1;
		 else
		 	start=mid+1;
		 return GetFirst(data,length,k,start,end);
	}
	int GetLast(vector<int> data,int length,int k, int start,int end)
	{
		if(start>end)
			return -1;
		int  mid=(start+end)/2;
		int mid_data=data[mid];
		if (mid_data==k)
		{
			if((mid<length-1 &&data[mid+1]!=k) ||mid==length-1)
				return mid;
			else
				start=mid+1;
		}
		else if(mid_data<k)
			start=mid+1;
		else
			end=mid-1;
		return GetLast(data,length,k,start,end);

	}
	int GetNumberOfK(vector<int> data ,int k) 
    {
    	int tmp=0;
    	int length=data.size();
        if(length>0)
    	{
    		int first=GetFirst(data,length,k,0,length-1);
    		int last=GetLast(data,length,k,0,length-1);
    		if(first>-1 &&last>-1)
    			tmp=last-first+1;
    	}

    	return tmp;
    }
    // int GetNumberOfK(vector<int> data ,int k) 
    // {
    // 	int tmp=0;
    // 	for (int i = 0; i < data.size(); ++i)
	   //  {
	   //  	if(data[i]==k)
	   //  		tmp++;
	   //  }    
    // 	return tmp;
    // }
};
int main(int argc, char const *argv[])
{
	
	return 0;
}
