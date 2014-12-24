// Binary Tree Zigzag Level Order Traversal
//   Author: flashhack
//   Update: 2014-12-23
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

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > res;
		vector<int> now;
		if(root==NULL)
		{
			return res;
		}			
		int need_reverse=0;
        vector<TreeNode*>queue;
		int head=0,tail=0,flag=0;
		queue.push_back(root);
		while(head<=tail)
		{
			now.push_back(queue[head]->val);
			if(queue[head]->left != NULL) 
			{
				queue.push_back(queue[head]->left);
				tail++;
			}
			if(queue[head]->right != NULL)
			{
				queue.push_back(queue[head]->right);
				tail++;
			}
			if(head==flag)
			{
				if(need_reverse)reverse(now.begin(),now.end());
				need_reverse^=1;
				res.push_back(now);
				now.clear();
				flag=tail;
			}
			head++;
		}
		return res;
    }
};

int main()
{
	Solution *s = new Solution();

	TreeNode a(3);
	TreeNode b(9);
	TreeNode c(20);
	TreeNode d(15);
	TreeNode e(7);
	a.left = &b;
	a.right=&c;
	c.left=&d;
	c.right=&e;

	vector<vector<int> > res = s->zigzagLevelOrder(&a);
	for(auto it1:res)
	{
		for(auto it2:it1) cout << it2 << " ";
		cout<<endl;
	}

	system("pause");
	return 0;
}