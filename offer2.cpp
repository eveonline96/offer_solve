#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
/*请实现一个函数，将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.
则经过替换之后的字符串为We%20Are%20Happy。*/
// class Solution 
// {
// public:
// 	void replaceSpace(char *str,int length) 
// 	{
// 		char buf[100];
// 		bzero(buf,sizeof(buf));
// 		for (int i =0,j=0;i<length; ++i)  //定义两个参数独立进行
// 		{

// 			if (str[i]==' ')
// 			{
// 				buf[j]='%';
// 				j++;
// 				buf[j++]='2';
// 				buf[j++]='0';
// 			}
// 			else
// 			{
// 				buf[j]=str[i];
// 				j++;
// 			}
// 		}
// 		cout<<buf<<endl;
// 	}
// };

class Solution
 {
public:
	void replaceSpace(char *str,int length) 
	{
		if (str==NULL||length<=0)
			return ;
	    int blank=0;  //black num
	    int ori_len=0;//origin length
	    int str_len =0 ;  //string length
		for (int i = 0; str[i] !='\0' ; ++i)
		{
			ori_len++;
			if (str[i]==' ')
				blank++;
		}
		str_len =ori_len+2*blank ; 
		printf("%d\t%d\n",ori_len,str_len);
		if (str_len>length)
			return;
		for (int j = str_len ,i=ori_len; i>=0 ; --i)
		{
			if (str[i]==' ')
			{
				str[j--]='0';
				str[j--]='2';
				str[j--]='%';
			}
			else
			{
				str[j--]=str[i];
			}
		}
	}
};


// class Solution {
// public:
//     void replaceSpace(char *str,int length) {
// if (str==NULL||length<=0)
//     return;
//         int spacenum=0;
//         int origi_len = 0;
//         for (int i=0;i!='/0';i++){
//             origi_len++;
//             if (str[i]==' ')
//                 spacenum++;
//         }
//         int newlen = origi_len +2*spacenum;
//         int change = newlen;
//         for (int j=origi_len;j>=0&&change>j;j--){
//             if(str[j]==' '){
//                 str[change]='0';
//                 change--;
//                 str[change]='2';
//                 change--;
//                 str[change]='%';
//             }
//             else{
//                 str[change]=str[j];
//             }
//             change--;
//         }
//     }
// };

int main(int argc, char const *argv[])
{
	char st[]="We are Happy";
	int len=100;
	Solution s1;
	s1.replaceSpace(st,len);
	printf("%s\n",st);
	return 0;
}
