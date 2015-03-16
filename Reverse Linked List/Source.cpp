// Reverse Linked List
//   Author: flashhack
//   Update: 2015-03-13
#include <iostream>
#include <functional>
#include <bitset>
#include <chrono>
#include <exception>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
/*
prev: head of reversed list
every step: new node point to prev, prev move back
*/
class Solution {
public:
    ListNode *reverse(ListNode *head) {
        ListNode *prev=NULL, *p=head;
        while(p){
            auto p_next=p->next;
            p->next=prev;
            prev=p;
            p=p_next;
        }
        return prev;
    }
};

/*
boundary: NULL or single node
n1->n2...
n1 ....->n2
n2->next=n1;
*/
class Solution_recur {
public:
    ListNode *reverse(ListNode *head) {
		if(head==NULL || head->next==NULL) return head;
		auto next=head->next;
		head->next=NULL;
		auto res=reverse(next);
		next->next=head;
		return res;
    }
};


int main()
{


	system("pause");
	return 0;
}