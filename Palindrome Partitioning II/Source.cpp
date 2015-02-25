// Palindrome Partitioning II
//   Author: flashhack
//   Update: 2015-01-09
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
	int f[1500];
	bool p[1500][1500];
    int minCut(string s) {
		int lenS=s.length();
		if(lenS<=1) return 0;

		for(int i=0;i<lenS;i++) p[i][i]=true;
		for(int len=2;len<=lenS;len++)
			for(int i=0;i+len-1<lenS;i++)
			{
				int j=i+len-1;
				if(s[i]==s[j]) p[i][j]=(i+1<lenS && j-1>=0 && i+1<=j-1)?p[i+1][j-1]:true;
				else p[i][j]=false;
			}

		for(int i=lenS-2;i>=0;i--)
		{
			int tmp=INT_MAX;
			for(int j=i;j<lenS;j++)
			{
				if(p[i][j])
					tmp=min(tmp,(j+1<lenS)?f[j+1]+1:0);
			}
			f[i]=tmp;
		}

		return f[0];
    }
};

//2nd pass: 2015-02-25
class Solution {
public:
	int minCut(string s) {
		int lenS = s.length();
		vector<int> f(lenS + 1, 0);
		for (int i = 0; i <= lenS; i++) f[i] = i - 1;
		for (int i = 1; i <= lenS; i++){
			for (int len = 0; i + len <= lenS && i - len - 1 >= 0 && s[i + len - 1] == s[i - len - 1]; len++)
				f[i + len] = min(f[i + len], f[i - len - 1] + 1);
			for (int len = 0; i + len + 1 <= lenS && i - len - 1 >= 0 && s[i + len] == s[i - len - 1]; len++)
				f[i + len + 1] = min(f[i + len + 1], f[i - len - 1] + 1);
		}
		return f[lenS];
	}
};

int main()
{
	Solution *s = new Solution();
	cout<<s->minCut("aab")<<endl;
	//cout<<s->minCut("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")<<endl;


	system("pause");
	return 0;
}