// Recover Binary Search Tree
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

class Solution_old {
public:
	void recoverTree(TreeNode *root) {
		vector<TreeNode*> st;
		TreeNode *now=root;
		if(root==NULL) return;
		TreeNode *a=NULL,*b=NULL,*prev=NULL,*cur=NULL;

		//tricky case
		//if only one descending, just swap adjacent nodes
		while(1)
		{
			if(now==NULL && st.empty()) break;
			if(now==NULL)
			{
				if(prev==NULL)
				{
					prev=st.back();
				}
				else
				{
					cur=st.back();
					if(prev->val > cur->val)
					{
						if(a==NULL)
						{
							a=prev;
							b=cur;		//in case of only one descending
						}
						else
						{
							b=cur;
							swap(a->val,b->val);
							return;
						}
					}
					prev=cur;
				}

				now=st.back()->right;
				st.pop_back();
			}
			else
			{
				st.push_back(now);
				now=now->left;
			}
		}        
		//deal with only one descending case
		swap(a->val,b->val);
	}
};

//2nd pass: 2015-02-04
class Solution {
public:
    void recoverTree(TreeNode *root) {
        vector<TreeNode*> st;
        TreeNode *now=root, *a=NULL, *b=NULL, *c=NULL;
        TreeNode *prev=NULL;
        while(1)
        {
            if(now!=NULL)
            {
                st.push_back(now);
                now=now->left;
                continue;
            }
            if(st.empty()) break;
            if(prev==NULL)
            {
                prev=st.back();
            }
            else
            {
                if(prev->val > st.back()->val)
                {
                    if(a==NULL)
                    {
                        a=prev;
                        b=st.back();
                    }
                    else
                    {
                        c=st.back();
                    }
                }
            }
            now=st.back()->right;
            prev=st.back();
            st.pop_back();
        }
        if(c==NULL) swap(a->val, b->val);
        else swap(a->val,c->val);
    }
};

int main()
{
	Solution *s = new Solution();
	TreeNode a(3);
	TreeNode b(1);
	TreeNode c(2);
	a.left=&b;
	a.right=&c;
	vector<int> tmp = inorderTraversal(&a);
	for(auto it:tmp)cout<<it<<" "; cout<<endl;

	s->recoverTree(&a);

	tmp = inorderTraversal(&a);
	for(auto it:tmp)cout<<it<<" "; cout<<endl;

	system("pause");
	return 0;
}