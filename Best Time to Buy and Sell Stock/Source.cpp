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

class Solution {
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

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}