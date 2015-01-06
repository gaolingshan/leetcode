// Triangle
//   Author: flashhack
//   Update: 2015-01-06
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
	int f[1000];
    int minimumTotal(vector<vector<int> > &triangle) {
		int numRows=triangle.size();
		if(numRows==0) return 0;
		for(int i=0;i<numRows;i++)f[i]=triangle[numRows-1][i];
		for(int i=numRows-2;i>=0;i--)
		{
			for(int j=0;j<=i;j++)
				f[j]=triangle[i][j]+min(f[j],f[j+1]);
		}
		return f[0];
    }
};

int main()
{
	Solution *s = new Solution();
	vector<vector<int>> data;
	int A[]={1};
	vector<int> tmp(A,A+sizeof(A)/sizeof(int));
	data.push_back(tmp);
	int B[]={2,3};
	tmp.assign(B,B+sizeof(B)/sizeof(int));
	data.push_back(tmp);
	cout<<s->minimumTotal(data)<<endl;

	system("pause");
	return 0;
}