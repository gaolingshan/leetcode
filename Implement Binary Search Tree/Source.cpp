// Implement Binary Search Tree
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

template <class T>
class BST {
public:
	struct TreeNode {
	public:
		int val;
		TreeNode *left, *right;
		TreeNode(T val) {
			this->val = val;
			this->left = this->right = NULL;
		}
	};
	BST(){

	}
	~BST(){
		deleteTree(root);
	}
	void deleteTree(TreeNode *root){
		if (root == NULL) return;
		deleteTree(root->left);
		deleteTree(root->right);
		delete(root); 
	}
	void insert(T val) {
		if (root == NULL) {
			root = new TreeNode(val);
			return;
		}
		TreeNode *p = root;
		while (p){
			if (val > p->val){
				if (p->right == NULL) {
					p->right = new TreeNode(val);
					break;
				}
				else
					p = p->right;
			}
			else{
				if (p->left == NULL){
					p->left = new TreeNode(val);
					break;
				}
				else
					p = p->left;
			}
		}
	}

	TreeNode* get_left_most(TreeNode* node){
		while (node && node->left) node = node->left;
		return node;
	}
	TreeNode* removeNode(TreeNode* root, T value) {
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
	void remove(T val){
		root = removeNode(root, val);
	}
private:
	TreeNode* root{ NULL };
};


int main()
{
	//Solution *s = new Solution();

	system("pause");
	return 0;
}