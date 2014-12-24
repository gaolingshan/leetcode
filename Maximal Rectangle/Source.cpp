// Maximal Rectangle
//   Author: flashhack
//   Update: 2014-12-22
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


//136ms need improve
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        vector<int> st;
		int res=0;
		int top=0,h=0;
		for(int i=0;i<height.size();i++)
		{
			if(st.empty() || height[i] >= height[st.back()])
			{
				st.push_back(i);
			}
			else
			{
				top=st.back();
				while(!st.empty() && height[st.back()] > height[i])
				{
					//trick here. real horizontal distance is after pop+1~top, height is still before pop, so record h 
					h = height[st.back()];
					st.pop_back();
					res = max(res, h*(st.empty()?top + 1:top - st.back()));
				}
				st.push_back(i);
			}
		}
		return res;
    }	

    int maximalRectangle(vector<vector<char> > &matrix) {
		int m=matrix.size();
		if(m==0) return 0;
		int n=matrix[0].size();
		if(n==0) return 0;

		vector<int> height(n+1,0);
		int res=0;
		for(int i=m-1;i>=0;i--)
		{
			for(int j=0;j<n;j++)
			{
				if(height[j]>=1) height[j]-=1;
				else
				{
					if(matrix[i][j]!='0') 
					{
						int k=i-1;
						for(;k>=0;k--) if(matrix[k][j]=='0') break;
						height[j]=i-k;
					}
				}
			}
			res=max(res,largestRectangleArea(height));
		}
		return res;
    }
};

int main()
{
	Solution *s = new Solution();
	vector<vector<char> > matrix;
	char A[][6]={{'0','0','0','1','0','0'},
				 {'0','0','1','1','0','0'},
				 {'0','0','1','1','0','0'},
				 {'0','0','1','1','0','1'},
				 {'1','0','1','1','1','1'},
				 {'1','1','1','1','1','1'},
	};
	for(int i=0;i<6;i++)
	{
		vector<char> row(A[i],A[i]+sizeof(A[i])/sizeof(char));
		matrix.push_back(row);
	}
	cout<<s->maximalRectangle(matrix)<<endl;

	system("pause");
	return 0;
}