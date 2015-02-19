// Convert Sorted List to Binary Search Tree
//   Author: flashhack
//   Update: 2014-12-24
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


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution_2 {
public:
	TreeNode* dfs(vector<int> &num, int left, int right)
	{
		if(left>right) return NULL;
		int mid = left + ((right-left)>>1);
		TreeNode *root = new TreeNode(num[mid]);
		root->left = dfs(num,left,mid-1);
		root->right = dfs(num,mid+1,right);
		return root;
	}

    TreeNode *sortedArrayToBST(vector<int> &num) {
		return dfs(num,0,num.size()-1);
    }
    TreeNode *sortedListToBST(ListNode *head) {
        vector<int> data;
		while(head!=NULL) 
		{
			data.push_back(head->val);
			head=head->next;
		}
		return sortedArrayToBST(data);
    }
};

class Solution_old {
public:
	TreeNode* dfs(ListNode* &p, int left, int right)
	{
		if(left>right) return NULL;
		int mid = left + ((right-left)>>1);
		TreeNode *left_node = dfs(p,left,mid-1);
		TreeNode *root = new TreeNode(p->val);
		root->left = left_node;
		p=p->next;
		root->right = dfs(p,mid+1,right);
		return root;
	}

    TreeNode *sortedListToBST(ListNode *head) {
		ListNode *p=head;
		int cnt=0;
		while(p!=NULL)
		{
			cnt++;
			p=p->next;
		}
		return dfs(head,0,cnt-1);
    }
};


//2nd pass: 2015-02-07
class Solution {
public:
    TreeNode* dfs(ListNode* &head, int size)
    {
        if(head==NULL || size==0) return NULL;
        TreeNode* left=dfs(head,size/2);
        TreeNode* root=new TreeNode(head->val);
		head=head->next;
        TreeNode* right=dfs(head,size-1-size/2);
        root->left=left;
        root->right=right;
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        int len=0;
        ListNode*p=head;
        while(p)
        {
            len++;
            p=p->next;
        }
        return dfs(head,len);
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
	s->sortedListToBST(&a);

	system("pause");
	return 0;
}