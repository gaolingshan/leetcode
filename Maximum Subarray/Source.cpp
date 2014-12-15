// Maximum Subarray
//   Author: flashhack
//   Update: 2014-12-14
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

//sweep solution
class Solution_Sweep {
public:
		//int left[100000];
		//int right[100000];

	int maxSubArray(int A[], int n) {
		int res=INT_MIN;
		int* left = new int[n];
		int* right = new int[n];

		//note: start from n-1
		for(int i=n-1;i>=0;i--)
		{
			right[i]=INT_MIN;
			if(i+1<n && right[i+1]>0) 
				right[i]=A[i]+right[i+1];
			else
				right[i]=A[i];
		}
		for(int i=0;i<n;i++)
		{
			left[i]=INT_MIN;
			if(i-1>=0 && left[i-1]>0)
				left[i]=A[i]+left[i-1];
			else
				left[i]=A[i];
		}

		for(int i=0;i<n;i++)
		{
			// note: three possible situations need to count. to include left/right or not to include, that's a problem
			res=max(res,A[i]);
			if(i-1>=0) res=max(res,A[i]+left[i-1]);
			if(i+1<n) res=max(res,A[i]+right[i+1]);
			if(i-1>=0 && i+1<n) res=max(res,A[i]+left[i-1]+right[i+1]);
		}
        return res;
    }
};

//devide and conqure solution, so slow 80ms. O(nlogn) actually
class Solution {
public:
	int dfs(int A[], int L, int R)
	{
		if(L>R) return INT_MIN;
		int mid=L+((R-L)>>1);
		int res=INT_MIN;
		res=max(res,dfs(A,L,mid-1));
		res=max(res,dfs(A,mid+1,R));
		res=max(res,A[mid]);
		int left=INT_MIN,right=INT_MIN,tmp=0;
		for(int i=mid-1;i>=L;i--)
		{
			tmp+=A[i];
			left=max(left,tmp);
		}
		tmp=0;
		//note: here use i<=R, R is inclusive. 
		//Unlike binary search, n is total data num. right=n-1 is inclusive.
		for(int i=mid+1;i<=R;i++)
		{
			tmp+=A[i];
			right=max(right,tmp);
		}
		if(left!=INT_MIN) res=max(res,A[mid]+left);
		if(right!=INT_MIN)res=max(res,A[mid]+right);
		if(left!=INT_MIN&&right!=INT_MIN)res=max(res,A[mid]+left+right);
		return res;
	}

	int maxSubArray(int A[], int n) {
		return dfs(A,0,n-1);
    }
};


int main()
{
	Solution *s = new Solution();
	//int A[] = {-2,1,-3,4,-1,2,1,-5,4};
	int A[] = {1,2};
	cout<<s->maxSubArray(A,2)<<endl;


	system("pause");
	return 0;
}