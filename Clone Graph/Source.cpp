// Clone Graph
//   Author: flashhack
//   Update: 2015-01-11
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

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	unordered_map<int, UndirectedGraphNode*> visited;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(node==NULL) return NULL;
		vector<UndirectedGraphNode*> queue;
		int head=0,tail=0;
		queue.push_back(node);
		UndirectedGraphNode *res= new UndirectedGraphNode(node->label);
		visited[node->label] = res;
		while(head<=tail)
		{
			UndirectedGraphNode* now = queue[head];
			for(auto it:now->neighbors)
			{
				if(visited.find(it->label) == visited.end())
				{
					UndirectedGraphNode * newNode = new UndirectedGraphNode(it->label);
					visited[it->label] = newNode;
					queue.push_back(it);
					tail++;
					//trick here, can create neibours at the same time when bfs
					visited[now->label]->neighbors.push_back(newNode);
				}				
				else
				{
					visited[now->label]->neighbors.push_back(visited[it->label]);
				}
			}
			head++;
		}
		//for(auto it:queue)
		//{
		//	for(auto it2:it->neighbors)
		//		visited[it->label]->neighbors.push_back(visited[it2->label]);
		//}
		return res;
    }
};

int main()
{
	Solution *s = new Solution();


	system("pause");
	return 0;
}