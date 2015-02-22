// Construct Binary Tree from Inorder and Postorder Traversal
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
	TreeNode* build(vector<int> &postorder, vector<int> &inorder, int l1,int r1, int l2, int r2)
	{
		if(l1>r1 || l2>r2) return NULL;
		TreeNode* root = new TreeNode(postorder[r1]);
		for(int i=l2;i<=r2;i++)
			if(inorder[i]==postorder[r1])
			{
				root->left=build(postorder,inorder,l1,l1+i-l2-1,l2,i-1);
				root->right=build(postorder,inorder,r1-r2+i,r1-1,i+1,r2);
				break;
			}
		return root;
	}
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		int len1=postorder.size();
		int len2=inorder.size();
		if(len1 != len2) return NULL;
		return build(postorder,inorder,0,len1-1,0,len2-1);        
    }
};

class Solution {
public:
    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int l1,int r1, int l2, int r2)
    {
        if(l1>r1 || l2>r2) return NULL;
        TreeNode*root=new TreeNode(postorder[r2]);
        //postorder:  l2~l2+idx-1-l1   l2+idx-l1~l2-l1+r1-1   r2
        //inorder:    l1~idx-1  idx  idx+1~r1
        int idx=l1;
        while(inorder[idx]!=postorder[r2]) idx++;
        root->left=build(inorder,postorder,l1,idx-1,l2,l2+idx-1-l1);
        root->right=build(inorder,postorder,idx+1,r1,l2+idx-l1,l2-l1+r1-1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};

int main()
{
	Solution *s = new Solution();
	int A[]={1,3,2};
	int B[]={3,2,1};
	vector<int> inorder(A,A+sizeof(A)/sizeof(int));
	vector<int> postorder(B,B+sizeof(B)/sizeof(int));
	vector<int> res = inorderTraversal(s->buildTree(inorder,postorder));
	for(auto it:res) cout<<it<<" ";
	cout<<endl;


	system("pause");
	return 0;
}