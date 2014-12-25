// Minimum Depth of Binary Tree
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
    int minDepth(TreeNode *root) {
        if(root==NULL) return 0;
		int ld = minDepth(root->left);
		int rd = minDepth(root->right);
		if(ld==0) return rd+1;
		if(rd==0) return ld+1;
		return min(ld,rd)+1;
    }
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}