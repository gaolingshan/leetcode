// Balanced Binary Tree
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

class Solution_1st {
public:
	int dfs(TreeNode *root)
	{
		if(root==NULL) return 0;
		return max(dfs(root->left),dfs(root->right))+1;
	}

    bool isBalanced(TreeNode *root) {
		if(root==NULL) return true;
		return isBalanced(root->left) && isBalanced(root->right) && (abs(dfs(root->left) - dfs(root->right)) <= 1);
    }
};

//2nd pass: 2015-02-18
class Solution {
public:
    pair<bool,int> dfs(TreeNode *root)
    {
        if(root==NULL) return make_pair(true,0);
        auto resLeft=dfs(root->left);
        auto resRight=dfs(root->right);
        int depth=max(resLeft.second,resRight.second)+1;
        if(resLeft.first && resRight.first && abs(resLeft.second-resRight.second)<=1) return make_pair(true,depth); else return make_pair(false,depth);
    }
    bool isBalanced(TreeNode *root) {
        auto res=dfs(root);
        return res.first;
    }
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}