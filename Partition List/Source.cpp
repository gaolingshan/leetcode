// Partition List
//   Author: flashhack
//   Update: 2014-12-22
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

void print(ListNode *l)
{
	while(l!=NULL)
	{
		cout<<l->val<<endl;
		l=l->next;
	}
	cout<<endl;
}

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
		ListNode *l1 = new ListNode(0),*p1=l1;
		ListNode *l2 = new ListNode(0),*p2=l2;


		ListNode *p=head;
		if(p==NULL) return NULL;
		while(p!=NULL)
		{
			if(p->val<x)
			{
				p1->next=p;
				p1=p;
				p=p->next;
				p1->next=NULL;
			}
			else
			{
				p2->next=p;
				p2=p;
				p=p->next;
				p2->next=NULL;
			}
		}
		ListNode *newHead;
		if(l1->next != NULL) 
		{
			newHead=l1->next;
			p1->next = l2->next;
		}
		else
			newHead=l2->next;
		return newHead;
    }
};

int main()
{
	Solution *s = new Solution();
	ListNode a(1);
	ListNode b(4);
	ListNode c(3);
	ListNode d(2);
	ListNode e(5);
	ListNode f(2);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	print(&a);
	print(s->partition(&a,6));


	system("pause");
	return 0;
}