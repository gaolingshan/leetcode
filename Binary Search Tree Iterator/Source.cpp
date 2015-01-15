// Binary Search Tree Iterator
//   Author: flashhack
//   Update: 2015-01-14
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

class BSTIterator {
public:
	vector<TreeNode*> stack;
	TreeNode* now;
    BSTIterator(TreeNode *root) {
        now=root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
		if(now!=NULL || !stack.empty()) return true;
    }

    /** @return the next smallest number */
    int next() {
		while(1)
		{
			if(now!=NULL)
			{
				stack.push_back(now);
				now=now->left;
			}
			else
			{
				now=stack.back()->right;
				int tmp=stack.back()->val;
				stack.pop_back();
				return tmp;
			}
		}
    }
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}