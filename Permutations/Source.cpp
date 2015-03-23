// Permutations
//   Author: flashhack
//   Update: 2014-12-14
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
    vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > res;
		sort(num.begin(),num.end());
		res.push_back(num);
		int i=0,j=0,len=num.size();
		while(1)
		{
			i=len-2;
			for(i=len-2;i>=0;i--)
				if(num[i]<num[i+1])break;
			if(i<0)break;
			for(j=len-1;j>i;j--) if(num[j]>num[i])break;
			swap(num[i],num[j]);
			reverse(num.begin()+i+1,num.end());
			res.push_back(num);
		}
		return res;

    }
};

//2nd pass: 2015-02-24
class Solution_2nd {
public:
	vector<vector<int>> res;
	void dfs(int i, vector<int> &now)
	{
		if (i == now.size())
		{
			res.push_back(now);
			return;
		}
		for (int j = i; j<now.size(); j++)
		{
			swap(now[i], now[j]);
			dfs(i + 1, now);
			swap(now[i], now[j]);
		}
	}
	vector<vector<int> > permute(vector<int> &num) {
		sort(num.begin(), num.end());
		dfs(0, num);
		return res;
	}
};

//3rd pass: 2015-03-22
class Solution {
public:
    void dfs(vector<vector<int>> &res, vector<int> &now, int i){
        if(i==now.size()){
            res.push_back(now);
            return;
        }
        for(int j=i;j<now.size();++j){
            swap(now[i],now[j]);
            dfs(res,now,i+1);
            swap(now[i],now[j]);
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> res;
        dfs(res,num,0);
        return res;
    }
};


int main()
{
	Solution *s = new Solution();

	int A[] = {1,2,3};
	vector<int> data(A,A+sizeof(A)/sizeof(int));

	vector<vector<int> > res = s->permute(data);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++) cout<<res[i][j]<<" ";
		cout<<endl;
	}
	

	system("pause");
	return 0;
}