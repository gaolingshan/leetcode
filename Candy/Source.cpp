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
using namespace std;

class Solution {
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

int main()
{
	Solution *s = new Solution();


	system("pause");
	return 0;
}