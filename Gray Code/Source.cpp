// Gray Code
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

class Solution {
public:
	set<int> visited;
	int N,newNum;
    vector<int> res;
	void dfs(int now)
	{
		visited.insert(now);
		res.push_back(now);
		for(int i=0;i<N;i++)
		{
			newNum = now ^ (1<<i);
			if(visited.find(newNum) == visited.end()) dfs(newNum);
		}
	}
    vector<int> grayCode(int n) {
		N=n;
		dfs(0);
		return res;
    }
};

int main()
{
	Solution *s = new Solution();
	vector<int> res = s->grayCode(0);
	for(auto it:res) cout<<it<<" ";
	cout<<endl;

	system("pause");
	return 0;
}