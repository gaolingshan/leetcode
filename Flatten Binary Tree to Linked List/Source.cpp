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

class Solution_old {
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


//2nd pass: 2015-02-05
class Solution_2nd {
public:
    pair<TreeNode*,TreeNode*> dfs(TreeNode* root)
    {
        if(root==NULL)return make_pair<TreeNode*,TreeNode*>(NULL,NULL);
        auto res1 = dfs(root->left);
        auto res2 = dfs(root->right);
        root->left=NULL;
        root->right=NULL;
        if(res1.first != NULL) 
        {
            root->right=res1.first;
            res1.second->right=res2.first;
            return make_pair(root, res2.first==NULL?res1.second:res2.second);
        }
        else if(res2.first != NULL) 
        {
            root->right=res2.first;
            return make_pair(root, res2.second);
        }
        return make_pair(root,root);
    }

    void flatten(TreeNode *root) {
        dfs(root);
    }
};

//3rd pass: 2015-03-13
/*
flatten return head & tail
flatten left, flatten right
1. left not NULL: root -> left
    1.1 right not NULL: root->left->right
    1.2 right NULL: root -> left
2. right not NULL: root -> right
3. right NULL: root
*/
class Solution_recur {
public:
    pair<TreeNode*,TreeNode*> flat(TreeNode *root){
        if(root==NULL) return make_pair(root,root);
        auto left=flat(root->left), right=flat(root->right);
        root->left=NULL;
        if(left.first){
            root->right=left.first;
            if(right.first){
                left.second->right=right.first;
                return make_pair(root,right.second);
            }else return make_pair(root,left.second);
        }else if(right.first){
            root->right=right.first;
            return make_pair(root,right.second);
        }else return make_pair(root, root);
    }
    void flatten(TreeNode *root) {
        flat(root);
    }
};

/*
iterative, until root NULL
1. if has L, find right most node in left -> A
    1.1 put R as right child of A
    1.2 put L as right child of root
    1.3 L set NULL
2. root = root->right
*/
class Solution {
public:
    void flatten(TreeNode *root) {
        while(root){
            if(root->left){
                TreeNode *p=root->left, *R=root->right;
                while(p->right) p=p->right;
                p->right=R;
                root->right=root->left;
                root->left=NULL;
            }
            root=root->right;
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