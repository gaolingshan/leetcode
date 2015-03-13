// Intersection of Two Linked Lists
//   Author: flashhack
//   Update: 2015-01-13
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


class Solution_1st {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *p1=headA, *p2=headB;
		bool hasShiftA=false, hasShiftB=false;
		ListNode *intersect=NULL;
		while(1)
		{
			if(p1==NULL && p2==NULL && hasShiftA && hasShiftB)
			{
				return NULL;
			}
			if(hasShiftA && hasShiftB)
			{
				if(p1->val == p2->val) return p1;
			}
			if(p1==NULL) 
			{
				p1=headB;
				hasShiftA=true;
			}
			else
				p1=p1->next;
			if(p2==NULL)
			{
				p2=headA;
				hasShiftB=true;
			}
			else
				p2=p2->next;

		}
    }
};

//2nd pass: 2015-02-18
class Solution_2nd {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=0,lenB=0;
        ListNode *p=headA, *q=headB,*prevA=NULL,*prevB=NULL;
        while(p)
        {
            lenA++; prevA=p; p=p->next;
        }
        while(q)
        {
            lenB++; prevB=q; q=q->next;
        }
        if(prevA!=prevB) return NULL;
        p=headA; q=headB;
        while(lenA>lenB)
        {
            p=p->next;lenA--;
        }
        while(lenB>lenA)
        {
            q=q->next; lenB--;
        }
        while(p)
        {
            if(p==q) return p;
            p=p->next; q=q->next;
        }
    }
};

//3rd pass: 2015-03-12
/*
1. get lenA && lenB
2. swap(A,B), A be the longer one
3. A move forward lenA-lenB step
4. AB move together until same
5. not same in the end, NULL
*/
class Solution {
public:
    int getLen(ListNode* head){
        int cnt=0;
        auto p=head;
        while(p){ cnt++; p=p->next; }
		return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=getLen(headA), lenB=getLen(headB);
        if(lenA<lenB){
            swap(headA,headB);
            swap(lenA,lenB);
        }
        auto p=headA,q=headB;
        for(int i=0;i<lenA-lenB;i++) p=p->next;
        while(p){
            if(p==q) return p;
            p=p->next;
            q=q->next;
        }
        return NULL;
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
	print(s->getIntersectionNode(&a,&b));
	

	system("pause");
	return 0;
}