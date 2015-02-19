#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
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

	ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode * p1 = head;
		ListNode * p2 = head;
		int distance=0;
		while(p2 != NULL)
		{
			if(distance > n) 
			{
				p1 = p1->next;
				distance--;
			}
			p2 = p2->next;
			distance++;
		}
		if(distance==n)
		{
			p1=p1->next;
			return p1;
		}
		else
		{
			p1->next = p1->next->next;		
			return head;
		}		
	}
};

//2nd pass: 2015-02-06
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head==NULL) return head;
        if(n==0)return head;
        ListNode*newHead=new ListNode(0);
        newHead->next=head;
        
        ListNode *p=head,*q=head,*prev=newHead;
        int cnt=n;
        while(cnt)
        {
            q=q->next;
            cnt--;
        }
        while(q)
        {
            prev=p;
            p=p->next;
            q=q->next;
        }
        prev->next=p->next;
        ListNode*res=newHead->next;
        delete(newHead);
        return res;
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

	print(s->removeNthFromEnd(&a,6));
	

	system("pause");
	return 0;
}
