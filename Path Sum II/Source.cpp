// Path Sum II
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

class Solution {
public:
	void dfs(vector<vector<int> > &res, vector<int> &now, TreeNode *root, int target)
	{
		now.push_back(root->val);
		if(root->left == NULL && root->right == NULL)
		{
			int tmp=0;
			for(int it:now)tmp+=it;
			if(tmp==target) res.push_back(now);
			now.pop_back();
			return;
		}
		if(root->left != NULL) dfs(res,now,root->left,target);
		if(root->right != NULL) dfs(res,now,root->right,target);
		now.pop_back();
	}
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
		vector<int> now;
		if(root==NULL) return res;
		dfs(res,now,root,sum);
		return res;
    }
};

int main()
{
	Solution *s = new Solution();

	TreeNode a(2);
	TreeNode b(3);
	TreeNode c(1);
	//a.left=&b;
	//a.right=&c;

	vector<vector<int> > res = s->pathSum(&a,0);

	system("pause");
	return 0;
}