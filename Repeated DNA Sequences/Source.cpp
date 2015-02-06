// Repeated DNA Sequences
//   Author: flashhack
//   Update: 2015-02-06
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
	int DNAToInt(string s)
	{
		int base=1, res=0;
		for(int i=0;i<10;i++)
		{
			int num=0;
			if(s[i]=='A') num=0;
			if(s[i]=='C') num=1;
			if(s[i]=='G') num=2;
			if(s[i]=='T') num=3;
			res+=num*base;
			base*=4;
		}
		return res;
	}
	string IntToDNA(int x)
	{
		int base=1;
		string res="";
		for(int i=0;i<10;i++)
		{
			int num=x%4;
			switch (num)
			{
			case 0:
				res+="A";
				break;
			case 1:
				res+="C";
				break;
			case 2:
				res+="G";
				break;
			case 3:
				res+="T";
				break;
			default:
				break;
			}
			x/=4;
		}
		return res;
	}
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int,int> visited;
        vector<string> res;
        if(s.length()<=10) return res;
		visited.clear();
		for(int i=0;i+10<=s.length();i++)
		{
			string str=s.substr(i,10);
			visited[DNAToInt(str)]++;
		}
		for(auto it:visited)
			if(it.second>1) res.push_back(IntToDNA(it.first));
        return res;
    }
};

int main()
{
	Solution *s = new Solution();
	//vector<string> res = s->findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCAAAAAGGGTTT");
	vector<string> res = s->findRepeatedDnaSequences("AAAAAAAAAAA");
	for(auto str:res)cout<<str<<endl;

	system("pause");
	return 0;
}