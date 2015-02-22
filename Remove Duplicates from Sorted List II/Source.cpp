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

class Solution_old {
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

//2nd pass 2015-02-04
class Solution_2nd {
public:
    void deleteNodes(ListNode *p)
    {
        while(p!=NULL)
        {
            ListNode* tmp=p->next;
            delete p;
            p=tmp;
        }
    }
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL) return NULL;
        ListNode newHead(0);
        newHead.next=head;
        ListNode* start=head, *start_prev=&newHead, *now=head->next, *prev=head;
        while(1)    //problem here. what if start->end are duplicates?
        {
            if(now==NULL || now->val != start->val) //modify here. now is the end of list case
            {
                if(start!=prev) //need remove nodes
                {
                    start_prev->next = now;
                    prev->next=NULL;
                    //deleteNodes(start);
                    prev=start_prev;
                }
                if(now==NULL) break;
                start=now;
                start_prev=prev;
                prev=now;
                now=now->next;
            }
            else
            {
                prev=now;
                now=now->next;
            }
        }
        return newHead.next;
    }
};

//3rd pass: 2015-02-06
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution_3rd {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL) return head;
        ListNode *newHead = new ListNode(INT_MIN);
        newHead->next=head;
        
        ListNode *p=head, *prev=newHead;
        bool find=false;
        while(p)
        {
            if(p->next!=NULL && p->val==p->next->val)
            {
                find=true;
                p=p->next;
                continue;
            }
            if(find)
            {
                prev->next=p->next;
                p=p->next;
                find=false;
            }
            else
            {
                prev=p;
                p=p->next;
            }
        }
		ListNode* res=newHead->next;
		delete(newHead);
		return res;
    }
};

//4th pass: 2015-02-19
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *newHead=new ListNode(0), *prev=newHead, *p=head;
        newHead->next=head;
        while(p&&p->next)
        {
            if(p->val != p->next->val)
            {
                prev=p;
                p=p->next;
            }else
            {
                while(p->next && p->val==p->next->val) p=p->next;
                prev->next=p->next;
                p=p->next;
            }
        }
        ListNode*res=newHead->next;
        delete(newHead);
        return res;
    }
};

int main()
{
	Solution *s = new Solution();

	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(3);
	ListNode e(4);
	ListNode f(4);
	ListNode g(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;

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

	//ListNode a(1);
	//ListNode b(2);
	//ListNode c(2);
	//a.next = &b;
	//b.next = &c;

	print(&a);
	print(s->deleteDuplicates(&a));


	system("pause");
	return 0;
}