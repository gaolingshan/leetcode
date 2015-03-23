#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution_old {
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

//2nd pass: 2015-02-21
class Solution_2nd {
public:
    string longestPalindrome(string s) {
        int ans=0;
		string tmp="";
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j+i<s.length() && i-j>=0;j++)
                if(s[i+j]==s[i-j])
				{
					if(2*j+1>ans)
					{
						ans=2*j+1;
						tmp=s.substr(i+1,j);
						reverse(tmp.begin(),tmp.end());
						tmp+=s[i]+s.substr(i+1,j);
					}
				}
				else break;
            for(int j=0;i-j>=0 && i+1+j<s.length();j++)
                if(s[i-j]==s[i+1+j]) 
				{
					if(2*j+2>ans)
					{
						ans=2*j+2;
						tmp=s.substr(i+1,j+1);
						reverse(tmp.begin(),tmp.end());
						tmp+=s.substr(i+1,j+1);
					}
				}else break;
        }
        return tmp;
    }
};

//3rd pass: 2015-02-21
//4rd pass: 2015-03-22
/*
abba
abb
two kind of expand: i==j, i+1=j
traverse i:
do two expand, update max len
*/
class Solution {
public:
    string expand(string s, int l, int r)
    {
        while(l>=0 && r<s.length() && s[l]==s[r]) {l--;r++;}
        return s.substr(l+1,r-l-1);
    }
    string longestPalindrome(string s) {
		if(s.length()<=1) return s;
        string ans="",tmp="";
        for(int i=0;i<s.length()-1;i++)
        {
            tmp=expand(s,i,i);
            if(tmp.length()>ans.length()) ans=tmp;
            tmp=expand(s,i,i+1);
            if(tmp.length()>ans.length()) ans=tmp;
        }
        return ans;
    }
};

int main()
{
	Solution *s = new Solution();

	cout << s->longestPalindrome("abccba") << endl;
	//cout << s->longestPalindrome("a") << endl;
	system("pause");
	return 0;
}