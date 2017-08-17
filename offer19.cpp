#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;
/*
题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

解题思路：顺时针打印就是按圈数循环打印，一圈包含两行或者两列，
1.在打印的时候会出现某一圈中只包含一行，要判断从左向右打印和从右向左打印的时候
是否会出现重复打印，
2.同样只包含一列时，要判断从上向下打印和从下向上打印的时候
是否会出现重复打印的情况
*/
class Solution 
{
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int>res;
        res.clear();
        int row=matrix.size();//行数
        int collor=matrix[0].size();//列数
        //计算打印的圈数
        int circle=((row<collor?row:collor)-1)/2+1;//圈数
        for(int i=0;i<circle;i++){
            //从左向右打印
            for(int j=i;j<collor-i;j++)
                res.push_back(matrix[i][j]);          
            //从上往下的每一列数据 
            for(int k=i+1;k<row-i;k++)
                res.push_back(matrix[k][collor-1-i]);
            //判断是否会重复打印(从右向左的每行数据) 
            for(int m=collor-i-2;(m>=i)&&(row-i-1!=i);m--) 
                res.push_back(matrix[row-i-1][m]); 
            //判断是否会重复打印(从下往上的每一列数据)
            for(int n=row-i-2;(n>i)&&(collor-i-1!=i);n--) 
                res.push_back(matrix[n][i]);}
        return res;
    }
};

/*
* 1.选坐标为(0,0),(1,1)...的点记为(start,start)为开始坐标,下一圈开始坐标为(start+1,start+1)
* 2.判断是否进入下一圈(即是否打印完成)的条件是row>start*2 && column>start*2
* 3.打印一圈的左上角坐标为(start,start)，右下角的坐标为(column-start-1,row-start-1)
* 4.根据一圈左上角和右下角坐标判断“从左到右”，“从上到下”，“从右到左”，“从下到上”哪些用打印，哪些不用
*/
 
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if (matrix.empty()) {
            return matrix[0];
        }
        int row = static_cast<int>(matrix.size()) ;
        int column = static_cast<int>(matrix[0].size()) ;
        int start = 0;
        vector<int> result;
        result.clear();
         
        while (column > start*2 && row > start*2) 
		{
            int endY = column - 1 - start;
            int endX = row - 1 - start;
            //从左到右打印一行
            for (int i=start; i<=endY; i++) {
                result.push_back(matrix[start][i]);
            }
            //从上到下打印一行
            if (start <endX) 
			{
                for (int i=start+1; i<=endX; i++) {
                    result.push_back(matrix[i][endY]);
                }
            }
            //从右到左打印一行
            if (start < endY && start < endX) {
                for (int i=endY-1; i>=start; i--) {
                    result.push_back(matrix[endX][i]);
                }
            }
            //从下到上打印一行
            if (start<endY && start<endX-1) {
                for (int i=endX-1; i>=start+1; i--) {
                    result.push_back(matrix[i][start]);
                }
            }
            start++;
        }
        return result;
    }
};