#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution_old {
public:
    ListNode *swapPairs(ListNode *head) {
		ListNode * newHead = new ListNode(0);
		ListNode * now = head;
		ListNode * prev = newHead;

		while(now != NULL)
		{
			ListNode * a = now;
			ListNode * b = now->next;

			if(b != NULL)
			{
				prev->next = b;
				now = b->next;
				a->next = b->next;
				b->next = a;
				prev = a;
			}
			else
			{
				prev->next = a;
				now = b;
			}
				

		}

		return newHead->next;
    }
};


//2nd pass: 2015-02-06
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL) return head;
        ListNode* newHead=new ListNode(0);
        newHead->next=head;
        
        ListNode* p=head, *prev=newHead, *q=p->next;
        while(p)
        {
            if(q!=NULL)
            {
                ListNode* q_next=q->next;
                prev->next=q;
                q->next=p;
                p->next=q_next;

                prev=p;
                p=q_next;
                if(p!=NULL)q=p->next;
            }
			else
				p=NULL;
        }
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

	ListNode a(10);
	ListNode b(20);
	ListNode c(3);
	ListNode d(4);
	ListNode e(15);
	ListNode f(16);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;

	print(s->swapPairs(&a));
	
	system("pause");
	return 0;
}