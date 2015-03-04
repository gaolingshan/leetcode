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

class Solution_old {
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

//2nd pass: 2015-03-04
class Solution_dfs {
public:
    void dfs(vector<int> &res, int now, int flag, int i, int n){
        if(i==n){
            res.push_back(now);
            return;
        }
		dfs(res,(now<<1)+flag,0,i+1,n);
		dfs(res,(now<<1)+!flag,1,i+1,n);
    }
    vector<int> grayCode(int n) {
        vector<int> res;
        dfs(res,0,0,0,n);
        return res;
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1,0);
        for(int i=0;i<n;i++){
            int num=1<<i, len=res.size();
            for(int j=len-1;j>=0;j--) res.push_back(num+res[j]);
        }
        return res;
    }
};

int main()
{
	Solution *s = new Solution();
	vector<int> res = s->grayCode(3);
	for(auto it:res) cout<<it<<" ";
	cout<<endl;

	system("pause");
	return 0;
}