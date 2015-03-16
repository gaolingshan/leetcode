// Binary Tree Level Order Traversal
//   Author: flashhack
//   Update: 2014-12-13
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

class Solution_1st {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > res;
		vector<int> now;
		if(root==NULL)
		{
			return res;
		}			
        vector<TreeNode*>queue;
		int head=0,tail=0,flag=0;
		queue.push_back(root);
		while(head<=tail)
		{
			now.push_back(queue[head]->val);
			if(queue[head]->left != NULL) 
			{
				queue.push_back(queue[head]->left);
				tail++;
			}
			if(queue[head]->right != NULL)
			{
				queue.push_back(queue[head]->right);
				tail++;
			}
			if(head==flag)
			{
				res.push_back(now);
				now.clear();
				flag=tail;
			}
			head++;
		}
		return res;
    }
};

//2nd pass: 2015-02-20
/*
use bfs, two qeueus p&q. p is current level, q is next level
use now to record current level res
when found q empty, swap p,q and output result
*/
class Solution_bfs {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        vector<int> now;
        if(root==NULL) return res;
        deque<TreeNode*> p,q;
        p.push_back(root);
        while(!p.empty())
        {
            auto head=p.front();
            p.pop_front();
            now.push_back(head->val);
            if(head->left) q.push_back(head->left);
            if(head->right) q.push_back(head->right);
            if(p.empty())
            {
                res.push_back(now);
                now.clear();
                p=q;
                q.clear();
            }
        }
        return res;
    }
};

//3rd pass: 2015-02-27
class Solution {
public:
    int maxDepth(TreeNode *root){
        if(root==NULL) return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
    void dfs(TreeNode *root, vector<int> &now, int depth){
		if (root==NULL) return;
        if(depth==1){
            now.push_back(root->val);
            return;
        }
        dfs(root->left,now,depth-1);
        dfs(root->right,now,depth-1);
    }
    vector<vector<int> > levelOrder(TreeNode *root) {
        int depth=maxDepth(root);
        vector<vector<int>> res;
        if(depth==0) return res;
        for(int level=1;level<=depth;level++){
            vector<int> now;
            dfs(root,now,level);
            res.push_back(now);
        }
        return res;
    }
};

int main()
{
	Solution *s = new Solution();

	TreeNode a(3);
	TreeNode b(9);
	TreeNode c(20);
	TreeNode d(15);
	TreeNode e(7);
	a.left = &b;
	a.right=&c;
	c.left=&d;
	c.right=&e;

	vector<vector<int> > res = s->levelOrder(&a);
	for(auto it1:res)
	{
		for(auto it2:it1) cout << it2 << " ";
		cout<<endl;
	}

	system("pause");
	return 0;
}