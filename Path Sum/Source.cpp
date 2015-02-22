// Path Sum
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
	bool dfs(TreeNode *root, int now, int target)
	{
		now += root->val;
		if(root->left == NULL && root->right == NULL)
		{
			if(now==target) return true; else return false;
		}
		bool res=false;
		if(root->left!=NULL) res |= dfs(root->left,now,target);
		if(root->right!=NULL) res |= dfs(root->right,now,target);
		return res;
	}
    bool hasPathSum(TreeNode *root, int sum) {
		if(root==NULL) return false;
        return dfs(root,0,sum);
    }
};

//2nd pass: 2015-02-20
class Solution_2nd {
public:
	bool dfs(TreeNode*root, int now, int target)
	{
		now+=root->val;
		if(root->left==NULL && root->right==NULL) return (now==target);
		bool res=false;
		if(root->left) res |= dfs(root->left,now,target);
		if(root->right) res |= dfs(root->right,now,target);
		return res;
	}
	bool hasPathSum(TreeNode *root, int sum) {
		if(root==NULL) return false;
		return dfs(root,0,sum);
	}
};

//3rd pass: 2015-02-20
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL) return (root->val == sum);
        return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);
    }
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}