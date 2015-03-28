// Combination Sum II
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

class Solution_old {
public:
	void dfs(vector<vector<int> > &res, vector<int> &now, vector<int> &num, int pos, int target)
	{
		if(target == 0)
		{
			res.push_back(now);
			return;
		}
		if(pos == num.size()) return;
		if(target >= num[pos])
		{
			now.push_back(num[pos]);
			dfs(res,now,num,pos+1,target-num[pos]);
			now.pop_back();
		}
		dfs(res,now,num,pos+1,target);
	}

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		vector<vector<int> > result;
		vector<int> now;
		sort(num.begin(),num.end());
		dfs(result,now,num,0,target);

		sort(result.begin(),result.end());
		auto it = unique(result.begin(),result.end());
		result.resize(distance(result.begin(),it));
		return result;
    }
};


//2nd pass: 2015-02-23
class Solution_2nd {
public:
	vector<int> now;
	vector<vector<int>> res;
	void dfs(int i, int target, vector<int> &num)
	{
		if (target == 0)
		{
			res.push_back(now);
			return;
		}
		if (i == num.size()) return;
		dfs(i + 1, target, num);
		if (target >= num[i])
		{
			now.push_back(num[i]);
			dfs(i + 1, target - num[i], num);
			now.pop_back();
		}
	}
	vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		dfs(0, target, candidates);
		sort(res.begin(), res.end());
		res.resize(distance(res.begin(),unique(res.begin(),res.end())));
		return res;
	}
};

//3rd pass: 2015-03-23
/*
1. get (num,cnt_num)
2. same num can put up to cnt_num time
*/
class Solution {
public:
    void dfs(vector<vector<int>> &res, vector<int> &now, vector<pair<int,int>> &candidates, int i, int target){
        if(target==0){
            res.push_back(now);
            return;
        }
        if(i==candidates.size()) return;
        for(int j=1;j<=candidates[i].second;++j)
            if(target>=j*candidates[i].first){
                for(int k=0;k<j;++k) now.push_back(candidates[i].first);
                dfs(res,now,candidates,i+1,target-j*candidates[i].first);
                for(int k=0;k<j;++k) now.pop_back();
            }else break;
        if(target>=candidates[i].first) dfs(res,now,candidates,i+1,target);
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> res;
        vector<int> now;
        map<int,int> table;
        for(int v:num) ++table[v];
        vector<pair<int,int>> candidates;
        for(auto kv:table) candidates.emplace_back(kv.first,kv.second);
        dfs(res,now,candidates,0,target);
        return res;        
    }
};

int main()
{
	Solution *s = new Solution();

	int data[] = {13,23,25,11,7,26,14,11,27,27,26,12,8,20,22,34,27,17,5,26,31,11,16,27,13,20,29,18,7,14,13,15,25,25,21,27,16,22,33,8,15,25,16,18,10,25,9,24,7,32,15,26,30,19};
	vector<int> num(data,data+sizeof(data)/sizeof(int));

	vector<vector<int> > res = s->combinationSum2(num,25);

	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++) cout<<res[i][j]<<" ";
		cout<<endl;
	}

	system("pause");
	return 0;
}