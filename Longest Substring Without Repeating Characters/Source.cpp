#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
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

int main()
{
	string str = "abcabcbb";
	Solution *s = new Solution();
	cout << s->lengthOfLongestSubstring(str) << endl;
	system("pause");
	return 0;
}