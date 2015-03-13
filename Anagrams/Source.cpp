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

class Solution_1st {
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

//2nd pass: 2015-02-21
class Solution_2nd {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string,vector<int>> table;
        for(int i=0;i<strs.size();i++)
        {
            string str=strs[i];
            sort(str.begin(),str.end());
			table[str].push_back(i);
        }
        vector<string> res;
        for(auto it:table)
			if(it.second.size()>1)
				for(int i:it.second) res.push_back(strs[i]);
        return res;
    }
};

//3rd pass: 2015-03-13
/*
hashtable K:sorted str, V:occur idxs
1st sweep add
2nd sweep print
*/
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        unordered_map<string,vector<int>> table;
        for(int i=0;i<strs.size();++i){
            auto str=strs[i];
            sort(str.begin(),str.end());
            table[str].push_back(i);
        }
        for(auto it:table) if(it.second.size()>1) 
        for(int idx:it.second) res.push_back(strs[idx]);
        return res;
    }
};

int main()
{
	Solution *s = new Solution();
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
	string A[]={"rat","art","tar","facebook","bacefook","w"};
	vector<string> data, res;
	for(auto str:A) data.push_back(str);
	res=s->anagrams(data);
	for(auto str:res) cout<<str<<endl;

	system("pause");
	return 0;
}