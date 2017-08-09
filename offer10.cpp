#include <iostream>
#include <vector>
using namespace std;
/*我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
当n=1时，1
当n=2时，2
当n=3时，3
当n=4时，5
*/
class Solution 
{
	public:
	int rectCover(int number) 
	{
		if (number==0)
		{
			return 0;
		}
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
	int n=4;
	int result=s1.rectCover(n);
	cout<<result<<endl;
	return 0;
}