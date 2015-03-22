// Binary Tree Upside Down
//   Author: flashhack
//   Update: 2015-01-15
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
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
		vector<vector<TreeNode* > > levelOrder;
		vector<TreeNode*> now;
		if(root==NULL)
		{
			return root;
		}			
        vector<TreeNode*>queue;
		int head=0,tail=0,flag=0;
		queue.push_back(root);
		while(head<=tail)
		{
			now.push_back(queue[head]);
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
				levelOrder.push_back(now);
				now.clear();
				flag=tail;
			}
			head++;
		}
		
		TreeNode *newRoot=NULL;
		for(int i=levelOrder.size()-1;i>=0;i--)
		{
			if(newRoot==NULL) newRoot=levelOrder[i][0];
			levelOrder[i][0]->left=(levelOrder[i].size()==2)?levelOrder[i][1]:NULL;
			//trick here. must loop until i==0. And set the original root's right to NULL.
			//Otherwise the new tree got a loop and the tester will TLE
			levelOrder[i][0]->right=(i>0)?levelOrder[i-1][0]:NULL;
		}
		return newRoot;
    }
};

//2nd pass: 2015-02-20
class Solution_2nd {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        if(root==NULL) return root;
		auto left=root->left, right=root->right;
		root->left=NULL;
		root->right=NULL;
        if(left)
        {
            TreeNode* res=upsideDownBinaryTree(left);
            left->left=right;
            left->right=root;
            return res;
        }
        return root;
    }
};

//3rd pass: 2015-03-21
/*
    root
left    right   
1. recurse on left
2. turn to
    left
right   root    
3.boudary: no left child, just return itself.
*/
class Solution_Recur {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        if(root==NULL) return root;
        auto left=root->left, right=root->right;
        root->left=NULL; root->right=NULL;
        if(left) {
            auto res=upsideDownBinaryTree(left);
            left->left=right; left->right=root;   
            return res;
        }else return root;
    }
};

/*
iterative way, top down, simillar to reverse linked list
left child in flipped tree can be treated as a seperate linked list!!!!
    1
   / \
  2   3
 / \
4   5	
turn to
		   4   <-p
		  / \
right -> 5   2  <- prev  
			/ \
		   3   1  

prev: head of reversed list, right: head of parallel list!!
in reverse linked list, buffer p_next(p->left), here also need buffer right_next(p->right)
p->right=prev;  // same as reverse linked list
p->left=right;  // connect the paralled linked list to the main list!!
*/
class Solution {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        TreeNode* prev=NULL, *p=root, *right=NULL;
        while(p){
            auto p_next=p->left, right_next=p->right;
            p->right=prev; p->left=right;
            prev=p;
            p=p_next;
            right=right_next;
        }
        return prev;
    }
};

int main()
{
	Solution *s = new Solution();
	TreeNode a(1);
	TreeNode b(2);
	a.left=&b;
	s->upsideDownBinaryTree(&a);


	system("pause");
	return 0;
}