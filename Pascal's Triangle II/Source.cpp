// Pascal's Triangle II
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
    vector<int> getRow(int rowIndex) {
		rowIndex+=1;
		vector<int> now,prev;
		now.push_back(1);
		if(rowIndex==0) return now;
		prev=now;
		for(int i=1;i<rowIndex;i++)
		{
			now.clear();
			for(int j=0;j<=i;j++)
			{
				int a = (j-1>=0)?prev[j-1]:0;
				int b = (j<=i-1)?prev[j]:0;
				now.push_back(a+b);
			}
			prev=now;
		}
		return now;
    }
};

/*
1
1 1
1 2 1
1 3 3 1
f[i][j]=f[i-1][j-1]+f[i-1][j]
f[j]=g[j-1]+g[j]
j&j-1 >=0 <f[i-1].size()
g=f
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> f,g;
        g.push_back(1);
        for(int i=1;i<=rowIndex;++i){
            for(int j=0;j<=i;j++){
                int a=(j-1>=0)?g[j-1]:0;
                int b=(j<g.size())?g[j]:0;
                f.push_back(a+b);
            }
            g=f;
            f.clear();
        }
        return g;
    }
};

int main()
{
	Solution *s = new Solution();
	vector<int> res = s->getRow(5);
	for(auto it : res) cout<<it<<" ";
	cout<<endl;


	system("pause");
	return 0;
}