#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution_old {
public:
	map<char,int> hashtable;
	int lengthOfLongestSubstring(string s) {
		int start=0, now=0;
		int maxlen=0;
		while(now < s.length())
		{
			if(hashtable.find(s[now]) == hashtable.end())
			{
				hashtable[s[now]]=now;
				
			}else
			{
				if(hashtable[s[now]]+1 > start)
					start = hashtable[s[now]]+1;
				hashtable[s[now]]=now;
			}
			if(now-start+1 > maxlen) maxlen = now-start+1;
			now++;
		}
		return maxlen;
	}
};

//2nd pass: 2015-02-21
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> table;
        int len=s.length();
        if(len==0) return 0;
        table[s[0]]=0;
        int ans=1,j=0;
        for(int i=1;i<s.length();i++)
        {
            if(table.count(s[i]))
			{
				for(int k=j;k<table[s[i]];k++) table.erase(s[k]);    
				j=table[s[i]]+1;
			}
			table[s[i]]=i;
            if(i-j+1>ans) ans=i-j+1;
        }
        return ans;
    }
};

int main()
{
	//string str = "abcabcbb";
	string str = "bbbbb";
	Solution *s = new Solution();
	cout << s->lengthOfLongestSubstring(str) << endl;
	system("pause");
	return 0;
}