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

class Solution {
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