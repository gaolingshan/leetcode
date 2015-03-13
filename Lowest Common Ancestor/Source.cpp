// Lowest Common Ancestor
//   Author: flashhack
//   Update: 2015-02-19
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


/*
1. A||B is root -> LCA found
2. l=LCA(left), r=LCA(right)
    2.1 l,r both non NULL, root is LCA
    2.1 l||r==NULL, LCA is non NULL one
    2.3 l,r both NULL, return NULL
*/
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        if(!root) return NULL;
        if(root==A || root==B) return root;
        TreeNode* lcaLeft=lowestCommonAncestor(root->left,A,B);
        TreeNode* lcaRight=lowestCommonAncestor(root->right,A,B);
        if(lcaLeft && lcaRight) return root;
        return (lcaLeft)?lcaLeft:lcaRight;
    }
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}