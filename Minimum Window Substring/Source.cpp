// Minimum Window Substring
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

class Solution {
public:
    string minWindow(string S, string T) {
		int lenS=S.length(), lenT=T.length();
		if(lenT>lenS) return "";
		if(lenT==0) return "";

        int targetCnt[256],nowCnt[256];
		memset(targetCnt,0,sizeof(targetCnt));
		memset(nowCnt,0,sizeof(nowCnt));

		for(int i=0;i<lenT;i++) targetCnt[T[i]]++;
		int targetFrom,targetTo;
		for(targetFrom=0;targetFrom<256;targetFrom++) if(targetCnt[targetFrom]!=0)break;
		for(targetTo=255;targetTo>=0;targetTo--) if(targetCnt[targetTo]!=0)break;

		int res_left=0,res_right=0,res_len=INT_MAX;
		int left=0,right=0;
		nowCnt[S[0]]++;
		while(right<lenS)
		{
			bool flag=true;
			for(int i=targetFrom;i<=targetTo;i++)
				if(nowCnt[i]<targetCnt[i])
				{
					flag=false;
					break;
				}

			if(!flag) 
			{
				right++;
				nowCnt[S[right]]++;
			}
			else
			{
				if(right-left < res_len)
				{
					res_left=left;
					res_right=right;
					res_len=right-left;
				}
				nowCnt[S[left]]--;
				left++;
			}
		}
		if(res_len!=INT_MAX)
			return S.substr(res_left,res_right-res_left+1);
		else
			return "";
    }
};

int main()
{
	Solution *s = new Solution();
	//cout<<s->minWindow("ADOBECODEBANC","ABC")<<endl;
	//cout<<s->minWindow("AAAAABC","ABC")<<endl;
	cout<<s->minWindow("a","b")<<endl;


	system("pause");
	return 0;
}