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


class Solution_old {
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

//2nd pass: 2015-02-04
class Solution_2nd {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==NULL || k<=1) return head;
        ListNode newHead(0);
        newHead.next = head;
        ListNode *st_prev=&newHead, *st=head, *st_next, *ed, *ed_next;
        int cnt=0;
        while(st!=NULL)
        {
            ed=st;
			cnt=1;
            while(ed!=NULL)
            {
                ed=ed->next;
                if(ed!=NULL) cnt++;
                if(cnt==k) break;
            }
            if(cnt!=k) break;
            ed_next=ed->next;
            
            while(st->next != ed_next)  //keep reversing until reach end
            {
                st_next=st->next;
                if(st_next != NULL)
                {
                    st->next = st_next->next;
                    st_next->next=NULL;
                    
                    ListNode* tmp = st_prev->next;
                    st_prev->next=st_next;
                    st_next->next=tmp;
                }
            }
            
            //reversing k group done, reload and do next counting
            st_prev = st;
            st=ed_next;
        }
        return newHead.next;
    }
};

//3rd pass: 2015-02-06
class Solution_3rd {
public:
    pair<ListNode*, ListNode*> reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode *p=head;
        while(p)
        {
            ListNode* p_next = p->next;
            p->next=prev;
            prev=p;
            p=p_next;
        }
        return make_pair(prev,head);
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
		if(head==NULL || k<=1) return head;
        ListNode* newHead= new ListNode(0);
        newHead->next=head;
        
        ListNode *p=head, *prev=newHead, *post;
        int cnt=1;
        while(p)
        {
            if(cnt%k==0)
            {
                post=p->next;
                p->next=NULL;
                auto it=reverse(prev->next);
                prev->next=it.first;
                it.second->next=post;
                prev=it.second;
                p=post;
                cnt=1;
                continue;
            }
            cnt++;
            p=p->next;
        }
        ListNode*res = newHead->next;
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

//4th pass: 2015-03-13
/*
need dummy head
prev-> [q... p] ->next
         k cnt
            keep p->next non NULL
every step: 1. move p, add cnt till cnt % k == 0
            2. mark q, next, break p_next
            3. reverse q..p
            4. prev->[p,q]->next
            5. prev=q,p=q
  1 2 3 4 5
  q p
*/
class Solution {
public:
    void reverse(ListNode *head){
        ListNode *prev=NULL, *p=head;
        while(p){
            auto p_next=p->next;
            p->next=prev;
            prev=p;
            p=p_next;
        }
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *newHead=new ListNode(0); newHead->next=head;
        ListNode *prev=newHead, *p=newHead, *q=head, *next=NULL;
        int cnt=0;
        while(p->next){
            p=p->next; 
            if(++cnt % k == 0){
                q=prev->next;
                next=p->next;
                p->next=NULL;
                reverse(q);
                prev->next=p;
                q->next=next;
                prev=q; p=q;
            }
        }
        auto res=newHead->next;
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
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;

	print(s->reverseKGroup(&a, 3));
	
	system("pause");
	return 0;
}