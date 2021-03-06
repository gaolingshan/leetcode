// Best Time to Buy and Sell Stock III
//   Author: flashhack
//   Update: 2015-01-07
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

class Solution_old {
public:
    int maxProfit(vector<int> &prices) {
		int len=prices.size();
		if(len==0) return 0;
		int* f = new int[len];
		int* g = new int[len];
		int buyPrice=INT_MAX;
		for(int i=0;i<len;i++)
		{
			f[i]=(i>0)?f[i-1]:0;
			if(prices[i]<buyPrice) buyPrice=prices[i];
			f[i]=max(f[i],prices[i]-buyPrice);
		}
		int sellPrice=INT_MIN;
		for(int i=len-1;i>=0;i--)
		{
			g[i]=(i<(len-1))?g[i+1]:0;
			if(prices[i]>sellPrice) sellPrice=prices[i];
			g[i]=max(g[i],sellPrice-prices[i]);
		}
		int res=0;
		for(int i=0;i<len;i++) res=max(res,f[i]+g[i]);
		return res;
    }
};

//2nd pass: 2015-02-23
/*
f[i]: buy stock 1~i
	record min, update max profit
g[i]: sell stock n~i
	from n to i, record max, update max profit
ans=max(f[i]+g[i])
*/
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int len = prices.size();
		if (len <= 1) return 0;
		vector<int> f(len, 0), g(len, 0);
		int low = INT_MAX, high = 0, ans = 0;
		for (int i = 0; i<len; i++)
		{
			low = min(low, prices[i]);
			ans = max(ans, prices[i] - low);
			f[i] = ans;
		}
		ans = 0;
		for (int i = len - 1; i >= 0; i--)
		{
			high = max(high, prices[i]);
			ans = max(ans, high - prices[i]);
			g[i] = ans;
		}
		ans = 0;
		for (int i = 0; i<len; i++) ans = max(ans, f[i] + g[i]);
		return ans;
	}
};

int main()
{
	Solution *s = new Solution();
	int A[] = {1,2,1,4};
	vector<int> data(A,A+sizeof(A)/sizeof(int));
	cout<<s->maxProfit(data)<<endl;

	system("pause");
	return 0;
}