// Remove Duplicates from Sorted List
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution_old {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode * p=head,* q=head;
		while(q!=NULL)
		{
			if(q==p)
			{
				q=q->next;
				continue;
			}
			if(q->val == p->val) 
			{
				q=q->next;
			}
			else
			{
				p->next=q;
				p=q;
			}
		}
		if(p!=NULL) p->next=q;	//trick here!
		return head;
    }
};


//2nd pass: 2015-02-06
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *p=head,*prev=NULL;
        while(p)
        {
            if(prev!=NULL && prev->val==p->val)
            {
                prev->next=p->next;
                p=p->next;
                continue;
            }
            prev=p;
            p=p->next;
        }
		return head;
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

	ListNode a(1);
	ListNode b(1);
	ListNode c(2);
	ListNode d(3);
	ListNode e(3);
	ListNode f(6);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	print(&a);
	print(s->deleteDuplicates(&a));

	system("pause");
	return 0;
}