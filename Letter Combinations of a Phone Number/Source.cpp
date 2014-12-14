// Letter Combinations of a Phone Number
//   Author: flashhack
//   Update: 2014-12-13
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
    vector<string> res;
	vector<string> letters;
	
	void dfs(int i,vector<string> &res,string &digits, string &now)
	{
		if(i==digits.length())
		{
			res.push_back(now);
			return;
		}
		int digit=digits[i]-'0';
		for(int j=0;j<letters[digit].length();j++)
		{
			now+=letters[digit][j];
			dfs(i+1,res,digits,now);
			now.pop_back();
		}
	}
	vector<string> letterCombinations(string digits) {
		string list[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		for(int i=0;i<10;i++) letters.push_back(list[i]);
		vector<string> res;
		string now="";
		dfs(0,res,digits,now);
		return res;
    }
};

int main()
{
	Solution *s = new Solution();

	vector<string> res = s->letterCombinations("909");
	for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
	cout<<endl;

	system("pause");
	return 0;
}