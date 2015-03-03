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

class Solution_old {
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

//2nd pass: 2015-02-27
/*
maintain minVal and maxVal ending at this index so far, while updaing ans with maxVal

new num A[i]
maxVal = max(A[i],A[i]*maxVal_prev,minVal*A[i]);
minVal = min(A[i],A[i]*maxVal_prev,minVal*A[i]);
*/
class Solution {
public:
    int maxProduct(int A[], int n) {
        int minVal=A[0],maxVal=A[0],ans=A[0];
        for(int i=1;i<n;i++){
            int maxVal_prev=maxVal;
            maxVal=max(minVal*A[i],max(A[i],maxVal_prev*A[i]));
            minVal=min(A[i],min(A[i]*maxVal_prev,minVal*A[i]));
            ans=max(ans,maxVal);
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