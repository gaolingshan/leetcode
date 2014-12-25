// Same Tree
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==NULL && q==NULL) return true;
		if(p==NULL) return false;
		if(q==NULL) return false;
		if(p->val != q->val) return false;
		return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}