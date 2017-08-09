#include <iostream>
#include <vector>
using namespace std;
/*
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39

*/
class Solution 
{
public:
	//递归写法
    // int Fibonacci(int n) 
    // {
    // 	if (n==0)
    // 	{
    // 		return 0;
    // 	}
    // 	if (n==1)
    // 	{
    // 		return 1;
    // 	}
    // 	if (n>1)
    // 	{
    // 		return Fibonacci(n-1)+Fibonacci(n-2);
    // 	}
    // }

    //迭代写法
   	int Fibonacci(int n)
   	{
   		int a=0;   //n=0时的情况
   		int b=1;
   		while(n-->0)
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
	int n=38;
	int result=s1.Fibonacci(n);
	cout<<result<<endl;
	return 0;
}
