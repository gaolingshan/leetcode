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
	struct cmp{
		bool operator ()(const ListNode * a, const ListNode * b)
		{
			return a->val > b->val;
		}
	};	
    ListNode *mergeKLists(vector<ListNode *> &lists) {
		priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
		ListNode * now= new ListNode(0);
		ListNode * head = now;
		for(int i=0;i<lists.size();i++)
			if(lists[i] != NULL)
				pq.push(lists[i]);
		while(!pq.empty())
		{
			ListNode * node = pq.top();
			now->next = node;
			now = node;
			pq.pop();
			if(node->next != NULL) pq.push(node->next);
		}
		return head->next;
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
class Solution {
public:
    struct cmp
    {
        bool operator ()(const ListNode *a, const ListNode *b)
        {
            return a->val > b->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(auto p:lists) if(p)pq.push(p);
        ListNode*newHead = new ListNode(0),*p=newHead;
        while(!pq.empty())
        {
            p->next=pq.top();
            p=pq.top();
            ListNode* next=pq.top()->next;
            pq.pop();
            if(next)pq.push(next);
            p->next=NULL;
        }
        ListNode* res=newHead->next;
        delete(newHead);
        return res;
    }
};

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
	c.next = &d;
	e.next = &f;

	vector<ListNode *> input;
	//input.push_back(NULL);
	input.push_back(&a);
	input.push_back(&c);
	input.push_back(&e);


	print(s->mergeKLists(input));
	
	system("pause");
	return 0;
}


