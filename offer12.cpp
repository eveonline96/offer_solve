#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
/*
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

快速求正整数次幂，当然不能直接死乘。举个例子：
3 ^ 999 = 3 * 3 * 3 * … * 3
直接乘要做998次乘法。但事实上可以这样做，先求出2^k次幂：
3 ^ 2 = 3 * 3
3 ^ 4 = (3 ^ 2) * (3 ^ 2)
3 ^ 8 = (3 ^ 4) * (3 ^ 4)
3 ^ 16 = (3 ^ 8) * (3 ^ 8)
3 ^ 32 = (3 ^ 16) * (3 ^ 16)
3 ^ 64 = (3 ^ 32) * (3 ^ 32)
3 ^ 128 = (3 ^ 64) * (3 ^ 64)
3 ^ 256 = (3 ^ 128) * (3 ^ 128)
3 ^ 512 = (3 ^ 256) * (3 ^ 256)
再相乘：
3 ^ 999
= 3 ^ (512 + 256 + 128 + 64 + 32 + 4 + 2 + 1)
= (3 ^ 512) * (3 ^ 256) * (3 ^ 128) * (3 ^ 64) * (3 ^ 32) * (3 ^ 4) * (3 ^ 2) * 3

fabs函数求浮点数x的绝对值
abs函数是针对整数的
*/
class Solution {
public:
    double Power(double base, int exponent) 
    {
    	double result=1; //结果
    	int exp=exponent;
    	//指数为零
    	if (exponent==0)
    	{
    		return 1;
    	}
    	//分母不能为零, 判断double类型变量是否和0相等
    	if ((exponent<0)&&(fabs(base)<=1e-15))
    	{
    		cout<<"error"<<endl;
    	}
    	if (exponent<0)
    	{
    		exp=-exp;
    	}
    	while(exp)
    	{
    		if ((exp&1)==1)
    		{
    			result*=base;
    		}
    		base*=base;
    		exp>>=1;
    	}

    	return exponent>0? result:(1/result);   
    }
};
int main(int argc, char const *argv[])
{
	Solution s1;
	double d1=2;
	int n=-5;
	double result=s1.Power(d1,n);
	cout<<result<<endl;
	return 0;
}
