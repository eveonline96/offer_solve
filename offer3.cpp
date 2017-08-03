#include <iostream>
#include <vector>
using namespace std;
/*输入一个链表，从尾到头打印链表每个节点的值。
1.循环算法:
prev是NULL，head指向当前的头节点A，next指向A节点的下一个节点B。
首先从A节点开始逆序，将A节点的next指针指向prev，
因为prev的当前值是NULL，所以A节点就从链表中脱离出来了，然后移动head和next指针，
使它们分别指向B节点和B的下一个节点C（因为当前的next已经指向B节点了，
因此修改A节点的next指针不会导致链表丢失）。
2.递归算法：
递归的思想就是，先将当前的表头节点从链表中拆出来，
然后对剩余的节点进行逆序，最后将当前的表头节点连接到新链表的尾部。
关键点是头节点head的下一个节点head->next将是逆序后的新链表的尾节点，
被摘除的头接点head需要被连接到head->next才能完成整个链表的逆序

对于线性数据结构，比较适合用迭代循环方法，
而对于树状数据结构，比如二叉树，递归方法则非常简洁优雅。
*/
typedef struct ListNode 
{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
}ListNode;

class Solution 
{
public:ListNode *List_create(int num)
{
	head_node=(ListNode*)malloc(1*sizeof(ListNode));
	while(head_node==NULL)
	{
		head_node =(ListNode*)malloc(1*sizeof(ListNode));
	}
	head_node->val=100;
	head_node->next=NULL;
	curr_node=head_node;
	for (int i = 0; i < num; ++i)
	{
		new_node=(ListNode*)malloc(1*sizeof(ListNode));
		while(new_node==NULL)
		{
			new_node=(ListNode*)malloc(1*sizeof(ListNode));
		}
		new_node->val=i;
		new_node->next=NULL;
		curr_node->next=new_node;
		new_node=NULL;
		curr_node=curr_node->next;
	}
	return head_node;

}
public:void List_print(ListNode *head)
{
	while(head)
	{
		cout<<head->val<<endl;
		head=head->next;
	}
}
public: ListNode *reverse(ListNode *head)  //循环
{
	head_node=head;
	curr_node=NULL;
	while(head!=NULL)
	{
		new_node=head->next;
		head->next=curr_node;
		curr_node=head;
		head=new_node;
	}
	return curr_node;
}
public: ListNode *reverse2(ListNode *head)  //递归
{
	if ((head==NULL)||(head->next==NULL))
	{
		return head;
	}
	new_node=reverse2(head->next);
	head->next->next=head;  //连接逆序
	head->next=NULL;     //断开以前的指针
	return new_node;
}

public: vector<int> printListFromTailToHead(ListNode* head)  //向量递归
    {
		vector<int> v1;
		if (head)
		{
			v1.insert(v1.begin(),head->val);//只有一个数的时候
			if (head->next)
			{
				vector<int> temp=printListFromTailToHead(head->next);	
				if(temp.size()>0)
				{
					v1.insert(v1.begin(),temp.begin(),temp.end());
				}
				
			}
		}
		return v1;    
    }
public: vector<int> printListFromTailToHead2(ListNode* head) //向量循环
{
	vector<int> v2;
	if (head)
	{
		v2.insert(v2.begin(),head->val);  //只有一个数的时候
		while (head->next)
		{
			v2.insert(v2.begin(),head->val);
			head=head->next;
		}
	}
	return v2;
}
    private:
	ListNode *head_node;
	ListNode *curr_node;
	ListNode *new_node;
  };
int main(int argc, char const *argv[])
{
	
	Solution s1;
	ListNode* head1=s1.List_create(10);
	s1.List_print(head1);
	cout<<endl;
	// head1=s1.reverse2(head1);
	// s1.List_print(head1);
	s1.printListFromTailToHead2(head1);
	s1.List_print(head1);
	return 0;
}
