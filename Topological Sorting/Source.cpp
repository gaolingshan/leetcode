// Topological Sorting
//   Author: flashhack
//   Update: 2015-02-22
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

struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    unordered_set<DirectedGraphNode*> visited;
    vector<DirectedGraphNode*> res;
    void dfs(DirectedGraphNode* node)
    {
        if(visited.count(node)!=0) return;
        visited.insert(node);
        for(auto next:node->neighbors) dfs(next);
        res.push_back(node);
    }
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        for(auto node:graph) dfs(node);
        reverse(res.begin(),res.end());
        return res;
    }
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}