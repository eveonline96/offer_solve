#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。
 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

核心思路：
1.从(0,0)开始走，每成功走一步标记当前位置为true,然后从当前位置往四个方向探索，
返回1 + 4 个方向的探索值之和。
2.探索时，判断当前节点是否可达的标准为：
1）当前节点在矩阵内；
2）当前节点未被访问过；
3）当前节点满足limit限制。
3.
运行时间：31ms
占用内存：550k
*/


class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
       bool *flag = new bool[rows * cols];
        for(int i = 0; i < rows * cols; i++)
            flag[i] = false;
        int count = moving(threshold, rows, cols, 0, 0, flag);
        return count; 
    }
     int moving(int threshold, int rows, int cols, int i, int j, bool* flag)
        {
        int count = 0;
        if(i >= 0 && i < rows && j >= 0 && j < cols && getsum(i) + getsum(j) <= threshold && flag[i * cols + j] == false)
            {
            flag[i * cols + j] = true;
            count =1 + moving(threshold, rows, cols, i + 1, j, flag)
                + moving(threshold, rows, cols, i - 1, j, flag)
                + moving(threshold, rows, cols, i , j - 1, flag)
                + moving(threshold, rows, cols, i, j + 1, flag);
        }
        return count;
    }
    int getsum(int num)
        {
        int sum = 0;
        while(num)
            {
            sum += num % 10;
            num /= 10;
              
        }
        return sum;
    }
};


    
public:
    int movingCount(int threshold, int rows, int cols)
    {
        int cnt=0;
        int a,b,c,d;
        int count1=0,count2=0;
        for (int i = 0; i < cols; ++i)
        {
        	for (int j = 0; j < rows; ++j)
        	{
        		int count1=0,count2=0;
        		//cout<<"123"<<endl;
        		int c=i;
        		int r=j;
        		while(c!=0)
        		{
        			b=c%10;
        			count1+=b;
        			c=c/10;
        		}
        		while(r!=0)
        		{
        			b=r%10;
        			count2+=b;
        			r=r/10;
        		}
        		if (count1+count2>threshold)
        		{
        			continue;
        		}
        		cnt++;
        	}
        }
        return cnt;
    }
};
int main(int argc, char const *argv[])
{
	Solution s1;
	int res=s1.movingCount(15,20,20);
	cout<<res<<endl;
	return 0;
}