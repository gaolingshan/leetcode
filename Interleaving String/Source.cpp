// Interleaving String
//   Author: flashhack
//   Update: 2014-12-24
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
	bool f[1010][1010];
    bool isInterleave(string s1, string s2, string s3) {
		int len1=s1.length();
		int len2=s2.length();
		int len3=s3.length();

		if(len1+len2 != len3) return false;
		if(len1==0) return s2==s3;
		if(len2==0) return s1==s3;
		memset(f,0,sizeof(f));
		for(int i=1;i<=len1;i++)
		{
			if(s1[i-1]==s3[i-1]) f[i][0]=true;
			else break;
		}
		for(int j=1;j<=len2;j++)
		{
			if(s2[j-1]==s3[j-1]) f[0][j]=true;
			else break;
		}
		for(int i=0;i<=len1;i++)
			for(int j=0;j<=len2;j++)
				if(f[i][j])
				{
					if(i<len1 && i+j<len3 && s1[i]==s3[i+j]) f[i+1][j]=f[i][j];
					if(j<len2 && i+j<len3 && s2[j]==s3[i+j]) f[i][j+1]=f[i][j];
				}
		return f[len1][len2];
    }
};

//2nd pass: 2015-02-26
/*
f[i][j]  s1:1~i, s2:1~j match s3:1~i+j
f[i][j] -> f[i+1][j]  s1[i+1]==s3[i+j+1]
f[i][j+1]  s2[j+1]==s3[i+j+1]

*/
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int len1 = s1.length(), len2 = s2.length();
		if (len1+len2 != s3.length()) return false;
		vector<vector<bool>> f(len1+1, vector<bool>(len2+1, false));
		f[0][0] = true;
		for (int i = 0; i<=len1; i++)
			for (int j = 0; j<=len2; j++) if (f[i][j]){
				if (i+1<=len1 && s1[i] == s3[i+j]) f[i+1][j] = true;
				if (j+1<=len2 && s2[j] == s3[i+j]) f[i][j+1] = true;
			}
		return f[len1][len2];
	}
};

int main()
{
	Solution *s = new Solution();
	cout<<s->isInterleave("aabcc","dbbca","aadbbcbcac")<<endl;
	cout<<s->isInterleave("aabcc","dbbca","aadbbbaccc")<<endl;


	system("pause");
	return 0;
}