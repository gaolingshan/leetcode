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

class Solution_iter {
public:
    int maxDepth(TreeNode *root) {
	    stack<pair<TreeNode*,int>> st;
        int ans=0;
        if(root) st.push(make_pair(root,1));
        while(!st.empty()){
            auto head=st.top();
            st.pop();
            ans=max(ans,head.second);
            if(head.first->left) st.push(make_pair(head.first->left,head.second+1));
            if(head.first->right) st.push(make_pair(head.first->right,head.second+1));
        }
        return ans;
    }
};

int main()
{
	Solution *s = new Solution();


	system("pause");
	return 0;
}