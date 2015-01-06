// Populating Next Right Pointers in Each Node
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

class Solution {
public:
    void connect(TreeLinkNode *root) {
  		if(root==NULL) return;
		vector<TreeLinkNode*> queue,now;
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
				for(int i=0;i<now.size()-1;i++)
					now[i]->next=now[i+1];
				now.clear();
				flag=tail;
			}
			head++;
		}
    }
};

int main()
{
	Solution *s = new Solution();


	system("pause");
	return 0;
}