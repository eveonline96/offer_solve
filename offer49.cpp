#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，
但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2

1、判断输入数组有无元素非法
2、从头扫到尾，只要当前元素值与下标不同，就做一次判断,numbers[i]与numbers[numbers[i]]，相等就认为找到了
重复元素，返回true,否则就交换两者，继续循环。直到最后还没找到认为没找到重复元素，返回false

*/
// Parameters:
//        numbers:       an array of integers
//        length:        the length of array numbers
//        duplication:   (Output) the duplicated number in the array number
//Return value:  true if the input is valid, and there are some duplications in the array number
//       otherwise false
class Solution
{
public:
    
    bool duplicate(int numbers[], int length, int* duplication) 
    {
        if (length<=0 || numbers==NULL)
        	return false;
        //judge inlegle
// 		for(int i=0;i<length;++i)
//         {
//             if(numbers[i]<=0||numbers[i]>length-1)
//                 return false;
//         }
        for(int i=0;i<length;++i)
        {
            while(numbers[i]!=i)
            {
                if(numbers[i]==numbers[numbers[i]])
                {
                    *duplication = numbers[i];
                    return true;
                }
                //交换numbers[i]和numbers[numbers[i]]
                int temp = numbers[i];
                numbers[i] = numbers[temp];
                numbers[temp] = temp;
            }
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{
	
	return 0;
}