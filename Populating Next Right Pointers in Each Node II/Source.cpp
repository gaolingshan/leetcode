// Populating Next Right Pointers in Each Node II
//   Author: flashhack
//   Update: 2015-01-06
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

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution_old {
public:
    void connect(TreeLinkNode *root) {
  		if(root==NULL) return;
		TreeLinkNode* Level_1_Start=root;
		TreeLinkNode* Level_2_Start;
		TreeLinkNode* Level_1_Now;
		TreeLinkNode* Level_2_Now;
		while(1)
		{
			//first find next level's start, using current level's next
			Level_2_Start = NULL;
			TreeLinkNode* tmp = Level_1_Start;
			while(tmp!=NULL)
			{
				if(tmp->left!=NULL) 
				{
					Level_2_Start=tmp->left;
					break;
				}
				if(tmp->right!=NULL)
				{
					Level_2_Start=tmp->right;
					break;
				}
				tmp=tmp->next;
			}
			if(Level_2_Start==NULL) break;	//No next level, just break;
			Level_1_Now = Level_1_Start;
			Level_2_Now = Level_2_Start;
			while(Level_1_Now != NULL)	//connect level2
			{
				if(Level_1_Now->left != NULL && Level_1_Now->left != Level_2_Now)
				{
					Level_2_Now->next = Level_1_Now->left;
					Level_2_Now = Level_2_Now->next;
				}
				if(Level_1_Now->right != NULL && Level_1_Now->right != Level_2_Now)
				{
					Level_2_Now->next = Level_1_Now->right;
					Level_2_Now = Level_2_Now->next;
				}
				Level_1_Now=Level_1_Now->next;
			}
			//move on to next level
			Level_1_Start = Level_2_Start;
		}
    }
};

//2nd pass: 2015-02-20
class Solution_2nd {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *p=root, *q=NULL, *q_first=NULL;
		while(p)
		{
			while(p) //相当于遍历p中的每个点，扩展出队列q
			{
				if(p->left)
				{
					if(q_first==NULL) q_first=p->left;
					if(q)q->next=p->left;
					q=p->left;
				}
				if(p->right)   
				{
					if(q_first==NULL) q_first=p->right;
					if(q)q->next=p->right;
					q=p->right;
				}
				p=p->next;
			}
			p=q_first;  //队列滚动！
			q=NULL; q_first=NULL;

		}
    }
};

//3rd pass: 2015-03-20
/*
level order traverse
p: current level
q: next level current, q_first: next level head

after p done, p=q_first, q=q_first=NULL;
*/
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *p=root, *q_first=NULL, *q=NULL;
        while(p){
            if(p->left){
                if(q_first==NULL) q_first=p->left;
                if(q) q->next=p->left;
                q=p->left;
            }
            if(p->right){
                if(q_first==NULL) q_first=p->right;
                if(q) q->next=p->right;
                q=p->right;
            }
            p=p->next;
            if(p==NULL){
                p=q_first;
                q_first=q=NULL;
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