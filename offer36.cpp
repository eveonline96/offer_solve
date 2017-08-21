#include <string.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
输入两个链表，找出它们的第一个公共结点

*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

	ListNode *list1_cerate(int num)
	{
		ListNode*head_ListNode=(ListNode*)malloc(1*sizeof(ListNode));
		ListNode*curr_ListNode;
		ListNode*new_ListNode;
		while(head_ListNode==NULL)
		{
			head_ListNode=(ListNode *)malloc(1*sizeof(ListNode));
		}
		head_ListNode->val=-1;
		head_ListNode->next=NULL;
		curr_ListNode=head_ListNode;
		int i;
		for(i=0;i<num;i++)
		{
			new_ListNode=(ListNode*)malloc(1*sizeof(ListNode));
			while(new_ListNode==NULL)
			{
				new_ListNode=(ListNode*)malloc(1*sizeof(ListNode));
			}
			new_ListNode->val=i;
			new_ListNode->next=NULL;
			curr_ListNode->next=new_ListNode;
			curr_ListNode=new_ListNode;
			new_ListNode=NULL;
		}
		return head_ListNode;
	}
	ListNode *list2andlist1_cerate(int num,ListNode*head1_ListNode)
	{
		ListNode*head_ListNode=(ListNode*)malloc(1*sizeof(ListNode));
		ListNode*curr_ListNode;
		ListNode*new_ListNode;
		while(head_ListNode==NULL)
		{
			head_ListNode=(ListNode *)malloc(1*sizeof(ListNode));
		}
		head_ListNode->val=4;
		head_ListNode->next=NULL;
		curr_ListNode=head_ListNode;
		int i;
		for(i=0;i<num;i++)
		{
			new_ListNode=(ListNode*)malloc(1*sizeof(ListNode));
			while(new_ListNode==NULL)
			{
				new_ListNode=(ListNode*)malloc(1*sizeof(ListNode));
			}
			new_ListNode->val=i+5;
			new_ListNode->next=NULL;
			curr_ListNode->next=new_ListNode;
			curr_ListNode=new_ListNode;
			new_ListNode=NULL;
		}
		curr_ListNode->next=head1_ListNode;//将list1接到list2的尾部
		return head_ListNode;
	}
    ListNode* FindFirstCommonListNode( ListNode* pHead1, ListNode* pHead2) 
    {
    	if ((pHead1==NULL)||(pHead2==NULL))
			return NULL;
    	ListNode *curr=pHead1;
	    while(curr!=NULL)
	    {
	    	curr=curr->next;
	    }
	    curr->next=pHead2;
	    ListNode *fast=pHead2;
		ListNode *slow=pHead2;
		while(fast&&fast->next)
		{
			fast=fast->next->next;
			slow=slow->next;
			if (fast==slow)
				break;
		}
		return slow;
		slow=pHead2;
		while(slow!=fast)
		{
			slow=slow->next;
			fast=fast->next;
		}
		return slow;
    }

int main(int argc, char const *argv[])
{
	ListNode *head1=list1_cerate(10);
	ListNode *head2=list2andlist1_cerate(10,head1);
	ListNode *res=FindFirstCommonListNode(head1,head2);
	cout<<res->val<<endl;
	return 0;
}