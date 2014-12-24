// Scramble String
//   Author: flashhack
//   Update: 2014-12-22
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

//with memorize 1012ms.. so slow
//w/o memorize only 72ms! so interesting. don't know why
class Solution {
public:
	//int f[100][100][100];
	string S1,S2;
	bool dfs(int i,int j, int len)
	{
		//if(f[i][j][len]!=-1) return f[i][j][len];
		if(len==1)
		{
			if(S1[i]==S2[j]) 
			{
				//f[i][j][len] = true;
				return true;
			}
			else
			{
				//f[i][j][len]=false;
				return false;
			}
		}
		string ss1=S1.substr(i,len);
		string ss2=S2.substr(j,len);
		if(ss1 == ss2)
		{
			//f[i][j][len]=true;
			return true;
		}
		sort(ss1.begin(),ss1.end());
		sort(ss2.begin(),ss2.end());
		if(ss1!=ss2)
		{
			//f[i][j][len]=false;
			return false;
		}

		int left1=i,right1=i+len-1;
		int left2=j,right2=j+len-1;
		bool flag = false;
		for(int k=left1;k<right1;k++)
		{
			bool tmp1_1 = dfs(left1,left2,k-left1+1);
			int new_left2 = left2+k+1-left1;
			bool tmp1_2 = dfs(k+1,new_left2,right1-k);
			bool tmp1 = tmp1_1 && tmp1_2;

			new_left2=right2+left1-k;
			bool tmp2_1 = dfs(left1,new_left2,k-left1+1);
			bool tmp2_2 = dfs(k+1,left2,right1-k);
			bool tmp2 = tmp2_1 && tmp2_2;
			flag |= tmp1||tmp2;
			if(flag) break;
		}
		//f[i][j][len]=flag;
		return flag;
	}

    bool isScramble(string s1, string s2) {
		int len1=s1.size();
		int len2=s2.size();
		if(len1!=len2) return false;
		if(len1==len2 && len1==0) return true;
        S1=s1;
		S2=s2;
		//memset(f,-1,sizeof(f));
		return dfs(0,0,len1);
    }
};

int main()
{
	Solution *s = new Solution();

	cout<<s->isScramble("great","rgtae")<<endl;
	cout<<s->isScramble("great","rgeat")<<endl;
	cout<<s->isScramble("great","reatg")<<endl;
	cout<<s->isScramble("great","tgrea")<<endl;

	cout<<"case from LC"<<endl;
	cout<<s->isScramble("abb","bab")<<endl;


	system("pause");
	return 0;
}