// Best Time to Buy and Sell Stock
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
		int buyPrice=INT_MAX;
		int res = 0;
		for(int i=0;i<prices.size();i++)
		{
			if(prices[i]<buyPrice) buyPrice=prices[i];
			res=max(res,prices[i]-buyPrice);
		}
		return res;
    }
};

//2nd pass: 2015-02-23
/*
record min, buy at there, update max profit
Time: O(n)
Space: O(1)
*/
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int ans = 0, minBuyPrice = INT_MAX;
		for (int i = 0; i<prices.size(); i++)
		{
			minBuyPrice = min(minBuyPrice, prices[i]);
			ans = max(ans, prices[i] - minBuyPrice);
		}
		return ans;
	}
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}