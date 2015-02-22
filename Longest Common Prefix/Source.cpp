// Longest Common Prefix
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
    string longestCommonPrefix(vector<string> &strs) {
        string res="";
		int len=0;
		if(strs.size()==0)return "";
		if(strs.size()==1)return strs[0];
		while(1)
		{
			int i=0;
			for(i=0;i<strs.size();i++)
			{
				if(i+1<strs.size())
				{
					if(len>=strs[i].length()) break;
					if(len>=strs[i+1].length()) break;
					if(strs[i][len] != strs[i+1][len]) break;
				}
			}
			if(i!=strs.size()) break;
			else
			{
				res+=strs[i-1][len];
				len++;
			}
		}
		return res;
    }
};

//2nd pass: 2015-02-21
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
		if(strs.size()==0) return "";
        string res="";
        int i=0;
        while(1)
        {
            char c=0;
            for(string str:strs)
            {
                if(str.length()<=i) return res;
                if(c==0) c=str[i]; else if(c!=str[i]) return res;
            }
            res+=c;
			i++;
        }
        return res;
    }
};

int main()
{
	Solution *s = new Solution();

	string data[] = {"abc","abc","ab","a"};
	vector<string> input(data,data+sizeof(data)/sizeof(string));

	cout<<s->longestCommonPrefix(input)<<endl;

	system("pause");
	return 0;
}