// Spiral Matrix
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
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        //dir: 0¡ú 1¡ý 2¡û 3¡ü
		vector<int> res;
		if(matrix.size()==0) return res;
		int m=matrix.size();
		int n=matrix[0].size();

		bool** flag = new bool*[m];
		for(int i=0;i<m;i++) flag[i]=new bool[n];

		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				flag[i][j]=false;

		int i=0,j=0,dir=0;
		while(i!=m && j!=n)
		{
			res.push_back(matrix[i][j]);
			flag[i][j]=true;
			switch (dir)
			{
			case 0:
				j++;
				if(j>=n || flag[i][j])
				{
					j--;
					i++;
					dir++;
					if(i>=m || flag[i][j]) return res;
				}
				break;
			case 1:
				i++;
				if(i>=m || flag[i][j])
				{
					i--;
					j--;
					dir++;
					if(j<0 || flag[i][j]) return res;
				}
				break;
			case 2:
				j--;
				if(j<0 || flag[i][j])
				{
					j++;
					i--;
					dir++;
					if(i<0 || flag[i][j]) return res;
				}
				break;
			case 3:
				i--;
				if(i<0 || flag[i][j])
				{
					i++;
					j++;
					dir=0;
					if(j>=n || flag[i][j]) return res;
				}
				break;
			default:
				break;
			}
		}
		return res;
    }
};

int main()
{
	Solution *s = new Solution();

	vector<vector<int> > matrix;
/*
	int A[][3]={{1,2,3},
				{4,5,6},
				{7,8,9}};
	for(int i=0;i<3;i++)
	{
		vector<int> row(A[i],A[i]+sizeof(A[i])/sizeof(int));
		matrix.push_back(row);
	}
*/
	int A[][2]={{1,2}};
	for(int i=0;i<1;i++)
	{
		vector<int> row(A[i],A[i]+sizeof(A[i])/sizeof(int));
		matrix.push_back(row);
	}
	vector<int> res= s->spiralOrder(matrix);
	for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
	cout<<endl;


	system("pause");
	return 0;
}