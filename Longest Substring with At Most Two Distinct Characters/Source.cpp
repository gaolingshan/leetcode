// Longest Substring with At Most Two Distinct Characters
//   Author: flashhack
//   Update: 2015-01-15
#include <iostream>
#include <sstream>
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
	unordered_map<char,int> table;
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left=0,right=0,ans=0;
		while(right<s.length())
		{
			table[s[right]]++;
			while(table.size()>2)
			{
				table[s[left]]--;
				if(table[s[left]]==0) table.erase(s[left]);
				left++;
			}
			ans=max(ans,right-left+1);
			right++;
		}
		return ans;
    }
};

int main()
{
	Solution *s = new Solution();
	cout<<s->lengthOfLongestSubstringTwoDistinct("abcabcabc")<<endl;

	system("pause");
	return 0;
}