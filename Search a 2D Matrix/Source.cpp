// Search a 2D Matrix
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

    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int m = matrix.size();
		if(m==0) return false;
		int n = matrix[0].size();
		if(n==0) return false;

		int left=0,right=m-1,mid=0;
		while(left+1<right)
		{
			mid = left+((right-left)>>1);
			if(target<matrix[mid][0]) right=mid-1;
			else
			if(target==matrix[mid][0]) return true;
			else
				left=mid;
		}
		int row=-1;
		if(left >=0 && left < m)
			if(matrix[left][0]==target) return true;
		else
			if(matrix[left][0]<target) row=left;
		if(right >=0 && right < m)
			if(matrix[right][0]==target) return true;
		else
			if(matrix[right][0]<target) row=right;
		if(row==-1) return false;

		left=0;right=n-1;
		while(left+1<right)
		{
			mid = left + ((right-left)>>1);
			if(target<matrix[row][mid]) right=mid-1;
			else
			if(target==matrix[row][mid]) return true;
			else
				left=mid;
		}
		if(left >=0 && left < n && matrix[row][left] == target) return true;
		if(right >=0 && right < n && matrix[row][right] == target) return true;
		return false;
    }
};


//2nd pass: 2015-02-07
/*
1st. find 1st colum, just < target. if == target return true;
2nd. search that row, find or not find
*/

class Solution_2nd {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.size()==0) return false;
        int left=0,right=matrix.size()-1,mid;
        while(left+1<right)
        {
            mid=left+((right-left)>>1);
            if(matrix[mid][0]==target) return true;
            if(matrix[mid][0]>target) right=mid-1;
            if(matrix[mid][0]<target) left=mid;
        }
		if(matrix[left][0] ==target || matrix[right][0]==target) return true;
        int row=(matrix[right][0]<target)?right:(matrix[left][0]<target)?left:-1;
        if(row==-1)return false;
        left=0; right=matrix[row].size()-1;
        while(left<=right)
        {
            mid=left+((right-left)>>1);
            if(matrix[row][mid]==target) return true;
            if(matrix[row][mid]>target) right=mid-1;
            if(matrix[row][mid]<target) left=mid+1;
        }
        return false;
    }
};

//3rd pass: 2015-02-18
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row=matrix.size();
        if(row==0) return false;
        int col=matrix[0].size();
        if(col==0) return false;
        int left=0,right=row*col-1,mid;
        while(left<=right)
        {
            mid=left+((right-left)>>1);
            int x=mid/col,y=mid%col;
            if(matrix[x][y]==target) return true;
            if(target>matrix[x][y]) left=mid+1;
            else right=mid-1;
        }
        return false;
    }
};

int main()
{
	Solution *s = new Solution();
	vector<vector<int> > matrix;
	int A[][3]={{1,2,3},
				{4,5,6},
				{7,8,9}};
	for(int i=0;i<3;i++)
	{
		vector<int> row(A[i],A[i]+sizeof(A[i])/sizeof(int));
		matrix.push_back(row);
	}
	cout<<s->searchMatrix(matrix,9)<<endl;


	system("pause");
	return 0;
}