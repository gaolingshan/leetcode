// Best Time to Buy and Sell Stock II
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
		int len=prices.size();
		if(len==0)return 0;
		int buyPrice=prices[0],res=0,tmp=0;
		for(int i=1;i<prices.size();i++)
		{
			if(prices[i]<prices[i-1]) 
			{
				res+=tmp;
				buyPrice=prices[i];
				tmp=0;
			}
			tmp=prices[i]-buyPrice;
		}
		return res+tmp;
    }
};

int main()
{
	Solution *s = new Solution();
	int A[] = {1,4,2};
	vector<int> data(A,A+sizeof(A)/sizeof(int));
	cout<<s->maxProfit(data)<<endl;


	system("pause");
	return 0;
}