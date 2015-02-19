// Binary Tree Preorder Traversal
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

class Solution_old {
public:
    vector<int> preorderTraversal(TreeNode *root) {
		vector<int> res;        
		vector<TreeNode*> st;
		TreeNode *now=root;
		while(1)
		{
			if(now==NULL && st.empty())break;
			if(now==NULL)
			{
				now=st.back()->right;
				st.pop_back();
			}
			else
			{
				st.push_back(now);
				res.push_back(now->val);
				now=now->left;
			}
		}
		return res;
    }
};

//2nd pass: 2015-02-08
/*
	1
   / \
  2   3
	   \
	    4

pre: 1 2 3  print right now
post: 
stack: 1 2
if stack top has right && now != right -> now=right; else print stack top, pop

*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
		vector<int> res;
		stack<TreeNode*> st;
		TreeNode* now=root;
		while(1)
		{
			if(now==NULL && st.empty()) break;
			if(now==NULL)
			{
				now=st.top()->right;
				st.pop();
			}
			else
			{
				res.push_back(now->val);
				st.push(now);
				now=now->left;
			}
		}
		return res;
	}
};


int main()
{
	Solution *s = new Solution();
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	a.right=&b;
	b.left=&c;
	vector<int> res = s->preorderTraversal(&a);
	for(auto it:res) cout<<it<<" ";
	cout<<endl;


	system("pause");
	return 0;
}