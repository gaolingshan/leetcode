// Sort List
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

class Solution {
public:
	ListNode* Merge(ListNode* p1, ListNode* p2)
	{
		ListNode *newHead = new ListNode(0);
		ListNode *now=newHead;
		while(1)
		{
			if(p1==NULL && p2==NULL)
			{
				ListNode* res = newHead->next;
				delete(newHead);
				return res;			
			}
			else
			{
				//trick here, cannot create a new pointer to ref p1&p2, must operate p1,p2 directly. otherwise p1,p2 will not change
				//ListNode *p;
				if(p1==NULL || (p2!=NULL && p2->val<=p1->val) )
				{
					ListNode* tmp=p2->next;
					p2->next=NULL;
					now->next=p2;
					now=p2;
					p2=tmp;				
				}
				else
				if(p2==NULL || (p1!=NULL && p1->val<p2->val)) 
				{
					ListNode* tmp=p1->next;
					p1->next=NULL;
					now->next=p1;
					now=p1;
					p1=tmp;				
				}

			}			
		}
	}

	ListNode* MergeSort(ListNode* head, int total)
	{
		if(total==0) return NULL;
		if(total==1) return head;	//trick here, have to deal with 1 case. only 0 is insufficent
		ListNode* p=head;
		int cnt=1;
		while(cnt<total/2)
		{
			cnt++;
			p=p->next;
		}
		ListNode* head2=p->next;
		p->next=NULL;
		ListNode* p1=MergeSort(head,cnt);
		ListNode* p2=MergeSort(head2,total-cnt);
		ListNode* p3=Merge(p1,p2);
		return p3;
	}

    ListNode *sortList(ListNode *head) {
        ListNode *p=head;
		int cnt=0;
		while(p!=NULL)
		{
			cnt++;
			p=p->next;
		}
		return MergeSort(head,cnt);
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
	//a.next = &b;
	//b.next = &c;
	//c.next = &d;
	//d.next = &e;
	//e.next = &f;

	print(&a);
	print(s->sortList(&a));


	system("pause");
	return 0;
}