// Insertion Sort List
//   Author: flashhack
//   Update: 2015-01-12
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

class Solution_old {
public:
    ListNode *insertionSortList(ListNode *head) {
		ListNode *newHead=new ListNode(0);
		newHead->next=head;
		ListNode *prev, *now, *p=head, *p_prev=newHead;
		bool flag;
		while(p!=NULL)
		{
			prev=newHead;
			now=prev->next;
			flag=false;
			while(now!=p)
			{
				if(now->val <= p->val)
				{
					prev=now;
					now=now->next;
				}
				else
				{
					ListNode* tmp=p->next;
					prev->next=p;
					p->next=now;
					p_prev->next=tmp;
					p=tmp;
					flag=true;
					break;
				}
			}
			if(!flag)
			{
				p_prev=p;
				p=p->next;			
			}
		}
		return newHead->next;
    }
};

//2nd pass: 2015-02-06
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head==NULL) return head;
        ListNode* newHead=new ListNode(0);
        newHead->next=head;
        ListNode *p=head, *p_prev=newHead;
        while(p)
        {
            ListNode *q=newHead->next;
            ListNode *q_prev=newHead;
            bool inserted=false;
            while(q!=p)
            {
                if(p->val<q->val)
                {
                    ListNode* p_next=p->next;
                    q_prev->next=p;
                    p->next=q;
                    p_prev->next=p_next;
                    p=p_next;
                    inserted=true;
                    break;
                }
                q_prev=q;
                q=q->next;
            }
            if(!inserted)
            {
                p_prev=p;
                p=p->next;
            }
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
	ListNode b(10);
	ListNode c(3);
	ListNode d(4);
	ListNode e(15);
	ListNode f(16);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;

	print(&a);
	print(s->insertionSortList(&a));

	system("pause");
	return 0;
}