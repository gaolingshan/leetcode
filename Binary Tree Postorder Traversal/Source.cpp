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

class Solution {
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

int main()
{
	Solution *s = new Solution();
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	a.right=&b;
	b.left=&c;
	vector<int> res = s->postorderTraversal(&a);
	for(auto it:res) cout<<it<<" ";
	cout<<endl;

	system("pause");
	return 0;
}