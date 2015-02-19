// Rotate List
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
    ListNode *rotateRight(ListNode *head, int k) {
        int total=0;
		ListNode *p=head;
		while(p!=NULL)
		{
			total++;
			p=p->next;
		}
		//tricky case here. empty list
		if(total==0)return head;
		k=k%total;
		if(k==0) return head;

		int cnt=0;
		ListNode *newHead;
		p=head;
		while(p!=NULL)
		{
			cnt++;
			if(cnt==total-k)
			{
				if(p->next !=NULL) newHead=p->next;
				p->next=NULL;
				break;
			}
			p=p->next;
		}	
		p=newHead;
		while(p!=NULL)
		{
			if(p->next == NULL)
			{
				p->next=head;
				break;
			}
			p=p->next;
		}
		return newHead;
    }
};

//2nd pass: 2015-02-06

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head==NULL) return head;
        int len=0;
        ListNode*p=head;
        while(p)
        {
            len++;
            p=p->next;
        }
        
        k=k%len;
        if(k==0) return head;
        int cnt=1;
        p=head;
        while(cnt!=len-k)
        {
            cnt++;
            p=p->next;
        }
        ListNode*p_next=p->next;
        p->next=NULL;
        p=p_next;
        ListNode*res=p;
        while(p->next)
        {
            p=p->next;
        }
        p->next=head;
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
	a.next=&b;
	b.next=&c;
	c.next=&d;
	d.next=&e;

	print(s->rotateRight(&a,6));
	//print(s->rotateRight(NULL,0));

	system("pause");
	return 0;
}