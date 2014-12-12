// Longest Valid Parentheses
//   Author: flashhack
//   Update: 2014-12-12
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
		int i=0,j=0,ans=0;
		int len=s.size();
		for(j=0;j<len;j++)
		{
			if(s[j]=='(') 
				st.push(j);
			else
				if(!st.empty())
				{
					st.pop();
					ans=max(ans, st.empty()?j-i+1:j-st.top());
				}
				else
					i=j+1;		
		}
		return ans;
    }
};


int main()
{
	Solution *s = new Solution();

	cout<<s->longestValidParentheses("()(()()")<<endl;

	system("pause");
	return 0;
}