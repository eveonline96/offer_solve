#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行！
*/
class Solution {
public:
    string ReverseSentence(string str) 
    {	
    	int len=str.length();
    	if(len<=0)
    		return NULL;
    	string tmp="";
    	string res="";
    	for (int i = 0; i < len; ++i)
    	{
    		if (str[i]==' ')
    		{
    			res=" " +tmp+res;
    			tmp="";
    		}
    		else
    			tmp+=str[i];
    	}
    	if(tmp.size())
    				res=tmp+res;
    	return res;   
    }
};
int main(int argc, char const *argv[])
{
	Solution s1;
	string str1="I am a good boy.";
	string res=s1.ReverseSentence(str1);
	cout<<res<<endl;
	return 0;
}