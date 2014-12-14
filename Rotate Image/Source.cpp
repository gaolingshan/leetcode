// Rotate Image
//   Author: flashhack
//   Update: 2014-12-14
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
    void rotate(vector<vector<int> > &matrix) {
		int dim=matrix.size();
		for(int i=0;i<dim;i++)
			reverse(matrix[i].begin(),matrix[i].end());
		for(int i=0;i<dim;i++)
			for(int j=0;j<dim-i;j++) swap(matrix[i][j],matrix[dim-1-j][dim-1-i]);
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
	s->rotate(matrix);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++) cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
	



	system("pause");
	return 0;
}