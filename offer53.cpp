#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
请实现一个函数用来找出字符流中第一个只出现一次的字符。
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符


对这个题目思考，可以发现，出现的字符 和 它的出现的次数 是一种对应关系，自然联想到 哈希表的
  key-value 这种对应，或者应用关联容器
  map，可以很方便的解决这个问题。 
  map 容器中，它的一个元素 就是一组（key，value）对应的数据
*/

// class Solution 
// {
// public:
// 	void Insert(char ch)
// 	{
// 		vec.push_back(ch);
// 		mapdata[ch]++;
// 	}
// 	char FirstAppearingOnce()
// 	{
// 		vector<int>::iterator it;
// 		for (it= vec.begin(); it!=vec.end(); ++it)
// 		{
// 			if(mapdata[*it]==1)
// 				return *it;
// 		}
// 		return '#';
// 	}
// 	map<char,int> mapdata;
// 	vector<int> vec;
// };
class Solution
{
public:
    string str;
  //Insert one char from stringstream
    void Insert(char ch)
    {
         str += ch;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char cc[256] = {0};
        for(int i = 0; i < str.length(); i++) {
            cc[str[i]]++;
        }
        for(int i = 0; i < str.length(); i++) {
            if(cc[str[i]] == 1)
                return str[i];
        }
        return '#';
    }
 
};

int main(int argc, char const *argv[])
{
	Solution s1;
	s1.Insert('g');
	s1.Insert('o');
	s1.Insert('o');
	s1.Insert('g');
	s1.Insert('l');
	char ch=s1.FirstAppearingOnce();
	cout<<ch<<endl;	
	return 0;
}