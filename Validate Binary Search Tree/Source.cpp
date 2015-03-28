// Validate Binary Search Tree
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


class Solution_old {
public:
    bool isValidBST(TreeNode *root) {
		vector<int> res;        
		vector<TreeNode*> st;
		TreeNode *now=root;
		while(1)
		{
			if(now==NULL && st.empty()) return true;
			if(now==NULL)
			{
				if(!res.empty() && st.back()->val <= res.back()) return false;
				res.push_back(st.back()->val);
				now=st.back()->right;
				st.pop_back();
			}
			else
			{
				st.push_back(now);
				now=now->left;
			}
		}
        return true;
    }
};

//2nd pass:
//3rd pass: 2015-03-27
class Solution {
public:
    bool dfs(TreeNode*root, long long min, long long max)
    {
        if(root==NULL) return true;
        if(root->val <= min || root->val >= max) return false;
        return dfs(root->left,min,root->val) && dfs(root->right,root->val,max);
    }
    bool isValidBST(TreeNode *root) {
        return dfs(root,LLONG_MIN, LLONG_MAX);
    }
};

int main()
{
	Solution *s = new Solution();
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	//a.right=&b;
	//b.left=&c;
	cout<<s->isValidBST(&a)<<endl;

	system("pause");
	return 0;
}