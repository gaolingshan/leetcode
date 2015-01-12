// Linked List Cycle
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

class Solution {
public:
    bool hasCycle(ListNode *head) {
		ListNode* fast=head;
		ListNode* slow=head;
		while(fast!=NULL)
		{
			fast=fast->next;
			if(fast==NULL) break; else fast=fast->next;
			slow=slow->next;
			if(fast==slow) return true;
		}
		return false;
    }
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}