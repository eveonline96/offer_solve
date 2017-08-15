#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
/*
输入两个单调递增的链表，输出两个链表合成后的链表，
当然我们需要合成后的链表满足单调不减规则。
*/

struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution 
{
public:
	ListNode* List_Create(int n)
	{
		head_node=(ListNode*)malloc(1*sizeof(ListNode));
		while(head_node==NULL)
		{
			head_node=(ListNode*)malloc(1*sizeof(ListNode));
		}
		head_node->val=-1;
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
	ListNode* List_Create2(int n)
	{
		head_node=(ListNode*)malloc(1*sizeof(ListNode));
		while(head_node==NULL)
		{
			head_node=(ListNode*)malloc(1*sizeof(ListNode));
		}
		head_node->val=-1;
		head_node->next=NULL;
		curr_node=head_node;
		for (int i = 0; i < n; ++i)
		{
			new_node=(ListNode*)malloc(1*sizeof(ListNode));
			while(new_node==NULL)
			{
				new_node=(ListNode*)malloc(1*sizeof(ListNode));
			}
			new_node->val=i+10;
			new_node->next=NULL;
			curr_node->next=new_node;
			curr_node=new_node;
			new_node=NULL;
		}
		return head_node;
	}
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        list1_head=pHead1;
        list2_head=pHead2;
        new_node=(ListNode*)malloc(1*sizeof(ListNode));
        while(new_node==NULL)
        {
        	new_node=(ListNode*)malloc(1*sizeof(ListNode));
        }
        new_node->val=-100;
        new_node->next=NULL;
        Merge_head=new_node;
        while(list1_head&&list2_head)
        {
        	if (list1_head->val<=list2_head->val)
        	{
        		new_node->next=list1_head;
        		new_node=new_node->next;
        		list1_head=list1_head->next;
        	}
        	else
        	{
        		new_node->next=list2_head;
        		new_node=new_node->next;
        		list2_head=list2_head->next;
        	}
        }
        new_node->next=list1_head?list1_head:list2_head;
        return Merge_head->next;
    }
public:
	void List_print(ListNode *head_node)
	{
		curr_node=head_node;
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
	ListNode *list1_head;
	ListNode *list2_head;
	ListNode *Merge_head;
};
int main(int argc, char const *argv[])
{
	Solution s1;
	ListNode* head1=s1.List_Create(10);
	ListNode* head2=s1.List_Create2(10);
	ListNode* head3=s1.Merge(head1,head2);
	s1.List_print(head3);
	return 0;
}
