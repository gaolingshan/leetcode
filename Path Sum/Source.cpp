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

class Solution {
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

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}