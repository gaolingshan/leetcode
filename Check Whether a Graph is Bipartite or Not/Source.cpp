// Check Whether a Graph is Bipartite or Not
//   Author: flashhack
//   Update: 2015-02-27
#include <iostream>
#include <sstream>
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

bool isBipartite(vector<vector<int>> G, int src){
	queue<int> q;
	vector<int> color(G.size(), -1);//1 RED, 2 BLUE
	q.push(src);
	color[src] = 1;
	while (!q.empty()){
		int head = q.front();
		q.pop();
		for (int i = 0; i < G.size(); i++) if (G[head][i]){
			if (color[i] == color[head]) return false;
			if (color[i] == -1) color[i] = (color[head] == 1) ? 2 : 1;
		}
	}
	return true;
}

int main()
{
	//Solution *s = new Solution();
	vector<vector<int>> G = { { 0, 1, 0, 1 },
	{ 1, 0, 1, 0 },
	{ 0, 1, 0, 1 },
	{ 1, 0, 1, 0 }
	};
	cout << isBipartite(G, 0) << endl;

	system("pause");
	return 0;
}