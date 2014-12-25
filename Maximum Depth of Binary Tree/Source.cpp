// Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode *root) {
        if(root==NULL) return 0;
		return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

int main()
{
	Solution *s = new Solution();


	system("pause");
	return 0;
}