// Word Break II
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

class Solution {
public:
	unordered_map<int, vector<int>> table;

	void dfs(vector<string> &res, string &s, vector<string> &now, int pos)
	{
		if(pos==0) 
		{
			string tmp="";
			for(int i=now.size()-1;i>=0;i--)
				tmp+=now[i]+" ";
			res.push_back(tmp.substr(0,tmp.length()-1));
			return;
		}
		for(int start : table[pos])
		{
			now.push_back(s.substr(start,pos-start));
			dfs(res,s,now,start);
			now.pop_back();
		}
	}

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
		vector<string> res;

		int len = s.length();
		table[0]=vector<int>(1,-1);
		for(int i=0;i<len;i++)
			if(table.find(i)!=table.end())
			{
				for(string word:dict)
				{
					string tmp = s.substr(i,word.length());
					if(i+word.length()<=len && s.substr(i,word.length()) == word)
					{
						if(table.find(i+word.length())==table.end())
						{
							table[i+word.length()]=vector<int>(1,i);
						}
						else
						{
							table[i+word.length()].push_back(i);
						}
					}
				}
			}
		vector<string> now;
		dfs(res,s,now,len);
		return res;        
    }
};

int main()
{
	Solution *s = new Solution();
	string A[] = {"cat", "cats", "and", "sand", "dog"};
	unordered_set<string> dict;
	for(auto it:A) dict.insert(it);

	vector<string> res;
	res=s->wordBreak("catsanddog",dict);
	for(auto it:res)cout<<it<<endl;

	system("pause");
	return 0;
}