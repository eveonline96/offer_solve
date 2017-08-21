#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
*/
class Solution 
{
public:
    int FirstNotRepeatingChar(string str)
     {
     	
     	int str_len=str.size();
     	if(str_len==0)
     		return -1;
     	char ch[256]={0};
     	for(int i=0;i<str_len;i++)
     		ch[str[i]]++;
     	for(int i=0;i<str_len;i++)
     		if(ch[str[i]]==1)
     			return i;
     	return 0;
    }
};
int main(int argc, char const *argv[])
{
	Solution s1;
	string str="ababcacbdcdfffresefsdfsdfsddfsds";
	int res=s1.FirstNotRepeatingChar(str);
	cout<<res<<endl;
	cout<<str[res]<<endl;
	return 0;
}