// Binary Tree Inorder Traversal
//   Author: flashhack
//   Update: 2014-12-23
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

TreeNode* build(string A[], int len)
{
	if(len==0) return NULL;
	TreeNode *root = new TreeNode(atoi(A[0].c_str()));
	vector<TreeNode*>queue;
	queue.push_back(root);
	int head=0,i=1;
	while(1)
	{
		if(A[i]!="#")
		{
			
		}
	}
	return root;
}
 
class Solution_stack {
public:
    vector<int> inorderTraversal(TreeNode *root) {
		vector<int> res;        
		vector<TreeNode*> st;
		TreeNode *now=root;
		while(1)
		{
			if(now==NULL && st.empty()) break;
			if(now==NULL)
			{
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
		return res;
    }
};

//2nd pass: 2015-02-20
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *p=root;
        while(p)
        {
            if(p->left==NULL)
            {
                res.push_back(p->val);
                p=p->right;
            }
            else
            {
                TreeNode *prev=p->left;
                while(prev->right && prev->right!=p) prev=prev->right;
                if(prev->right==NULL)
                {
                    prev->right=p;
                    p=p->left;
                }
                else
                {
                    res.push_back(p->val);
                    prev->right=NULL;
                    p=p->right;
                }
            }
        }
		return res;
    }
};

int main()
{
	Solution *s = new Solution();
	//string A[]={"1","#","2","3"};
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	a.right=&b;
	b.left=&c;
	vector<int> res = s->inorderTraversal(&a);
	for(auto it:res) cout<<it<<" ";
	cout<<endl;




	system("pause");
	return 0;
}

