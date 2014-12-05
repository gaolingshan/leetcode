#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
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
    ListNode *reverseKGroup(ListNode *head, int k) {
		ListNode * newHead = new ListNode(0);
		ListNode * now = head;
		ListNode * prev = newHead;
		ListNode * k_next;
		
		while(now != NULL)
		{
			int cnt = 0;
			stack<ListNode*> ListNodeStack;	
			ListNode * a = now;
			while(cnt < k)
			{
				if(a == NULL) break;
				ListNodeStack.push(a);
				a = a->next;
				cnt++;
			}
			if(cnt!=k)
			{
				prev->next = now;
				break;
			}
			k_next = ListNodeStack.top()->next;
			while(!ListNodeStack.empty())
			{
				prev->next = ListNodeStack.top();
				prev = ListNodeStack.top();
				ListNodeStack.pop();
			}
			prev->next = k_next;
			now = k_next;
		}
		return newHead->next;
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

	print(s->reverseKGroup(&a, 1));
	
	system("pause");
	return 0;
}