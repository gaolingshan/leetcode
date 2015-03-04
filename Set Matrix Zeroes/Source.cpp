// Set Matrix Zeroes
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
	void setZeroes(vector<vector<int> > &matrix) {
		int m=matrix.size();
		if(m==0) return;
		int n=matrix[0].size();
		if(n==0) return;

		bool set1stRow=false, set1stCol=false;
		for(int i=0;i<n;i++) 
		{
			if(matrix[0][i]==0)
			{
				set1stRow=true;
				break;
			}
		}

		for(int i=0;i<m;i++)
		{
			if(matrix[i][0]==0)
			{
				set1stCol=true;
				break;
			}
		}
		for(int i=1;i<m;i++)
		{
			for(int j=1;j<n;j++)
				if(matrix[i][j]==0)
				{
					matrix[0][j]=0;
					matrix[i][0]=0;
				}
		}

		for(int j=1;j<n;j++)
		{
			if(matrix[0][j]==0)
				for(int i=0;i<m;i++) matrix[i][j]=0;
		}

		for(int i=1;i<m;i++)
		{
			if(matrix[i][0]==0)
				for(int j=0;j<n;j++) matrix[i][j]=0;
		}

		if(set1stRow) for(int j=0;j<n;j++) matrix[0][j]=0;
		if(set1stCol) for(int i=0;i<m;i++) matrix[i][0]=0;		
	}
};

//2nd pass: 2015-03-04
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
		int m=matrix.size();
		if(m==0) return;
		int n=matrix[0].size();
		if(n==0) return;
		bool set1stRow=false, set1stCol=false;
		for(int j=0;j<n;j++) if(matrix[0][j]==0) {set1stRow=true; break;}
		for(int i=0;i<m;i++) if(matrix[i][0]==0) {set1stCol=true; break;}
		for(int i=0;i<m;i++)
		    for(int j=0;j<n;j++) if(matrix[i][j]==0){
		        matrix[i][0]=0;
		        matrix[0][j]=0;
		    }
		for(int i=1;i<m;i++) 
		    if(matrix[i][0]==0)
		        for(int j=0;j<n;j++) matrix[i][j]=0;
		for(int j=1;j<n;j++)
		    if(matrix[0][j]==0)
		        for(int i=0;i<m;i++) matrix[i][j]=0;
		if(set1stRow) for(int j=0;j<n;j++) matrix[0][j]=0;
		if(set1stCol) for(int i=0;i<m;i++) matrix[i][0]=0;
    }
};

int main()
{
	Solution *s = new Solution();
	vector<vector<int> > matrix;
	int A[][3]={{1,2,0},
				{4,5,6},
				{7,8,9}};
	for(int i=0;i<3;i++)
	{
		vector<int> row(A[i],A[i]+sizeof(A[i])/sizeof(int));
		matrix.push_back(row);
	}

	s->setZeroes(matrix);

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++) cout<<matrix[i][j]<<" ";
		cout<<endl;
	}


	system("pause");
	return 0;
}