// Binary Tree Maximum Path Sum
//   Author: flashhack
//   Update: 2014-01-07
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
	int res;
	int dfs(TreeNode *root)
	{
		if(root==NULL) return 0;
		//trick here, must memorize
		int tmp1=dfs(root->left);
		int tmp2=dfs(root->right);
		res=max(res,root->val + tmp1 + tmp2);
		//trick here, must compare with 0
		return max(0,root->val + max(0,max(tmp1,tmp2)));
	}
    int maxPathSum(TreeNode *root) {
		res = INT_MIN;
		dfs(root);
		return res;
    }
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}