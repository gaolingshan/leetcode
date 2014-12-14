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