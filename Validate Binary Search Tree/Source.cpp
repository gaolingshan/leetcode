// Validate Binary Search Tree
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
    bool isValidBST(TreeNode *root) {
		vector<int> res;        
		vector<TreeNode*> st;
		TreeNode *now=root;
		while(1)
		{
			if(now==NULL && st.empty()) return true;
			if(now==NULL)
			{
				if(!res.empty() && st.back()->val <= res.back()) return false;
				res.push_back(st.back()->val);
				now=st.back()->right;
				st.pop_back();
			}
			else
			{
				st.push_back(now);
				now=now->left;
			}
		}
        return true;
    }
};

int main()
{
	Solution *s = new Solution();
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	a.right=&b;
	b.left=&c;
	cout<<s->isValidBST(&a)<<endl;

	system("pause");
	return 0;
}