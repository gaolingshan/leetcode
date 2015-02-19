// Reorder List
//   Author: flashhack
//   Update: 2015-01-11
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

    void reorderList(ListNode *head) {
        int total=0;
		ListNode *p=head;
		while(p!=NULL)
		{
			total++;
			p=p->next;
		}
		if(total==0||total==1) return;
		ListNode *newHead = new ListNode(0);
		p=head;
		int cnt=1;
		while(cnt<total/2)
		{
			cnt++;
			p=p->next;
		}
		newHead->next=p->next;
		p->next=NULL;
		p=newHead->next;
		while(p->next!=NULL)
		{
			ListNode* tmp=newHead->next;
			newHead->next=p->next;
			ListNode* tmp2=p->next->next;
			p->next->next=tmp;
			p->next=tmp2;
		}
		p=head;
		ListNode* p2=newHead->next;
		while(p!=NULL)
		{
			ListNode* tmp= p->next;
			ListNode* tmp2= p2->next;

			p->next=p2;
			if(tmp!=NULL)p2->next=tmp;

			p=tmp;
			p2=tmp2;
		}
    }
};

class Solution_2nd {
public:
    ListNode* reverseList(ListNode *head)
    {
        ListNode *q = NULL, *p_next;
        ListNode *p=head;
        while(p!=NULL)
        {
            p_next=p->next;
            p->next=q;
            q=p;
            p=p_next;
        }
        return q;
    }
    void reorderList(ListNode *head) {
        if(head==NULL) return;
        //break the list into two, and make list1 longer
        ListNode* head1, *head2;
        int count=0;
        ListNode* p=head;
        while(p!=NULL)
        {
            count++;
            p=p->next;
        }
        if(count%2) count++;    //make list1 longer;
        count/=2;
        int cnt=1;
        p=head;
        while(p!=NULL)
        {
            if(cnt==count)
            {
                head2=p->next;
                p->next=NULL;
                break;
            }
            cnt++;
            p=p->next;
        }
        //reverse list2
        head2=reverseList(head2);
        //merge list1&list2
        p=head;
        while(head2!=NULL)
        {
            ListNode* tmp1=p->next;
            ListNode* tmp2=head2->next;
            p->next=head2;
            head2->next=tmp1;
            p=tmp1;
            head2=tmp2;
        }
    }
};

//3rd pass: 2015-02-19
class Solution {
public:
    void reorderList(ListNode *head) {
        if(head==NULL) return;
        //split the list in two. 1st longer
        ListNode *slow=head, *fast=head, *prev=NULL;
        while(fast)
        {
			prev=slow;
            slow=slow->next;
            fast=(fast->next)?fast->next->next:NULL;
        }
		prev->next=NULL;
        ListNode *head2=slow;
        //reverse second list
        ListNode *p=head2;
		prev=NULL;
        while(p)
        {
            ListNode* p_next=p->next;
            p->next=prev;
            prev=p;
            p=p_next;
        }
        head2=prev;
        //merge two lists
        p=head;
        ListNode* q=head2;
        while(q)    //since p is longer and always not NULL
        {
            ListNode* p_next=p->next, *q_next=q->next;
            p->next=q;
            q->next=p_next;
            p=p_next;
            q=q_next;
        }
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
	ListNode g(7);
	//a.next=&b;
	//b.next=&c;
	//c.next=&d;
	//d.next=&e;
	//e.next=&f;
	//f.next=&g;
	s->reorderList(&a);
	print(&a);


	system("pause");
	return 0;
}