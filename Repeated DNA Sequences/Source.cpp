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

class Solution_old {
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

//2nd pass: 2015-03-11
/*
A-00-0
C-01-1
G-10-2
T-11-3
20bits for a string
hash: 2^20 OK!
mask: 0xFFFFF
1 pass the string and add to table, when cnt==2 output
Time:O(n)
Space:O(2^20)
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int,int> table;
        vector<string> res;
        int val=0;
        for(int i=0;i<s.length();++i) {
            val<<=2;
            if(s[i]=='C') val|=1;
            if(s[i]=='G') val|=2;
            if(s[i]=='T') val|=3;
            val&=0xFFFFF;
            if(i>=9) table[val]++;
            if(table[val]==2) 
				res.push_back(s.substr(i-9,10));
        }
        return res;
    }
};

int main()
{
	Solution *s = new Solution();
	//vector<string> res = s->findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	vector<string> res = s->findRepeatedDnaSequences("AAAAAAAAAAA");
	for(auto str:res)cout<<str<<endl;

	system("pause");
	return 0;
}