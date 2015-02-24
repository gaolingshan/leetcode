// Subsets II
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

class Solution_old {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
  		vector<vector<int> > res;
		int len=S.size();
		if(len==0) 
		{
			res.push_back(vector<int>());
			return res;
		}
		sort(S.begin(),S.end());
		for(int i=0;i< 1<<len;i++)
		{
			int j=i,k=0;
			vector<int> tmp;
			while(j!=0)
			{
				if(j%2) tmp.push_back(S[k]);
				k++;
				j/=2;
			}
			res.push_back(tmp);
		}

		sort(res.begin(),res.end());
		auto it = unique(res.begin(),res.end());
		res.resize(distance(res.begin(),it));

		return res;      
    }
};

//2nd pass: 2015-02-23
class Solution_sort {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		vector<vector<int>> res;
		vector<int> now;
		int len = S.size();
		for (long long flag = 0; flag<(1 << len); flag++)
		{
			now.clear();
			for (int i = 0; i<len; i++)
				if (flag & (1 << i)) now.push_back(S[i]);
			sort(now.begin(), now.end());
			res.push_back(now);
		}
		sort(res.begin(), res.end());
		res.resize(distance(res.begin(), unique(res.begin(), res.end())));
		return res;
	}
};

class Solution {
public:
	void dfs(int i, vector<vector<int>> &res, vector<int> &now, vector<int> &entries, unordered_map<int,int> &table)
	{
		if (i == entries.size())
		{
			res.push_back(now);
			return;
		}
		int total = table[entries[i]];
		for (int cnt = 0; cnt <= total; cnt++)
		{
			for (int j = 1; j <= cnt; j++) now.push_back(entries[i]);
			dfs(i + 1,res,now,entries,table);
			for (int j = 1; j <= cnt; j++) now.pop_back();
		}
	}
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		unordered_map<int, int> table;
		vector<int> entries;
		for (int v : S) table[v]++;
		for (auto it : table) entries.push_back(it.first);
		sort(entries.begin(), entries.end());
		vector<int> now;
		vector<vector<int>> res;
		dfs(0,res,now,entries,table);
		return res;
	}
};

int main()
{
	Solution *s = new Solution();
	vector<int> data = { 1, 2 ,2};

	vector<vector<int> > res = s->subsetsWithDup(data);
	for(auto it : res)
	{
		for(auto it2 : it) cout<<it2<<" ";
		cout<<endl;
	}


	system("pause");
	return 0;
}