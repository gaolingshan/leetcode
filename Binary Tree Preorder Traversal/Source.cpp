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

class Solution {
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