// Construct Binary Tree from Preorder and Inorder Traversal
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
	TreeNode* build(vector<int> &preorder, vector<int> &inorder, int l1,int r1, int l2, int r2)
	{
		if(l1>r1 || l2>r2) return NULL;
		TreeNode* root = new TreeNode(preorder[l1]);
		for(int i=l2;i<=r2;i++)
			if(inorder[i]==preorder[l1])
			{
				root->left=build(preorder,inorder,l1+1,l1+i-l2,l2,i-1);
				root->right=build(preorder,inorder,r1-r2+i+1,r1,i+1,r2);
			}
		return root;
	}
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int len1=preorder.size();
		int len2=inorder.size();
		if(len1 != len2) return NULL;
		return build(preorder,inorder,0,len1-1,0,len2-1);
    }
};

//2nd pass: 2015-02-20
class Solution {
public:
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int l1, int r1, int l2, int r2)
    {
        if(l1>r1 || l2>r2) return NULL;
        int idx=l2;
        while(inorder[idx]!=preorder[l1])idx++;
        TreeNode*root=new TreeNode(preorder[l1]);
        root->left=build(preorder,inorder,l1+1,l1+idx-l2,l2,idx-1);
        root->right=build(preorder,inorder,l1+idx-l2+1,l1-l2+r2,idx+1,r2);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};

int main()
{
	Solution *s = new Solution();
	int A[]={1,3,2};
	int B[]={1,2,3};
	vector<int> inorder(A,A+sizeof(A)/sizeof(int));
	vector<int> preorder(B,B+sizeof(B)/sizeof(int));
	vector<int> res = inorderTraversal(s->buildTree(preorder,inorder));
	for(auto it:res) cout<<it<<" ";
	cout<<endl;

	system("pause");
	return 0;
}