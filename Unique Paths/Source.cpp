// Unique Paths
//   Author: flashhack
//   Update: 2014-12-16
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
    int uniquePaths(int m, int n) {
		vector<int> f;
		if(m==0 || n==0) return 0;
		for(int i=0;i<n;i++) f.push_back(1);
		for(int i=1;i<m;i++)
			for(int j=1;j<n;j++)
				f[j]=f[j]+f[j-1];
		return f[n-1];
    }
};

//2nd pass: 2015-03-03
class Solution_nonRotate {
public:
    int uniquePaths(int m, int n) {
        if(m==0 || n==0) return 0;
        vector<vector<int>> f(m,vector<int>(n,0));
        f[0][0]=1;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(i-1>=0) f[i][j]+=f[i-1][j];
                if(j-1>=0) f[i][j]+=f[i][j-1];
            }
        return f[m-1][n-1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0 || n==0) return 0;
        vector<int> f(n,1);
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                f[j]=f[j]+f[j-1];
        return f[n-1];
    }
};

int main()
{
	Solution *s = new Solution();

	cout<<s->uniquePaths(2,2)<<endl;


	system("pause");
	return 0;
}