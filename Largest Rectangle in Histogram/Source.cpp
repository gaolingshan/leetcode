// Largest Rectangle in Histogram
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


//longer code 92ms
class Solution_old {
public:
    int largestRectangleArea(vector<int> &height) {
        vector<int> st;
		int res=0;
		height.insert(height.begin(),0);
		height.push_back(0);
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
				while(!st.empty())
				{
					//trick here. real horizontal distance is after pop+1~top, height is still before pop, so record h 
					h = height[st.back()];
					st.pop_back();
					res=max(res,h * (top - st.back()));
					if(height[st.back()] <= height[i]) break;
				}
				st.push_back(i);
			}
		}
		return res;
    }
};


//refracting code. code shorter but got 104ms..
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        vector<int> st;
		int res=0;
		height.push_back(0);
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
};

int main()
{
	Solution *s = new Solution();
	//int A[] = {2,1,5,6,2,3};
	int A[] = {2,1,2};
	vector<int> data(A,A+sizeof(A)/sizeof(int));

	cout<<s->largestRectangleArea(data)<<endl;

	system("pause");
	return 0;
}