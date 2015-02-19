#include <iostream>
#include <vector>
#include <map>
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

	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *lastlast;
		ListNode *last = new ListNode(0);
		ListNode *res = last;
		int plus = 0;

		while(l1 != NULL || l2 != NULL)
		{
			int a=(l1!=NULL)?l1->val:0;
			int b=(l2!=NULL)?l2->val:0;
			last->val = a+b+plus;
			if(last->val > 9) 
			{
				plus = 1;
				last->val -= 10;
			}
			else 
				plus = 0;
			l1 = (l1!=NULL)?l1->next:NULL;
			l2 = (l2!=NULL)?l2->next:NULL;
			ListNode *next = new ListNode(0);
			last->next=next;
			lastlast = last;
			last=next;
		}
		if(plus!=0)last->val=plus; else lastlast->next=NULL;
		return res;
	}
};


//2nd pass

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode*newHead=new ListNode(0),*p=newHead;
        int tmp=0;
        while(l1!=NULL && l2!=NULL)
        {
            int num=l1->val+l2->val+tmp;
            tmp=num/10;
            num%=10;
            p->next=new ListNode(num);
            p=p->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            int num=l1->val+tmp;
            tmp=num/10;
            num%=10;
            p->next=new ListNode(num);
            p=p->next;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            int num=l2->val+tmp;
            tmp=num/10;
            num%=10;
            p->next=new ListNode(num);
            p=p->next;
            l2=l2->next;
        }
        if(tmp!=0)
            p->next=new ListNode(tmp);
        ListNode*res=newHead->next;
        delete(newHead);
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
	ListNode a(2);
	ListNode b(4);
	ListNode c(3);
	ListNode d(5);
	ListNode e(6);
	ListNode f(9);
	a.next = &b;
	b.next = &c;
	d.next = &e;
	e.next = &f;
	print(&a);
	print(&d);


	Solution *s = new Solution();
	print(s->addTwoNumbers(&a,&d));
	system("pause");
	return 0;
}