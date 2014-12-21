// Edit Distance
//   Author: flashhack
//   Update: 2014-12-21
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

//DP with rotating array
class Solution {
public:
    int minDistance(string word1, string word2) {
		int Alen=word1.length();
		int Blen=word2.length();
		if(Alen==0)return Blen;
		if(Blen==0)return Alen;
		vector<int> f(Blen+1,0);
		vector<int> g(Blen+1,0);
		for(int i=0;i<=Blen;i++) f[i]=i;
		for(int i=1;i<=Alen;i++)
		{
			g[0]=i;
			for(int j=1;j<=Blen;j++)
			{
				if(word1[i-1]==word2[j-1])
					g[j]=f[j-1];
				else
				{
					g[j]=min(g[j-1]+1,f[j]+1);
					g[j]=min(g[j],f[j-1]+1);
				}
			}
			f=g;
		}
		return f[Blen];
    }
};

int main()
{
	Solution *s = new Solution();
	cout<<s->minDistance("a","b")<<endl;;

	system("pause");
	return 0;
}