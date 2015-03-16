// <filename>.<ext>
//   Author: <name>
//   Update: <date>
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
		if(m==n) return head;
		ListNode *newHead = new ListNode(0);
		newHead->next=head;
		ListNode *prev=newHead, *p=head, *post;
		int cnt=1;
		while(cnt!=n)
		{
			post=p->next;
			if(cnt>=m)
			{
				ListNode *tmp=prev->next;
				prev->next=post;
				p->next=post->next;
				post->next=tmp;
			}
			else
			{
				prev=p;
				p=post;
			}
			cnt++;
		}		
		return newHead->next;
    }
};

/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution_2nd {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    pair<ListNode*,ListNode*> reverse(ListNode *head)
    {
        ListNode* prev=NULL, *tail=head;
        ListNode* p=head;
        while(p)
        {
            ListNode* p_next = p->next;
            p->next = prev;
            prev=p;
            p=p_next;
        }
        return make_pair(prev,tail);
    }
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        ListNode *prev, *post, *p=head;
        ListNode *start, *end;
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        prev=newHead;
        int cnt=1;
        while(p)
        {
            if(cnt==m)
            {
                start=p;
                break;
            }
            prev=p;
            p=p->next;
            cnt++;
        }
        while(p)
        {
            if(cnt==n)
            {
                end=p;
                post=p->next;
                break;
            }
            p=p->next;
            cnt++;
        }
        end->next=NULL;
        
        auto it = reverse(start);
        prev->next = it.first;
        it.second->next = post;
        ListNode* res = newHead->next;
        delete(newHead);
        return res;
    }
};

//3rd pass: 2015-03-13
/*
dummy head node needed
1.prev->[slow...fast]->next
2.fast next break
3.reverse [slow...fast]
4.prev->fast  slow->next
1 2 3 4 5, m=2, n=4
p s   f
*/
class Solution {
public:
    void reverse(ListNode* head){
        ListNode *prev=NULL, *p=head;
        while(p){
            auto p_next=p->next;
            p->next=prev;
            prev=p;
            p=p_next;
        }
    }
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *newHead=new ListNode(0); newHead->next=head;
        ListNode *prev=newHead,*slow=head,*fast=head,*next=NULL;
        while(n>1){
            if(m>1){
                prev=slow;
                slow=slow->next;
                --m;
            }
            fast=fast->next;
            --n;
        }
        next=fast->next;
        fast->next=NULL;
        reverse(slow);
        prev->next=fast; slow->next=next;
        auto ans=newHead->next;
        delete(newHead);
        return ans;
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
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;

	print(&a);
	print(s->reverseBetween(&a,1,6));


	system("pause");
	return 0;
}