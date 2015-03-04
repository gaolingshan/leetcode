// <filename>.<ext>
//   Author: <name>
//   Update: <date>
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

class Solution_BruteForce {
public:
	int f[1000][1000];

    int minPathSum(vector<vector<int> > &grid) {
		int m=grid.size();
		if(m==0) return 0;
		int n=grid[0].size();
		int a=0,b=0;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				a=INT_MAX; b=INT_MAX;
				if(i-1>=0) a=f[i-1][j]+grid[i][j]; 
				if(j-1>=0) b=f[i][j-1]+grid[i][j];
				if(a!=INT_MAX || b!=INT_MAX) f[i][j]=min(a,b); else f[i][j]=grid[i][j];
			}
		return f[m-1][n-1];
    }
};

//¹ö¶¯Êý×é
class Solution_old {
public:
    int minPathSum(vector<vector<int> > &grid) {
		int m=grid.size();
		if(m==0) return 0;
		int n=grid[0].size();
		vector<int> f;
		f.push_back(grid[0][0]);
		for(int i=1;i<n;i++) f.push_back(f[i-1]+grid[0][i]);
		for(int i=1;i<m;i++)
			for(int j=0;j<n;j++)
			{
				f[j]=f[j]+grid[i][j]; 
				if(j-1>=0) f[j]=min(f[j]+grid[i][j],f[j-1]+grid[i][j]);
			}
		return f[n-1];
    }
};

//2nd pass: 2015-03-04
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        if(n==0) return 0;
        vector<vector<int>> f(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                int a=INT_MAX, b=INT_MAX;
                if(i-1>=0) a=f[i-1][j];
                if(j-1>=0) b=f[i][j-1];
                if(a==INT_MAX && b==INT_MAX) f[i][j]=grid[i][j]; else f[i][j]=grid[i][j]+min(a,b);
            }
        return f[m-1][n-1];
    }
};


int main()
{
	Solution *s = new Solution();
	vector<vector<int> > matrix;

	//int A[][3]={{1,2,3},
	//			{4,5,6},
	//			{7,8,9}};
	int A[][3]={{1,2,5},
				{3,2,1}};
	for(int i=0;i<2;i++)
	{
		vector<int> row(A[i],A[i]+sizeof(A[i])/sizeof(int));
		matrix.push_back(row);
	}

	cout<<s->minPathSum(matrix)<<endl;

	system("pause");
	return 0;
}