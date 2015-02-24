// Sum Root to Leaf Numbers
//   Author: flashhack
//   Update: 2015-01-09
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
	void dfs(TreeNode *root, int now)
	{
		now=now*10+root->val;
		if(root->left==NULL && root->right==NULL)
		{
			res+=now;
			return;
		}
		if(root->left != NULL)dfs(root->left,now);
		if(root->right != NULL)dfs(root->right,now);
	}
    int sumNumbers(TreeNode *root) {
		if(root==NULL) return 0;
        dfs(root,0);
		return res;
    }
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}