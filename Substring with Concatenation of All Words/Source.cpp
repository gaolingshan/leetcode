// Substring with Concatenation of All Words
//   Author: flashhack
//   Update: 2014-12-11
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

//1734ms
class Solution_BruteForce {
public:
	unordered_map<string,int> dictionary;
    vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> result;
		if(L.size()==0)
			return result;
		int word_length = L[0].length();
		int target_length = L.size() * L[0].length();
		for(int i=0;i<L.size();i++)
			dictionary[L[i]]++;
		int tmp = S.length();
		unordered_map<string,int> count;
		int cur=0;
		for(int now=0;now<tmp-target_length+1;now++)
		{
			count.clear();
			cur = now;
			while(cur < now + target_length)
			{
				string test_str = S.substr(cur,word_length);
				if(dictionary.find(test_str) != dictionary.end())
				{
					count[test_str]++;
					if(count[test_str] > dictionary[test_str]) break;
				}
				else
					break;
				cur+=word_length;
			}
			if(cur == now+target_length) result.push_back(now);
		}
		return result;
    }
};

//168ms! -> 148ms!
class Solution {
public:
	unordered_map<string,int> dictionary;
    vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> result;
		if(L.size()==0)
			return result;
		int word_length = L[0].length();
		int target_length = L.size() * L[0].length();
		for(int i=0;i<L.size();i++)
			dictionary[L[i]]++;
		int tmp = S.length();
		unordered_map<string,int> count;

		for(int startpoint=0;startpoint<word_length;startpoint++)
		{
			int left = startpoint, right = startpoint;
			count.clear();
			while(right<tmp-word_length+1)
			{
				string str=S.substr(right,word_length);
				if(dictionary.find(str) != dictionary.end())
				{
					count[str]++;
					while(count[str] > dictionary[str])
					{
						string str2 = S.substr(left,word_length);
						count[str2]--;
						left+=word_length;
					}
					right += word_length;
				}
				else
				{
					count.clear();
					right += word_length;
					left = right;
				}
				if(right-left == target_length) result.push_back(left);
			}
		}

		return result;
    }
};

int main()
{
	Solution *s = new Solution();

	string S = "barfoothefoobarman";
	vector<string> L;
	L.push_back("foo");
	L.push_back("bar");
	//L.push_back("b");

	vector<int> res = s->findSubstring(S,L);
	
	for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
	cout<<endl;

	system("pause");
	return 0;
}