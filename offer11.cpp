#include <iostream>
#include <vector>
using namespace std;
/*
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示
整解：通过左移位数字1的方法，无论输入数有几个1，就得循环移位32次
最优解：n&(n-1)表示将一个整数的二进制形式的最后一个1变为0.所以可以利用这个特性来计算1的数量。
*/
// class Solution 
// {
// public:
//  int  NumberOf1(int n) 
//  {
//  	 int cnt=0; //记录1的个数
//  	 int flag=1;
//  	 while(flag!=0)  //循环32位
//  	 {
//  	 	if ((flag&n)!=0)
//  	 	{
//  	 		cnt++;
//  	 	}
//  	 	flag=flag<<1;
//  	 }
//  	 return cnt;
//  }
// };
class Solution 
{
public:
 int  NumberOf1(int n) 
 {
 	 int cnt=0; //记录1的个数
 	 while(n!=0)  //循环32位
 	 {
 	 	++cnt;
 	 	n=(n-1)&n;
 	 }
 	 return cnt;
 }
};
int main(int argc, char const *argv[])
{
	Solution s1;
	int n=11;
	int result=s1.NumberOf1(n);
	cout<<result<<endl;
	return 0;
}
