/*
in-order traversal the tree. if it is a BST, should be sorted.
if the first time find a number in the traversal sequence, is <= previous number, then false

use stack, not recursion to do the traversal



*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if(root == NULL) return true;
        vector<TreeNode*> st;
        vector<int> numbers;
        TreeNode* p = root;
        while(1)
        {
            if(p!=NULL)
            {
                st.push_back(p);
                p=p->left;
                continue;
            }
            else
            {
                if(st.empty()) return true;    //traverse complete
                if(!numbers.empty() && st.back()->val <= numbers.back()) return false;    //find a violence
                numbers.push_back(st.back()->val);
                p=st.back()->right;
                st.pop_back();
            }
        }
    }
};

int main()
{
    Solution s;
    TreeNode a(1);
    TreeNode b(0);
    TreeNode c(2);
    a.left = &b;
    a.right= &c;
    cout<<s.isValidBST(&a)<<endl;
    
    cout<<"done"<<endl;
    getchar();
    return 0;
}