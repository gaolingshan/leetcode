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
class Solution_old2 {
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


//2nd pass: 2015-02-04
class Solution_2nd {
public:
    int largestRectangleArea(vector<int> &height) {
        vector<int> st;
        height.push_back(0);
        int ans=0;
        for(int i=0;i<height.size();i++)
        {
            if(st.empty() || height[i]>height[st.back()])
            {
                st.push_back(i);
                continue;
            }
			//problem here. the area is
			int tmp;
			while(!st.empty())
            {
                if(height[i]>height[st.back()])break;
				tmp=st.back();
				st.pop_back();
				int start=(st.empty())?0:st.back()+1;
                ans = max(ans, height[tmp] * (i-start));
            }
            st.push_back(i);
        }
        return ans;
    }
};

//3rd pass: 2015-02-27
/*
[2,1,5,6,2,3]
   .
  ..
  ..
  .. .
. ....
......

keep non-desending (<=) order in the stack
1. stack==empty || new number >= stack top, just push. else
2.    height=stack top, pop stack,
len = stack.top()+1(or 0 if stack empty) ~ i-1, area = height*len
keep pop stack if stack is not empty && new height < stack top
3. finally push i into stack

*/
class Solution_3rd {
public:
	int largestRectangleArea(vector<int> &height) {
		stack<int> st;
		int ans = 0;
		height.push_back(0);
		for (int i = 0; i<height.size(); i++){
			if (st.empty() || height[i] >= height[st.top()]) st.push(i); else{
				do{
					int h = height[st.top()];
					st.pop();
					int len = i - (st.empty() ? 0 : st.top() + 1);
					ans = max(ans, len*h);
				} while (!st.empty() && height[i] < height[st.top()]);
				st.push(i);
			}
		}
		return ans;
	}
};

//4th pass: 2015-03-23
/*
use stack, maintain increasing(>)
traverse i:
1. st.emtpy || height[i]>height[st.top], just push
2. while(!st.empty && h[i] <= h[st.top]) keep poping
    2.1 h=st.top, pop st
    2.2 area = st.empty?0:st.top+1 ~ i-1  *   h
3. finally push i
*/
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        stack<int> st;
        int ans=0;
        for(int i=0;i<height.size();++i){
            if(st.empty() || height[i]>height[st.top()]) st.push(i); else{
                while(!st.empty() && height[i]<=height[st.top()]){
                    int h=height[st.top()]; st.pop();
                    ans=max(ans,(i-(st.empty()?0:st.top()+1))*h);
                }
                st.push(i);
            }
        }
        return ans;
    }
};

int main()
{
	Solution *s = new Solution();
	int A[] = {2,1,5,6,2,3};
	//int A[] = {2,1,2};
	vector<int> data(A,A+sizeof(A)/sizeof(int));

	cout<<s->largestRectangleArea(data)<<endl;

	system("pause");
	return 0;
}