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

class Solution_old {
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

//2nd pass: 2015-03-10
class Solution {
public:
	/*
	len_s must >= 4 && <= 12
	
	dfs
	1. 0 -> 1digits other-> 3digits. i+j<=len_s
	2. num <= 255
	i==len_s && now_len == 4 find!
	*/
    void dfs(vector<string> &res, int i,vector<int>& now, string &s){
		if(now.size() > 4) return;
        if(i==s.length() && now.size()==4){
            string tmp="";
            for(int v:now) tmp+=to_string(v)+".";
            tmp.pop_back();
            res.push_back(tmp);
            return;
        }
        int len=(s[i]=='0')?1:3;
        for(int j=1;j<=len && i+j<=s.length();j++){
            string tmp=s.substr(i,j);
            int num=stoi(tmp);
            if(num<=255){
                now.push_back(num);
                dfs(res,i+j,now,s);
                now.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.length()<4 || s.length()>12) return res;
        vector<int> now;
        dfs(res,0,now,s);
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