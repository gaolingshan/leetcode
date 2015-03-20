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

class Solution_old {
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

//2nd pass: 2015-02-05
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution_3pass {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL) return head;
        //1st pass, copy node
        RandomListNode *p = head, *p2;
        while(p!=NULL)
        {
            RandomListNode* tmp=p->next;
            RandomListNode *pp = new RandomListNode(p->label);
            p->next=pp;
            pp->next=tmp;
            p=tmp;
        }
        
        //2nd pass, create random link
        p=head;
        while(p!=NULL)
        {
            if(p->random != NULL)
                p->next->random = p->random->next;
            p=p->next->next;
        }
        
        //3rd pass, break link between copied node and original nodes
        p=head; p2=head->next;
        RandomListNode *res = p2;
        while(p!=NULL)
        {
            p->next=p2->next;
            p=p2->next;
            if(p!=NULL) 
            {
                p2->next=p->next;
                p2=p->next;
            }
        }
        return res;
    }
};

//3rd pass: 2015-02-26
/*
use hashtable<old,new>
1st pass: 
1.create new, insert into table
2.connect next pointer between new nodes

2nd pass: connect rd pointer between new nodes
*/
class Solution {
public:
	unordered_map<RandomListNode*, RandomListNode*> table;
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL) return NULL;
		RandomListNode* p = head, *prev = NULL;
		while (p){
			RandomListNode* newNode = new RandomListNode(p->label);
			if (prev) prev->next = newNode;
			prev = newNode;
			table[p] = newNode;
			p = p->next;
		}
		p = head;
		while (p){
			table[p]->random = table[p->random];
			p = p->next;
		}
		return table[head];
	}
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}