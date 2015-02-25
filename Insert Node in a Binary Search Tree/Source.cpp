// Insert Node in a Binary Search Tree
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

class TreeNode {
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
	TreeNode* insertNode(TreeNode* root, TreeNode* node) {
		if (root == NULL) return node;
		TreeNode *p = root;
		while (p){
			if (node->val > p->val){
				if (p->right == NULL) {
					p->right = node;
					break;
				}
				else
					p = p->right;
			}
			else{
				if (p->left == NULL){
					p->left = node;
					break;
				}
				else
					p = p->left;
			}
		}
		return root;
	}
};


int main()
{
	//Solution *s = new Solution();

	system("pause");
	return 0;
}