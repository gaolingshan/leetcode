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

class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
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