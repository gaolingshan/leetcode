// Anagrams
//   Author: flashhack
//   Update: 2014-12-14
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

class Solution {
public:
	unordered_map<string,int> hashtable;
    vector<string> anagrams(vector<string> &strs) {
		vector<string> result;
		for(int i=0;i<strs.size();i++)
		{
			string tmp=strs[i];
			sort(tmp.begin(),tmp.end());
			if(hashtable.find(tmp)!=hashtable.end())
			{
				if(hashtable[tmp]!=-1) 
				{
					result.push_back(strs[hashtable[tmp]]);
					hashtable[tmp]=-1;
				}
				result.push_back(strs[i]);
			}else
				hashtable[tmp]=i;
		}

		return result;
    }
};

int main()
{
	//Solution *s = new Solution();
	/*
	dan,adn
	·µ»Ødan,adn
	"",""
	·µ»Ø"",""
	c,c
	·µ»Øc,c
	*
	*
	*/

	system("pause");
	return 0;
}