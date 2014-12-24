// Restore IP Addresses
//   Author: flashhack
//   Update: 2014-12-23
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
	void dfs(vector<string> &res, string &now,int pos, int left, string &s)
	{
		if(pos==s.length()) return;
		if(left==0)
		{
			if(s.length()-pos>3) return;
			int len=s.length()-pos;
			int num = atoi(s.substr(pos).c_str());
			if(len==2 && num<10) return;
			if(len==3 && num<100) return;
			if(num<=255)
				res.push_back(now+s.substr(pos));
			else
				return;
		}
		string tmp=now;
		int num=0;
		//1
		now+=s.substr(pos,1)+".";
		dfs(res,now,pos+1,left-1,s);
		now=tmp;
		//2
		if(pos+1<s.length())
		{
			num=atoi(s.substr(pos,2).c_str());
			if(num>=10)
			{
				now+=s.substr(pos,2)+".";
				dfs(res,now,pos+2,left-1,s);
				now=tmp;			
			}
		}
		//3
		if(pos+2<s.length())
		{
			int num=atoi(s.substr(pos,3).c_str());
			if(num>=100 && num<=255)
			{
				now+=s.substr(pos,3)+".";
				dfs(res,now,pos+3,left-1,s);
				now=tmp;
			}
		}
	}
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
		if(s.length()<4 || s.length()>12) res;
		string now="";
		dfs(res,now,0,3,s);
		return res;
    }
};

int main()
{
	Solution *s = new Solution();
	//vector<string> res = s->restoreIpAddresses("25525511135");
	//vector<string> res = s->restoreIpAddresses("0000");
	vector<string> res = s->restoreIpAddresses("010010");
	for(auto it:res) cout<<it<<endl;


	system("pause");
	return 0;
}