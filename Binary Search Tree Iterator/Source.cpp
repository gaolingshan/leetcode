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

class BSTIterator_old {
public:
	vector<TreeNode*> stack;
	TreeNode* now;
    BSTIterator_old(TreeNode *root) {
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

//2nd pass: 2015-03-22
/*
 1
2 3
   4
st: 1 2
output:2 1 3 4
has p, push stack, p = p->left
no p, pop stack, p=stack.top->right
*/
class BSTIterator {
private:
    stack<TreeNode*> st;
    TreeNode *p;
public:
    BSTIterator(TreeNode *root) {
        p=root;
    }
    bool hasNext() {
        if(p!=NULL || !st.empty()) return true; else return false;
    }
    int next() {
        while(p!=NULL || !st.empty()){
            if(p){
                st.push(p);
                p=p->left;
            }else{
                int ans=st.top()->val;
                p=st.top()->right;
                st.pop();
                return ans;
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