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
class Solution_2nd {
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

//3rd pass: 2015-03-30
/*
two flags: set 1st row & set 1st col
use 1st row & 1st col as flag to set the col/row

set steps:
row:2~m, set by col 1
col:2~n, set by row 1
fianlly set row1 & col1
*/
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        int m=matrix.size(), n=matrix[0].size();
        bool set1stRow=false, set1stCol=false;
        for(int i=0;i<n;++i) if(matrix[0][i]==0) {set1stRow=true;break;}
        for(int i=0;i<m;++i) if(matrix[i][0]==0) {set1stCol=true;break;}
        for(int i=1;i<m;++i) for(int j=1;j<n;++j) if(matrix[i][j]==0){matrix[i][0]=0; matrix[0][j]=0;}
        for(int i=1;i<m;++i) if(matrix[i][0]==0) for(int j=1;j<n;++j) matrix[i][j]=0;
        for(int j=1;j<n;++j) if(matrix[0][j]==0) for(int i=1;i<m;++i) matrix[i][j]=0;
        if(set1stRow) for(int i=0;i<n;++i) matrix[0][i]=0;
        if(set1stCol) for(int i=0;i<m;++i) matrix[i][0]=0;
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