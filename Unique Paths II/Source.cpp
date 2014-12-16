// Unique Paths II
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

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int m=obstacleGrid.size();
		if(m==0) return 0;
		int n=obstacleGrid[0].size();
		if(n==0) return 0;
		vector<int> f;
		bool flag=false;
		for(int i=0;i<n;i++) 
		{
			if(obstacleGrid[0][i]) flag=true;
			if(!flag) f.push_back(1); else f.push_back(0);
		}
		flag=obstacleGrid[0][0];
		for(int i=1;i<m;i++)
		{
			if(obstacleGrid[i][0])flag=true;
			if(!flag) f[0]=1; else f[0]=0;
			for(int j=1;j<n;j++)
				if(obstacleGrid[i][j]) f[j]=0; else
					f[j]=f[j]+f[j-1];
		}
		return f[n-1];        
    }
};

int main()
{
	Solution *s = new Solution();
	vector<vector<int> > matrix;
	int A[][3]={{0,0,0},
				{0,1,0},
				{0,0,0}};
	for(int i=0;i<3;i++)
	{
		vector<int> row(A[i],A[i]+sizeof(A[i])/sizeof(int));
		matrix.push_back(row);
	}
	cout<<s->uniquePathsWithObstacles(matrix)<<endl;

	system("pause");
	return 0;
}