// Palindromic Substrings
//   Author: flashhack
//   Update: 2015-02-22
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

class Solution_BF {
public:
    long long extend(string &S, int l, int r)
    {
        if(l>r) return 0;
        long long ans=0;
        while(l>=0 && r<S.length() && S[l]==S[r]){l--;r++;ans++;}
        return ans;
    }
	long long countPalindromicSubstrings(string &S) {
        long long ans=0;
        for(int i=0;i<S.length();i++)
        {
            ans+=extend(S,i,i);
            ans+=extend(S,i,i+1);
        }
        return ans;
	}
};

class Solution {
public:
	long long countPalindromicSubstrings(string &S) {
		string s="$";
		for(char c:S)  s+="#"+string(1,c); s+="#";
		vector<int> p(s.length(),0);
		int mx=0,id=0;
		for (int i=1; i<s.length(); i++) {
			p[i] = mx > i ? min(p[2*id-i], mx-i) : 1;
			while (s[i + p[i]] == s[i - p[i]]) p[i]++;
			if (i + p[i] > mx) {
				mx = i + p[i];
				id = i;
			}
		}
        long long ans=0;
		for(int i=0;i<p.size();i++) ans+=p[i]/2;
		return ans;
	}
};

int main()
{
	Solution *s = new Solution();
	//string data="aaaa";
	//string data="aba";
	string data(1000,'a');
	cout<<s->countPalindromicSubstrings(data)<<endl;


	system("pause");
	return 0;
}