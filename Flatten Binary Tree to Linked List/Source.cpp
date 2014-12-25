// Flatten Binary Tree to Linked List
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
    void flatten(TreeNode *root) {
		if(root==NULL) return;
		flatten(root->left);
		flatten(root->right);
		if(root->left!=NULL)
		{
			TreeNode *p = root->left;
			while(p->right != NULL) p=p->right;
			TreeNode *tmp = root->right;
			root->right=root->left;
			root->left=NULL;	//fuck! forget to nullify the left child. got wierd RTE. Maybe it's the judge's bug
			p->right=tmp;
		}
    }
};

int main()
{
	Solution *s = new Solution();
	TreeNode a(1);
	TreeNode b(2);
	a.left = &b;
	s->flatten(&a);

	system("pause");
	return 0;
}