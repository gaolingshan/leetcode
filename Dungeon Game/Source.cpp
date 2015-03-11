// Dungeon Game
//   Author: flashhack
//   Update: 2015-01-15
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

    int calculateMinimumHP(vector<vector<int> > &dungeon) {
		int m=dungeon.size();
		if(m==0) return 1;
		int n=dungeon[0].size();
		if(n==0) return 1;
		vector<int>f(n,0);
		f[n-1]=max(-dungeon[m-1][n-1],0)+1;
		for(int j=n-2;j>=0;j--) f[j]=max(f[j+1]-dungeon[m-1][j],1);
		for(int i=m-2;i>=0;i--)
			for(int j=n-1;j>=0;j--)
			{
				int a=(j+1<n)?f[j+1]:INT_MAX;
				int b=(i+1<m)?f[j]:INT_MAX;
				f[j]=max(min(a,b)-dungeon[i][j],1);
			}
		return f[0];
    }
};

/*
dp from end to begin
f[i][j]: from i,j reach end, init health
f[i][j]=max(1,min(f[i+1][j],f[i][j+1])-grid[i][j])
f[m-1][n-1]=max(1,-grid[m-1][n-1])
i:m-1~0
j:n-1~0
Time: O(n^2)
Space: O(n)
*/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        if(dungeon.empty() || dungeon[0].empty()) return 0;
        int m=dungeon.size(), n=dungeon[0].size();
        vector<vector<int>> f(m,vector<int>(n,0));
        for(int i=m-1;i>=0;--i){
            for(int j=n-1;j>=0;--j){
                int a=(i+1<m)?f[i+1][j]:INT_MAX;
                int b=(j+1<n)?f[i][j+1]:INT_MAX;
                int c=(a==b && a==INT_MAX)?1:min(a,b);
                f[i][j]=max(1,c-dungeon[i][j]);
            }
        }
        return f[0][0];
    }
};

int main()
{
	Solution *s = new Solution();
	vector<vector<int> > matrix;
	int A[][3]={{-2,-3,3},
				{-5,-10,1},
				{10,30,-5}};
	for(int i=0;i<3;i++)
	{
		vector<int> row(A[i],A[i]+sizeof(A[i])/sizeof(int));
		matrix.push_back(row);
	}
	cout<<s->calculateMinimumHP(matrix)<<endl;


	system("pause");
	return 0;
}