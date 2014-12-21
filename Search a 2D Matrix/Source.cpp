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

class Solution {
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
	cout<<s->searchMatrix(matrix,0)<<endl;


	system("pause");
	return 0;
}