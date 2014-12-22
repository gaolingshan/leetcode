// Remove Duplicates from Sorted List II
//   Author: flashhack
//   Update: 2014-12-21
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *p=head;
		if(p==NULL) return p;
		ListNode *q=p->next;
		ListNode *prev= new ListNode(0);
		ListNode *newHead=prev;
		while(1)
		{
			if(q!=NULL && p->val == q->val)
			{
				while(q!=NULL)
				{
					if(p->val != q->val) break;
					q=q->next;
				}
				if(q==NULL)
				{
					break;
				}
				else
				{
					p=q;
					q=p->next;
				}
			}
			else
			{
				prev->next = p;
				prev=p;
				p->next=NULL;
				p=q;
				if(p==NULL)break;
				q=p->next;
			}
		}
		return newHead->next;
		
    }
};

int main()
{
	Solution *s = new Solution();

	//ListNode a(1);
	//ListNode b(2);
	//ListNode c(3);
	//ListNode d(3);
	//ListNode e(4);
	//ListNode f(4);
	//ListNode g(5);
	//a.next = &b;
	//b.next = &c;
	//c.next = &d;
	//d.next = &e;
	//e.next = &f;
	//f.next = &g;
	//ListNode a(1);
	//ListNode b(1);
	//ListNode c(1);
	//ListNode d(2);
	//ListNode e(3);
	//a.next = &b;
	//b.next = &c;
	//c.next = &d;
	//d.next = &e;

	//ListNode a(1);
	//ListNode b(1);
	//a.next = &b;

	ListNode a(1);
	ListNode b(2);
	ListNode c(2);
	a.next = &b;
	b.next = &c;

	print(&a);
	print(s->deleteDuplicates(&a));


	system("pause");
	return 0;
}