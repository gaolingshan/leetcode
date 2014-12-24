// <filename>.<ext>
//   Author: <name>
//   Update: <date>
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
		if(m==n) return head;
		ListNode *newHead = new ListNode(0);
		newHead->next=head;
		ListNode *prev=newHead, *p=head, *post;
		int cnt=1;
		while(cnt!=n)
		{
			post=p->next;
			if(cnt>=m)
			{
				ListNode *tmp=prev->next;
				prev->next=post;
				p->next=post->next;
				post->next=tmp;
			}
			else
			{
				prev=p;
				p=post;
			}
			cnt++;
		}		
		return newHead->next;
    }
};


int main()
{
	Solution *s = new Solution();

	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	ListNode f(6);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;

	print(&a);
	print(s->reverseBetween(&a,1,6));


	system("pause");
	return 0;
}