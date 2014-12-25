// Convert Sorted Array to Binary Search Tree
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
	TreeNode* dfs(vector<int> &num, int left, int right)
	{
		if(left>right) return NULL;
		int mid = left + ((right-left)>>1);
		TreeNode *root = new TreeNode(num[mid]);
		root->left = dfs(num,left,mid-1);
		root->right = dfs(num,mid+1,right);
		return root;
	}

    TreeNode *sortedArrayToBST(vector<int> &num) {
		return dfs(num,0,num.size()-1);
    }
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}