// Intersection of Two Linked Lists
//   Author: flashhack
//   Update: 2015-01-13
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *p1=headA, *p2=headB;
		bool hasShiftA=false, hasShiftB=false;
		ListNode *intersect=NULL;
		while(1)
		{
			if(p1==NULL && p2==NULL && hasShiftA && hasShiftB)
			{
				return NULL;
			}
			if(hasShiftA && hasShiftB)
			{
				if(p1->val == p2->val) return p1;
			}
			if(p1==NULL) 
			{
				p1=headB;
				hasShiftA=true;
			}
			else
				p1=p1->next;
			if(p2==NULL)
			{
				p2=headA;
				hasShiftB=true;
			}
			else
				p2=p2->next;

		}
    }
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}