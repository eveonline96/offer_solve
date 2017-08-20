/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，
因此输出2。如果不存在则输出0

思路： 第一种解法利用快排 sort 时间复杂度为 O(nlog(n))
   	第二种解法：时间复杂度
   	采用阵地攻守的思想： 第一个数字作为第一个士兵，
   	守阵地；count = 1； 遇到相同元素，count++; 
   	遇到不相同元素，即为敌人，同归于尽,count--；
   	当遇到count为0的情况，又以新的i值作为守阵地的士兵，
   	继续下去，到最后还留在阵地上的士兵，有可能是主元素。 
   	再加一次循环，记录这个士兵的个数看是否大于数组一般即可
*/
#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;

// class Solution 
// {
// public:
//     int MoreThanHalfNum_Solution(vector<int> numbers) 
//     {
// 		int temp=numbers[0];
// 		int cnt=0;
// 		int v_size=numbers.size();
// 		sort(numbers.begin(),numbers.end());
// 		for(int i=0;i<v_size;i++)
// 		{
// 			if (temp==numbers[i])
// 			{
// 				cnt++;
// 			}
// 			else
// 			{
// 				temp=numbers[i];
// 				cnt=0;
// 			}
// 			if (cnt>=(v_size/2))
// 			{
// 				return temp;
// 			}
// 		}
// 		return 0; 
//     }
// };
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> array) 
    {
        int length=array.size();
        if(length<=0)
            return 0;
        int result=array[0];
        int times=1;
        for(int i=1;i<length;i++)
        {
            if(times==0)
            {
                result=array[i];
                times=1;
            }
            else
            {
                if(array[i]==result)
                    times++;
                else
                    times--;
            }
        }
        
        times=0;
        for(int i=0;i<length;i++)
        {
            if(result==array[i])
                times++;
       }
            
       if(times*2<length)
           result=0;
       return result;
    }
};
int main(int argc, char const *argv[])
{
	Solution s1;
	vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(2);
	numbers.push_back(2);
	numbers.push_back(2);
	numbers.push_back(5);
	numbers.push_back(4);
	numbers.push_back(2);
	int result=s1.MoreThanHalfNum_Solution(numbers);
	cout<<result<<endl;
	return 0;
}