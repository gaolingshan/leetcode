// Candy
//   Author: flashhack
//   Update: 2015-01-09
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
#include <numeric>
using namespace std;

class Solution_old {
public:
    int candy(vector<int> &ratings) {
		int len=ratings.size();
		if(len==0) return 0;
		int *left = new int[len];
		int *right= new int[len];
		left[0]=1;
		right[len-1]=1;
		for(int i=1;i<len;i++)
		{
			left[i]=(ratings[i]>ratings[i-1])?left[i-1]+1:1;
		}
		for(int i=len-2;i>=0;i--)
		{
			right[i]=(ratings[i]>ratings[i+1])?right[i+1]+1:1;
		}
		int res=0;
		for(int i=0;i<len;i++)
		{
			res+=max(left[i],right[i]);
		}
		return res;
    }
};

//2nd pass: 2015-03-11
/*
1 2 5 4 3 2 1
1 2 3 1 1 1 1
1 2 5 4 3 2 1
1. from left to right, if rate[i]>rate[i-1], num[i]=num[i-1]+1;
2. from right to left, if rate[i]>rate[i+1], num[i]=max(num[i],num[i+1]+1);
*/
class Solution {
public:
    int candy(vector<int> &ratings) {
        int n=ratings.size();
        if(n==0) return 0;
        vector<int> num(n,1);
        for(int i=1;i<n;++i) if(ratings[i]>ratings[i-1]) num[i]=num[i-1]+1;
        for(int i=n-2;i>=0;--i) if(ratings[i]>ratings[i+1]) num[i]=max(num[i],num[i+1]+1);
        return accumulate(num.begin(), num.end(), 0);
    }
};

int main()
{
	Solution *s = new Solution();


	system("pause");
	return 0;
}