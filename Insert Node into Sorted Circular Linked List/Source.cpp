// Insert Node into Sorted Circular Linked List
//   Author: flashhack
//   Update: 2015-02-23
#include <iostream>
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
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void insert(ListNode*root, int x)
{
	if (root == NULL)
	{
		ListNode *newNode = new ListNode(x);
		newNode->next = newNode;
		return;
	}
	ListNode *p = root, *prev = NULL;
	while (p)
	{
		prev = p;
		p = p->next;
		if (prev->val <= x && x <= p->val) break;
		if ((prev->val > p->val) && (x > prev->val || x < p->val)) break;
		if (p == root) break;
	}
	ListNode*newNode = new ListNode(x);
	prev->next = newNode;
	newNode->next = p;
}

int main()
{
	//Solution *s = new Solution();

	system("pause");
	return 0;
}