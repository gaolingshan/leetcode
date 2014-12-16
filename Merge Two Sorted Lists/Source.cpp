// Merge Two Sorted Lists
//   Author: flashhack
//   Update: 2014-12-16
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution_BruteForce {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode newHead(0);
		ListNode *now=&newHead;
		ListNode *p=l1, *q=l2;

		while(p!=NULL || q!=NULL)
		{
			if(p!=NULL)
				if(q!=NULL)
				{
					if(p->val < q->val)
					{
						now->next = p;
						now=p;
						p=p->next;
					}else
					{
						now->next = q;
						now=q;
						q=q->next;
					}
				}
				else
				{
					now->next = p;
					now=p;
					p=p->next;
				}
			else
			{
				if(q!=NULL)
				{
					now->next = q;
					now=q;
					q=q->next;
				}
			}
		}
		return newHead.next;
    }
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode newHead(0);
		ListNode *now=&newHead;
		ListNode *p=l1, *q=l2;

		while(p!=NULL && q!=NULL)
		{
			if(p->val < q->val)
			{
				now->next = p;
				now=p;
				p=p->next;
			}else
			{
				now->next = q;
				now=q;
				q=q->next;
			}
		}
		if(p!=NULL) now->next=p;
		else now->next=q;
		return newHead.next;
    }
};


void print(ListNode *l)
{
	while(l!=NULL)
	{
		cout<<l->val<<endl;
		l=l->next;
	}
	cout<<endl;
}

int main()
{
	Solution *s = new Solution();
	ListNode a(10);
	ListNode b(20);
	ListNode c(30);
	ListNode d(4);
	ListNode e(15);
	ListNode f(16);
	a.next = &b;
	b.next = &c;
	d.next = &e;
	e.next = &f;

	print(s->mergeTwoLists(&a,&d));

	system("pause");
	return 0;
}