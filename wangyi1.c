#include <stdio.h>
#include <iostream>
using namespace std;
/*
题目描述
有 n 个学生站成一排，每个学生有一个能力值，
牛牛想从这 n 个学生中按照顺序选取 k 名学生，
要求相邻两个学生的位置编号的差不超过 d，
使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？
输入描述:
每个输入包含 1 个测试用例。
每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，
表示学生的个数，接下来的一行，包含 n 个整数，
按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。
接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。
输出描述:
输出一行表示最大的乘积。
示例1
输入

3
7 4 7
2 50
输出

49
*/
int main(int argc, char const *argv[])
{
	int n,k,d,tmp,temp;
	long long int res=0;
	scanf("%d",&n);

	int buf[n];
	int i=0,j;
	for(i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		buf[i]=tmp;
	}
	scanf("%d %d",&k,&d);
	long long int fm[11][50]={0},fn[11][50]={0};
	int a,b,m;
	for(j=0;j<n;j++)
	{
		for(i=1;i<=k;i++)  //k个人开始查找
		{
			if (i==1)
			{
				fm[i][j]=buf[j]; 
				fn[i][j]=buf[j];
				continue;
			}
			for(m=1;m<=d;m++)  //在限定范围内查询
			{
				if (j-m>=0 && j-m<n)
				{
					// fm[i][j] = max(fm[i][j], max(fm[i - 1][j - m] * buf[j], fn[i - 1][j - m] * buf[j]));
                    //fn[i][j] = min(fn[i][j], min(fm[i - 1][j - m] * buf[j], fn[i - 1][j - m] * buf[j]));
					a=fm[i - 1][j - m] * buf[j];   //[第k-1人][k-1人的位置]
					b=fn[i - 1][j - m] * buf[j];
					//int c=fm[i][j];
					//int d=fn[i][j];
					//max =a+b?(a>c?a:c):(b>c?b:c);
					temp=(a>=b)?a:b;
					fm[i][j]=(fm[i][j]>=temp)?fm[i][j]:temp;
					temp=(a<=b)?a:b;
					fn[i][j]=(fn[i][j]<=temp)?fn[i][j]:temp;

				}
			}
		}
		res = max(res, fm[k][j]);
		//res=(res>fm[k][j])?res:fm[k][j];
	}
	
	printf("%ld\n",res);
	return 0;
}



