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

class Solution_old {
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

//2nd pass: 2015-02-20
class Solution_2nd {
public:
    int res;
    int dfs(TreeNode *root)
    {
        if(root==NULL) return 0;
        int left=max(0,dfs(root->left));
        int right=max(0,dfs(root->right));
        res=max(res,root->val+left+right);
        return max(0,root->val+max(left,right));
    }
    int maxPathSum(TreeNode *root) {
        res=INT_MIN;
        return dfs(root);
    }
};

//3rd pass: 2015-03-13
/*
use dfs, meanwhile maintain maxsum out side
dfs get the max path sum from this node(include) to bottom of tree(no need be leaf)
l=max(0,dfs(left))
r=max(0,dfs(right));
ans=max(ans,root->val + l + r)
return root->val + max(l,r);
*/
class Solution {
public:
    int ans={INT_MIN};
    int dfs(TreeNode *root){
        if(root==NULL) return 0;
        int l=max(0,dfs(root->left));
        int r=max(0,dfs(root->right));
        ans=max(ans,root->val+l+r);
        return root->val + max(l,r);
    }
    int maxPathSum(TreeNode *root) {
        dfs(root);
        return ans;
    }
};

int main()
{
	Solution *s = new Solution();
	TreeNode a(0);
	cout<<s->maxPathSum(&a);


	system("pause");
	return 0;
}