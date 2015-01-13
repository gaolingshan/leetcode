// Maximum Product Subarray
//   Author: flashhack
//   Update: 2015-01-12
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
    int maxProduct(int A[], int n) {
		if(n==0) return 0;
		if(n==1) return A[0];
		vector<int> data;
		int tmp=0;
		for(int i=0;i<n;i++)
		{
			if(A[i]<=0)
			{
				if(tmp>0)data.push_back(tmp);
				data.push_back(A[i]);
				tmp=0;
			}
			else
			{
				if(tmp==0)tmp=1;
				tmp*=A[i];
				if(i==n-1) data.push_back(tmp);
			}
		}
        
		tmp=1;
		int ans=INT_MIN;
		for(int i=0;i<data.size();i++)
		{
			tmp*=data[i];
			ans=max(ans,tmp);
			if(tmp==0) tmp=1;
		}
		tmp=1;
		for(int i=data.size()-1;i>=0;i--)
		{
			tmp*=data[i];
			ans=max(ans,tmp);
			if(tmp==0) tmp=1;
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