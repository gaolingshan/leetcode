// Combination Sum
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

class Solution {
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
			dfs(res,now,num,pos,target-num[pos]);
			now.pop_back();
		}
		dfs(res,now,num,pos+1,target);
	}

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<vector<int> > result;
		vector<int> now;
		sort(candidates.begin(),candidates.end());
		dfs(result,now,candidates,0,target);

		sort(result.begin(),result.end());
		auto it = unique(result.begin(),result.end());
		result.resize(distance(result.begin(),it));
		return result;
    }
};

int main()
{
	Solution *s = new Solution();

	int data[] = {2,3,6,7};
	vector<int> num(data,data+sizeof(data)/sizeof(int));

	vector<vector<int> > res = s->combinationSum(num,7);

	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++) cout<<res[i][j]<<" ";
		cout<<endl;
	}

	system("pause");
	return 0;
}