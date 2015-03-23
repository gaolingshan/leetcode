// Linked List Cycle II
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

class Solution_1st {
public:
    ListNode *detectCycle(ListNode *head) {
		ListNode* fast=head;
		ListNode* slow=head;
		while(fast!=NULL)
		{
			fast=fast->next;
			if(fast==NULL) break; else fast=fast->next;
			slow=slow->next;
			if(fast==slow) 
			{
				ListNode *p = head;
				while(p!=slow)
				{
					p=p->next;
					slow=slow->next;
				}
				return p;
			}
		}
		return NULL;        
    }
};

//2nd pass: 2015-02-19
class Solution_2nd {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return NULL;
        ListNode* slow=head, *fast=head;
        do
        {
            slow=slow->next;
            fast=(fast->next!=NULL)?fast->next->next:NULL;
            if(fast==NULL) return NULL;
        }while(slow!=fast);
        fast=head;
		while(slow!=fast)
		{
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};

//3rd pass: 2015-03-22
/*
slow/fast pointer
1. fast reach end, return NULL
2. slow==fast, has cycle
put fast at head, if(slow==fast) return slow

prove:
x: head to cycle start
a: cycle start to meeting point
r: cycle length
L: list length

slow: x+a=s
fast: x+nr=2s
s=nr=x+a

fast go back to head
x+pr=r-a+qr
x+a=(q-p+1)r
if p==0, q=n-1, fast&slow must meet at start of cycle
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow=head, fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                fast=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}