#include <iostream>
#include <vector>
using namespace std;
/*一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
类似斐波那契数列f(n)=f(n+1)+f(n+2)
*/
class Solution 
{
	//递归
//public:
    // int jumpFloor(int number) 
    // {
    //     if (number==1)
    // 	{
    // 		return 1;
    // 	}
    // 	if (number==2)
    // 	{
    // 		return 2;
    // 	}
    // 	if (number>2)
    // 	{
    // 		return jumpFloor(number-1)+jumpFloor(number-2);
    // 	}
    //	return -1;
    // }
    //迭代算法
public: int jumpFloor(int number) 
    {
        int a=1;   //n=0时的情况
   		int b=2;
   		// number++;
   		while(number-->1)
   		{
   			b=a+b;   //n=1个数然后倒推
   			a=b-a;
   		}
   		return a;
    }
	
};
int main(int argc, char const *argv[])
{
	Solution s1;
	int n=8;
	int result=s1.jumpFloor(n);
	cout<<result<<endl;
	return 0;
}
