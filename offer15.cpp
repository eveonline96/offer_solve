#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
/*
输入一个链表，反转链表后，输出链表的所有元素。
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution 
{
public:
    ListNode* ReverseList(ListNode* pHead) 
    {
    	head_node=pHead;
    	curr_node=NULL;
    	while(head_node!=NULL)
    	{
    		new_node=head_node->next;
    		head_node->next=curr_node;
    		curr_node=head_node;
    		head_node=new_node;
    	}
    	return curr_node;
    }
    ListNode *List_Create(int n)
    {
    	head_node=(ListNode*)malloc(1*sizeof(ListNode));
    	while(head_node==NULL)
    	{
    		head_node=(ListNode*)malloc(1*sizeof(ListNode));
    	}
    	head_node->val=100;
    	head_node->next=NULL;
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
    void printListFromTailToHead(ListNode* pHead)
    {
		curr_node=pHead;
		while(curr_node!=NULL)
		{
			cout<<curr_node->val<<endl;
			curr_node=curr_node->next;
		}
    }
private:
	ListNode *head_node;
	ListNode *curr_node;
	ListNode *new_node;
};
int main(int argc, char const *argv[])
{
	Solution s1;
	ListNode* head=s1.List_Create(10);
	ListNode* result=s1.ReverseList(head);
	s1.printListFromTailToHead(result);
	return 0;
}