// Subsets
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
    vector<vector<int> > subsets(vector<int> &S) {
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
class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
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
		return res;
	}
};

int main()
{
	Solution *s = new Solution();
	int A[]={1,2,3};
	vector<int> data(A,A+sizeof(A)/sizeof(int));

	vector<vector<int> > res = s->subsets(data);
	for(auto it : res)
	{
		for(auto it2 : it) cout<<it2<<" ";
		cout<<endl;
	}



	system("pause");
	return 0;
}