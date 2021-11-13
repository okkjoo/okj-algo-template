#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode *reverseList(ListNode *head)
	{
		ListNode *temp; // 保存cur的下一个节点
		ListNode *cur = head;
		ListNode *pre = NULL; //更新后的头
		while (cur)
		{
			temp = cur->next; // 保存一下 cur的下一个节点，因为接下来要改变cur->next
			cur->next = pre;  // 翻转操作
			//更新一下pre 和 cur指针
			pre = cur;	//pre移到现在cur所在
			cur = temp; //cur移到temp即原先的cur->next;
		}
		return pre;
	}
};