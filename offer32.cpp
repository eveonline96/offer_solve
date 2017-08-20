#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323
思路：
*对vector容器内的数据进行排序，按照 将a和b转为string后
 若 a＋b<b+a  a排在在前 的规则排序,
 如 2 21 因为 212 < 221 所以 排序后为 21 2 
to_string() 可以将int 转化为string

sort中的比较函数compare要声明为静态成员函数或全局函数，不能作为普通成员函数，否则会报错。 
因为：非静态成员函数是依赖于具体对象的，而std::sort这类函数是全局的，因此无法再sort中调用非静态成员函数。
静态成员函数或者全局函数是不依赖于具体对象的, 可以独立访问，无须创建任何对象实例就可以访问。
同时静态成员函数不可以调用类的非静态成员
*/

class Solution 
{
public:
    string PrintMinNumber(vector<int> numbers) 
    {
        int len = numbers.size();
        if(len == 0) return "";
        sort(numbers.begin(), numbers.end(), cmp);
        string res;
        for(int i = 0; i < len; i++)
        {
            res += to_string(numbers[i]);
        }
        return res;
    }
    static bool cmp(int a, int b){
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        return A < B;
    }
};

int main(int argc, char const *argv[])
{
	Solution s1;
	vector<int> array;
	array.push_back(3);
	array.push_back(32);
	array.push_back(321);
	string res=s1.PrintMinNumber(array);
	cout<<res<<endl;
	return 0;
}