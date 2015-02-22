// Unique Binary Search Trees II
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
	vector<TreeNode*> dfs(vector<int> numbers)
	{
		vector<TreeNode *> res;
		if(numbers.size()==0) 
		{
			res.push_back(NULL);
			return res;
		}
		for(int i=0;i<numbers.size();i++)
		{
			vector<int> numbers_new;
			for(int j=0;j<i;j++)numbers_new.push_back(numbers[j]);
			vector<TreeNode*> left=dfs(numbers_new);

			numbers_new.clear();
			for(int j=i+1;j<numbers.size();j++)numbers_new.push_back(numbers[j]);
			vector<TreeNode*> right=dfs(numbers_new);

			for(int j=0;j<left.size();j++)
				for(int k=0;k<right.size();k++)
				{
					TreeNode *root=new TreeNode(numbers[i]);
					root->left = left[j];
					root->right = right[k];
					res.push_back(root);
				}
		}
		return res;
	}

    vector<TreeNode *> generateTrees(int n) {
		vector<int> numbers;
		for(int i=1;i<=n;i++)numbers.push_back(i);
		return dfs(numbers);
    }
};

//2nd pass: 2015-02-20
class Solution {
public:
    vector<TreeNode*> dfs(int st,int ed)
    {
        vector<TreeNode*> res;
        if(st>ed)
        {
            res.push_back(NULL);
            return res;
        }
        for(int i=st;i<=ed;i++)
        {
            vector<TreeNode*> left=dfs(st,i-1);
            vector<TreeNode*> right=dfs(i+1,ed);
            for(TreeNode* l:left)
                for(TreeNode* r:right)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    res.push_back(root);
                }
        }
        return res;
    }
    vector<TreeNode *> generateTrees(int n) {
        return dfs(1,n);
    }
};

int main()
{
	Solution *s = new Solution();
	vector<TreeNode*> res = s->generateTrees(4);
	for(auto it:res)
	{
		vector<int> tmp = inorderTraversal(it);
		for(auto it2:tmp) cout<<it2<<" ";
		cout<<endl;
	}

	system("pause");
	return 0;
}