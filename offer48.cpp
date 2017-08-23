#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0
示例1
输入

+2147483647
    1a33
输出

2147483647
    0
思路：
*/
class Solution {
public:
    int StrToInt(string str) {
        int len=str.length();
        if(len==0)
            return 0;
        int dig=true;
        int i=0;
        int num=0;
        //滤掉前面的空格
        while(str[i]==' ')
            i++;
        //进行符号判断
        if(str[i]=='+')
            i++;
        else if(str[i]=='-')
        {
            i++;
            dig*=false;
        }
        while(str[i]!='\0')
        {
            //对字符进行是否为数字的判断
            if(str[i]>='0'&&str[i]<='9')
            {
                int flag=dig?1:-1;
                num=num*10+flag*(str[i]-'0');
                //对数字是否溢出进行判断
               if((dig && num>0x7FFFFFFF)||(dig && num<(signed int)0x80000000))
               {
                   num=0;
                   break;
               }
               i++;
            }
            else
            {
                num=0;
                break;
            }

        }
        return num;
    }
};

int main(int argc, char const *argv[])
{
	Solution s1;
	string str="-123455678";
	int res =s1.StrToInt(str);
	cout<<res<<endl;
	return 0;
}