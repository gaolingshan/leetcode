// Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode *root) {
		vector<int> res;        
		vector<TreeNode*> st;
		TreeNode *now=root;
		while(1)
		{
			if(now==NULL && st.empty())break;
			if(now==NULL)
			{
				if(st.back()->right==NULL)//top of stack is leaf node
				{
					res.push_back(st.back()->val);
					now=st.back();
					st.pop_back();
					if(!st.empty())
					{
						//already the right node, need print root and go back one more step
						//trick: this is a recursive pop process
						while(now == st.back()->right)
						{
							res.push_back(st.back()->val);
							now=st.back();
							st.pop_back();
							if(st.empty())break;
						}
						if(st.empty())break;
						now=st.back()->right;
					}
					else
						break;
				}
				else
				{
					now=st.back()->right;
				}
			}
			else
			{
				st.push_back(now);
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

post: 
stack: 1   3 4
now:   1 2 3 4
res:     2 4 3 1
if stack top has right && now != right -> now=right; else print stack top, pop

*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
		vector<int> res;
		stack<TreeNode*> st;
		TreeNode* now=root;
		while(1)
		{
			if(now==NULL && st.empty()) break;
			if(now!=NULL)
			{
				st.push(now);
				now=now->left;
			}
			else
			{
				while(!st.empty() && (st.top()->right == NULL || st.top()->right == now))
				{
					res.push_back(st.top()->val);
					now=st.top();
					st.pop();
				}
				if(st.empty()) break;
				now=st.top()->right;
			}
		}
		return res;
	}
};

int main()
{
	//Solution *s = new Solution();
	Solution_old *s = new Solution_old();
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	TreeNode d(4);
	a.left=&b;
	a.right=&c;
	c.right=&d;
	vector<int> res = s->postorderTraversal(&a);
	for(auto it:res) cout<<it<<" ";
	cout<<endl;

	system("pause");
	return 0;
}