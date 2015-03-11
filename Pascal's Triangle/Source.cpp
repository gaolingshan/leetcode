// Pascal's Triangle
//   Author: flashhack
//   Update: 2015-01-06
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
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
		vector<int> now;
		if(numRows==0) return res;
		now.push_back(1);
		res.push_back(now);
		if(numRows==1) return res;
		for(int i=1;i<numRows;i++)
		{
			now.clear();
			for(int j=0;j<=i;j++)
			{
				int a = (j-1>=0)?res[i-1][j-1]:0;
				int b = (j<=i-1)?res[i-1][j]:0;
				now.push_back(a+b);
			}
			res.push_back(now);
		}
		return res;
    }
};

//2nd pass: 2015-03-10
/*
1
1 1
1 2 1
1 3 3 1
f[i][j]=f[i-1][j]+f[i-1][j-1]
j&j-1 need to be >=0 && <f[i-1].size(). otherwise 0
*/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==0) return res;
        res.push_back({1});
        for(int i=1;i<numRows;++i){
            vector<int> now;
            for(int j=0;j<=i;j++){
                int a=(j-1>=0)?res[i-1][j-1]:0;
                int b=(j<res[i-1].size())?res[i-1][j]:0;
                now.push_back(a+b);
            }
            res.push_back(now);
        }
        return res;
    }
};

int main()
{
	Solution *s = new Solution();
	vector<vector<int> > v = s->generate(5);
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++) cout<<v[i][j]<<" ";
		cout<<endl;
	}

		


	system("pause");
	return 0;
}