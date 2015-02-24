// Word Break
//   Author: flashhack
//   Update: 2015-01-11
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
	bool f[10240];
    bool wordBreak(string s, unordered_set<string> &dict) {
		int len = s.length();
        f[0]=true;
		for(int i=0;i<len;i++)
			if(f[i])
			{
				for(string word:dict)
				{
					string tmp = s.substr(i,word.length());
					if(i+word.length()<=len && s.substr(i,word.length()) == word)
						f[i+word.length()]=true;
				}
			}
		return f[len];
    }
};

//2nd pass: 2015-02-23
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		vector<bool> f(s.length()+1, 0);
		f[0] = true;
		for (int i = 0; i < s.length(); i++) if (f[i])
		{
			for (auto word : dict)
			{
				if (i + word.length() > s.length()) continue;
				string tmp = s.substr(i, word.length());
				if (tmp == word) f[i + word.length()] = true;
			}
		}
		return f[s.length()];
	}
};

int main()
{
	Solution *s = new Solution();
	string A[] = {"leet","code"};
	unordered_set<string> dict;
	for(auto it:A) dict.insert(it);

	cout<<s->wordBreak("leetcode",dict)<<endl;

	system("pause");
	return 0;
}