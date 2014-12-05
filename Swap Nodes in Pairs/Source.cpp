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


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
		ListNode * newHead = new ListNode(0);
		ListNode * now = head;
		ListNode * prev = newHead;

		while(now != NULL)
		{
			ListNode * a = now;
			ListNode * b = now->next;

			if(b != NULL)
			{
				prev->next = b;
				now = b->next;
				a->next = b->next;
				b->next = a;
				prev = a;
			}
			else
			{
				prev->next = a;
				now = b;
			}
				

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
	//a.next = &b;
	//b.next = &c;
	//c.next = &d;
	//d.next = &e;
	//e.next = &f;

	print(s->swapPairs(NULL));
	
	system("pause");
	return 0;
}