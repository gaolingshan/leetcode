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

class Solution_old {
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

//2nd pass: 2015-02-07
class Solution_2nd {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode*newHead=new ListNode(0), *p=newHead;
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val < l2->val)
            {
                ListNode* next=l1->next;
                p->next=l1;
                p=l1;
                p->next=NULL;
                l1=next;
            }
            else
            {
                ListNode* next=l2->next;
                p->next=l2;
                p=l2;
                p->next=NULL;
                l2=next;
            }
        }
        while(l1!=NULL)
        {
            ListNode* next=l1->next;
            p->next=l1;
            p=l1;
            p->next=NULL;
            l1=next;
        }
        while(l2!=NULL)
        {
             ListNode* next=l2->next;
             p->next=l2;
            p=l2;
            p->next=NULL;
            l2=next;
        }
        ListNode*res=newHead->next;
        delete(newHead);
        return res;
    }
};

//3rd pass: 2015-02-19
class Solution_recur {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val < l2->val)
        {
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};

class Solution_3rd {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode* newHead=new ListNode(0), *p=newHead;
        while(l1 && l2)
        {
            if(l1->val<l2->val)
            {
                p->next=l1;
                p=l1;
                l1=l1->next;
                p->next=NULL;
            }
            else
            {
                p->next=l2;
                p=l2;
                l2=l2->next;
                p->next=NULL;
            }
        }
        if(l1) p->next=l1; else p->next=l2;
        ListNode *res=newHead->next;
        delete(newHead);
        return res;
    }
};

//4rd pass: 2015-03-13
/*
prev : end of merged list
head : start of merged list
every step: prev proceed to end of list(no need to put NULL)

until one list NULL, concat prev-> non empty list
*/
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL || l2==NULL) return (l1)?l1:l2;
        ListNode* prev=NULL, *head=NULL;
        while(l1 && l2){
            if(head==NULL) head=(l1->val < l2->val)?l1:l2;
            if(l1->val < l2->val){
                if(prev) prev->next=l1;
				prev=l1;
                l1=l1->next;
            }else{
                if(prev) prev->next=l2;
				prev=l2;
                l2=l2->next;
            }
        }
        prev->next=(l1)?l1:l2;
        return head;
    }
};
class Solution_Recur {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL || l2==NULL) return (l1)?l1:l2;
        if(l1->val < l2->val){
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }else{
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};

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