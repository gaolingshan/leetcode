#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	bool f[1000][1000];
	string longestPalindrome(string s) {
		int ansi=0,ansj=1,ans=1;
		int length = s.length();
		for(int len=0;len<length;len++)
			for(int i=0;i+len<length;i++)
			{
				if(len==0) 
				{
					f[i][i]=1;
					continue;
				}
				if(len==1 && s[i] == s[i+1])
				{
					f[i][i+1] = 1;
					ansi=i;
					ansj=2;
					ans=2;
					continue;
				}
				f[i][i+len] = 0;
				if(f[i+1][i+len-1] && s[i]==s[i+len]) 
				{
					f[i][i+len]=1;
					if(len+1>ans)
					{
						ans=len+1;
						ansi=i;
						ansj=len+1;
					}
				}
			}
		return s.substr(ansi,ansj);
	}
};

int main()
{
	Solution *s = new Solution();

	cout << s->longestPalindrome("abccba") << endl;
	system("pause");
	return 0;
}