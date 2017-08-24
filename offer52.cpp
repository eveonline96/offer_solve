#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

*/
// class Solution 
// {
// public:
//     bool isNumeric(char* string)
//     {
//     	int dian=0;
//     	int e=0;
//     	int sub=0;
//         if (string[0]<='9' || string[0] >='0' || string[0]=='-' || string [0]=='+')
//         {
//             if(string[0]=='-' || string [0]=='+')
//             {
//                 sub++;
//                  if(string[1]=='-' || string[1]=='+')
//                   return false;
// 			}
//             if(string[1]=='-' || string[1]=='+')
//                   return false;
//         	for (int i = 1; i < strlen(string); ++i)
//         	{
//                 if(string[i]=='a')
//                     return  false;
//         		if (string[i]<='9' || string[i] >='0' || string[i]=='.' || string [i]=='e' ||string[i]=='E')
//         		{
                   
//         			if (string[i]=='.')
// 	        		{
// 	        			++dian;
// 	        			if (e==1)
// 	        			{
// 	        				return false;
// 	        			}
// 	        			if (dian>1)
// 	        				return false;
// 	        		}

// 	        		if (string [i]=='e' ||string[i]=='E')
// 	        		{
// 	        			++e;
//                         if (e==1)
// 	        			{
// 	        				if (string[i+1]=='\0')
// 	        				   return false;
// 	        			}
// 	        			if (e>1)
// 	        				return false;
// 	        		}

// 	        		if (string[i]=='-' || string[i]=='+')
// 	        		{
// 	        			++sub;
                       
// 	        			if (sub>2)
// 	        				return false;
// 	        		}
                    
//                      if(dian==1 && e==1 &&sub==1)
//                         return true;

//                     if((string[i]=='-' || string [i]=='+' )&& dian==0 && e==0)
//                         return false;
//                     printf("234\n");
//                     printf("%d\n",e);
//                     cout<<"123"<<endl;
//         		}
//         		else
//         			return false;
//         	}
//         	return true;
//         }
//         else
//         	return false;
//     }
// };
//注意表示数值的字符串遵循的规则；
//在数值之前可能有一个“+”或“-”，接下来是0到9的数位表示数值的整数部分，如果数值是一个小数，那么小数点后面可能会有若干个0到9的数位
//表示数值的小数部分。如果用科学计数法表示，接下来是一个‘e’或者‘E’，以及紧跟着一个整数（可以有正负号）表示指数。
class Solution {
public:
    bool isNumeric(char* string)
    {
        if(string==NULL)
            return false;
        if(*string=='+'||*string=='-')
            string++;
        if(*string=='\0')
            return false;
        int dot=0,num=0,nume=0;//分别用来标记小数点、整数部分和e指数是否存在
        while(*string!='\0'){
            if(*string>='0'&&*string<='9')
            {  
                string++;
                num=1;
            }
            else if(*string=='.'){
                if(dot>0||nume>0)
                    return false;
                string++;
                dot=1;
            }
            else if(*string=='e'||*string=='E')
                {
                  if(num==0||nume>0)
                      return false;
                  string++;
                  nume++;
                  if(*string=='+'||*string=='-')
                      string++;
                 if(*string=='\0')
                     return false;
                }
            else
                return false;
        }
        return true;
    }
 
};

int main(int argc, char const *argv[])
{
	Solution s1;
	char buf[]="-1E-16";
	bool res=s1.isNumeric(buf);
	cout<<res<<endl;
	return 0;
}