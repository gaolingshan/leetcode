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
class Solution_old {
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

//2nd pass: 2015-02-21
/*
f[i][j] S:1~i, T:1~j
f[0][j]=j;
f[i][0]=i;
f[i][j]=f[i-1][j-1]     S[i]==T[j]
        f[i-1][j-1]+1   S[i]!=T[j]
        f[i-1][j]     
        f[i][j-1]
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int lenS=word1.length(), lenT=word2.length();
        vector<vector<int>> f(lenS+1,vector<int>(lenT+1,0));
        for(int i=0;i<=lenS;i++)f[i][0]=i;
        for(int i=0;i<=lenT;i++)f[0][i]=i;
        for(int i=1;i<=lenS;i++)
            for(int j=1;j<=lenT;j++)
            {
                f[i][j]=min(f[i][j-1],f[i-1][j])+1;
                f[i][j]=min(f[i][j],f[i-1][j-1]+((word1[i-1]==word2[j-1])?0:1));
            }
        return f[lenS][lenT];
    }
};

int main()
{
	Solution *s = new Solution();
	cout<<s->minDistance("a","ab")<<endl;;

	system("pause");
	return 0;
}