#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
/*
输入一个链表，输出该链表中倒数第k个结点。
快慢指针
*/
//定义链表
struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
    {
    	if(pListHead==NULL||k<=0)  //考虑数组为空时和数字越界的情况
        {
            return NULL;
		}
    	fast_node=pListHead;
    	slow_node=pListHead;
    	for (int i = 0; i < (int)k; ++i)
    	{
    		 if(fast_node!=NULL)  
             {
               fast_node=fast_node->next; 
            }
            else
            {
              return NULL;  
            }	
    	}
    	while(fast_node)
    	{
    		fast_node=fast_node->next;
    		slow_node=slow_node->next;
    	}
    	return slow_node;
    }
public: ListNode*  List_Create(int n)
{
	head_node=(ListNode*)malloc(1*sizeof(ListNode));
	while(head_node==NULL)
	{
		head_node=(ListNode*)malloc(1*sizeof(ListNode));
	}
	head_node->val=100;
	head_node->next=new_node;
	curr_node=head_node;
	for (int i = 0; i < n; ++i)
	{
		new_node=(ListNode*)malloc(1*sizeof(ListNode));
		while(new_node==NULL)
		{
			new_node=(ListNode*)malloc(1*sizeof(ListNode));
		}
		new_node->val=i;
		new_node->next=NULL;
		curr_node->next=new_node;
		curr_node=new_node;
		new_node=NULL;
	}
	return head_node;
}
private:
	ListNode* head_node;
	ListNode* curr_node;
	ListNode* new_node;
	ListNode* fast_node;
	ListNode* slow_node;

};

int main(int argc, char const *argv[])
{
	Solution s1;
	ListNode* head=s1.List_Create(10);
	ListNode* result=s1.FindKthToTail(head,11);
	cout<<result->val<<endl;
}
