// Palindrome Partitioning
//   Author: flashhack
//   Update: 2015-01-09
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
    bool isPalindrome(string s) {
		int len=s.length();
		if(len==0) return true;
		int left=0,right=len-1;
		while(left<right)
		{
			if(s[left++]!=s[right--]) return false;
		}
		return true;
    }

	void dfs(vector<vector<string>> &res, vector<string> &now, string &s, int i)
	{
		if(i==s.length())
		{
			res.push_back(now);
			return;
		}
		int j=0;
		while(i+j<s.length())
		{
			if(isPalindrome(s.substr(i,j+1)))
			{
				now.push_back(s.substr(i,j+1));
				dfs(res,now,s,i+j+1);
				now.pop_back();
			}
			j++;
		}
	}

    vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> now;
		dfs(res,now,s,0);
		return res;
    }
};

int main()
{
	Solution *s = new Solution();
	vector<vector<string>> res = s->partition("aab");
	for(auto it1:res)
	{
		for(auto it2:it1) cout<<it2<<",";
		cout<<endl;
	}
	system("pause");
	return 0;
}