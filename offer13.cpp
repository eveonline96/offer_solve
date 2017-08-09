#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

定义两个数组
*/
class Solution 
{
public:
    void reOrderArray(vector<int> &array) 
    {
        int array_odd[100]={0};
        int array_even[100]={0};
        int size=array.size();
        for (int i = 0,o=0,e=0; i < size; ++i)
        {
        	if (array[i]%2==1)
        	{
        		array_odd[o]=array[i];
        		o++;
        		//cout<<array_odd[i]<<endl;
        	}
        	else
        	{
        		array_even[e]=array[i];
        		e++;
        		//cout<<array_even[i]<<endl;
        	}
        }
        for (int j = 0,e=0; j < size; ++j)
        {
        	if (array_odd[j]!=0)
        	{
        		array[j]=array_odd[j];
        	}
        	else
        	{
        		array[j]=array_even[e];
        		e++;
        	}
        	cout<<array[j]<<endl;
        }

    }
};
int main(int argc, char const *argv[])
{
	Solution s1;
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(7);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(13);
	arr.push_back(24);
	arr.push_back(35);
	arr.push_back(76);

	s1.reOrderArray(arr);
	
	return 0;
}
