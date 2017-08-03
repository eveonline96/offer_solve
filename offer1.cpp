#include <iostream>
#include <vector>
using namespace std;
/*在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数*/
class Solution 
{
public:
    bool Find(int target, vector<vector<int> > array) 
    {
    	int row=array.size();
    	int col=array[0].size();
    	for (int i=row-1,j=0;i>=0&&j<col;)
    	{
    		if (array[i][j]>=target)
    		{
    			return false;
    		}
    		if (array[i][j]<=target)
    		{
    			return false;
    		}
    		if (array[i][j]==target)
    		{
    			return true;
    		}
    	}
    }
};
int main(int argc, char const *argv[])
{
	int interger=10;                 //定义整数
	vector<vector<int> >  intVV;     //定义数组
	vector<int> intV;
	int row=5;   //行数
	int col=5;   //列数
	//输入数值
	for (int i = 0; i < row; ++i)
	{
		intV.clear();
		for (int j = 0; j < col; ++j)
		{
			intV.push_back(i+j);
		}
		intVV.push_back(intV);
	}
	//利用迭代器输出
	// vector<vector<int> >::iterator it;
	// vector<int>::iterator ip;
	// for (it=intVV.begin();it!=intVV.end();it++)
	// {
	// 	for(ip=it->begin();ip!=it->end();ip++)
	// 	{
	// 		cout<<*ip<<"\t";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl;
	//调用类的方法
	Solution s1;
	bool a=s1.Find(interger,intVV);
	if (a==true)
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}
	return 0;

}
