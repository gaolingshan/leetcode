// Combinations
//   Author: flashhack
//   Update: 2014-12-21
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

class Solution_old {
public:
	void dfs(vector<vector<int> > &res, vector<int> &now,int i, int n, int k)
	{
		if(i==k)
		{
			res.push_back(now);
			return;
		}
		int prev=0;
		if(i!=0)prev=now[i-1];
		for(int j=prev+1;j<=n;j++)
		{
			now[i]=j;
			dfs(res,now,i+1,n,k);
			now[i]=0;
		}
	}

    vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > res;
		if(n==0 || k==0 || k>n) return res;
        vector<int> now(k,0);
		dfs(res,now,0,n,k);
		return res;
    }
};

//2nd pass: 2015-02-23
class Solution {
public:
	void dfs(vector<vector<int>> &res, vector<int> &now, int n, int k)
	{
		if (k == 0)
		{
			auto tmp = now;
			reverse(tmp.begin(), tmp.end());
			res.push_back(tmp);
			return;
		}
		if (n == 0) return;
		now.push_back(n);
		dfs(res,now,n - 1, k - 1);
		now.pop_back();
		dfs(res,now,n - 1, k);
	}
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> now;
		dfs(res, now, n, k);
		return res;
	}
};

int main()
{
	Solution *s = new Solution();
	vector<vector<int> > res = s->combine(4,4);
	for(auto it : res)
	{
		for(auto it2 : it) cout<<it2<<" ";
		cout<<endl;
	}


	system("pause");
	return 0;
}