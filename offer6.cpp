#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0
为了保证时间复杂度：应该用二分查找
思路：  
    （1）我们用两个指针left,right分别指向数组的第一个元素和最后一个元素。按照题目的旋转的规则，
    第一个元素应该是大于最后一个元素的（没有重复的元素），是如果不是旋转，第一个元素肯定小于最后一个元素。  
    （2）找到数组的中间元素。中间元素大于第一个元素，则中间元素位于前面的递增子数组，此时最小元素位于中间元素的后面。
    我们可以让第一个指针left指向中间元素。移动之后，第一个指针仍然位于前面的递增数组中。中间元素小于第一个元素，
    则中间元素位于后面的递增子数组，此时最小元素位于中间元素的前面。我们可以让第二个指针right指向中间元素。移动之后，
    第二个指针仍然位于后面的递增数组中。
    （3）按照以上思路，第一个指针left总是指向前面递增数组的元素，第二个指针right总是指向后面递增的数组元素。  
  最终第一个指针将指向前面数组的最后一个元素，第二个指针指向后面数组中的第一个元素。也就是说他们将指向两个相邻的元素，
  而第二个指针指向的刚好是最小的元素，这就是循环的结束条件。
*/
class Solution 
{
public:
    int minNumberInRotateArray(vector<int> rotateArray) 
    {
    	int size =rotateArray.size();
    	if (size==0)   //若数组大小为0，请返回0
    	{
    		return 0;
    	}
    	int left=0;
   		int right=size-1;
    	int mid=0;
    	while(rotateArray[left]>=rotateArray[right])  //确保旋转。即左边的数字大于等于右边
    	{
    		if (right-left==1)  //判断是否结束
    		{
    			mid=right;
    			break;
    		}
    		mid=left+(right-left)/2;   //找中间的数
    		//当中间的元素位于前面的递增数组
    		if (rotateArray[mid]>=rotateArray[left]) 
    		{
    			left=mid;
    		}
    		else   //中间的元素位于后面的递增数组
    		{
    			right=mid;
    		}
    		if ((rotateArray[left]==rotateArray[right])&&(rotateArray[mid]==rotateArray[right]))//不正常情况下，三个数相等只能排序
    		{
    			return Sort(rotateArray,left,right);
    		}
    	}
    	
    	return rotateArray[mid];
    }
private:
    int  Sort(vector<int> num,int left,int right)
    {
    	int result=num[left];
    	for (int i = left+1; i < right; ++i)
    	{
    		if (num[i]<result)
    		{
    			result=num[i];
    		}
    	}
    	return result;
    }
};
int main(int argc, char const *argv[])
{
	Solution s1;
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(1);
	v1.push_back(2);
	//vector<int> v1={3,4,5,6,1,2};  //c++11标准可以用
	 int result=s1.minNumberInRotateArray(v1); 
	 cout<<result<<endl;
	return 0;
}

//以下方法思路更简单

// class Solution
// {
// public:
//     int minNumberInRotateArray(vector<int> arr)
//     {
//         int arr_len=arr.size();
//         if (arr_len==0)
//         {
//             return 0;
//         }
//         int left=0;
//         int right=arr_len-1;
//         int mid=0;
//         while(arr[left]>=arr[right])
//         {
//             if(right-left==1)
//             {
//                 mid=right;
//                 break;
//             }
//             mid=left+(right-left)/2;
//             if (arr[mid]>=arr[left])
//             {
//                 left=mid;
//             }
//             if (arr[mid]<=arr[right])
//             {
//                 right=mid;
//             }
//         }
//         return arr[mid];
//     }
// };

// int main(int argc, char const *argv[])
// {
//     Solution s1;
//     vector<int> v1;
//     v1.push_back(3);
//     v1.push_back(4);
//     v1.push_back(5);
//     v1.push_back(6);
//     v1.push_back(1);
//     v1.push_back(2);
//     int result=s1.minNumberInRotateArray(v1);
//     cout<<result<<endl;
//     return 0;
// }
