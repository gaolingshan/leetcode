// Remove Node in Binary Search Tree
//   Author: flashhack
//   Update: 2015-02-25
#include <iostream>
#include <sstream>
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
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

class Solution {
public:
	TreeNode* get_left_most(TreeNode* node){
		while (node && node->left) node = node->left;
		return node;
	}
	TreeNode* removeNode(TreeNode* root, int value) {
		if (root == NULL) return NULL;
		if (value > root->val){
			root->right = removeNode(root->right, value);
			return root;
		}
		if (value < root->val){
			root->left = removeNode(root->left, value);
			return root;
		}
		if (root->left == NULL){
			auto tmp = root->right;
			delete(root);
			return tmp;
		}
		if (root->right == NULL){
			auto tmp = root->left;
			delete(root);
			return tmp;
		}
		auto tmp = get_left_most(root->right);
		root->val = tmp->val;
		root->right = removeNode(root->right, tmp->val);
		return root;
	}
};

int main()
{
	//Solution *s = new Solution();

	system("pause");
	return 0;
}