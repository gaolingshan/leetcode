// Copy List with Random Pointer
//   Author: flashhack
//   Update: 2015-01-10
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


struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	unordered_map<RandomListNode*,RandomListNode*> table;
    RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode *p=head;
		RandomListNode *now=NULL, *prev=NULL, *newHead=NULL;
		while(p!=NULL)
		{
			now = new RandomListNode(p->label);
			if(newHead==NULL) newHead=now;
			if(prev!=NULL) prev->next=now;
			prev=now;
			table[p]=now;
			p=p->next;
		}
		p=head;
		while(p!=NULL)
		{
			table[p]->random=table[p->random];
			p=p->next;
		}
		return newHead;
    }
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}