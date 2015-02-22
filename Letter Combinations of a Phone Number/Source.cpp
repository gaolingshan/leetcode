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

class Solution_old {
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

//2nd pass: 2015-02-21
class Solution {
public:
    unordered_map<char,string> letters;
    void dfs(vector<string>&res,string now,string digits)
    {
        if(digits=="")
        {
            res.push_back(now);
            return;
        }
        for(char c:letters[digits[0]]) dfs(res,now+c,digits.substr(1,digits.length()-1));
    }
    vector<string> letterCombinations(string digits) {
        letters['2']="abc"; letters['3']="def"; letters['4']="ghi"; letters['5']="jkl";
        letters['6']="mno"; letters['7']="pqrs"; letters['8']="tuv"; letters['9']="wxyz";
		letters['0']=" "; letters['1']="";
        vector<string> res;
        dfs(res,"",digits);
		return res;
    }
};

int main()
{
	Solution *s = new Solution();

	vector<string> res = s->letterCombinations("929");
	for(int i=0;i<res.size();i++) cout<<res[i]<<endl;
	cout<<endl;

	system("pause");
	return 0;
}