// First Missing Positive
//   Author: flashhack
//   Update: 2014-12-13
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
    int firstMissingPositive(int A[], int n) {
		if(n==0) return 1;
        for(int i=0;i<n;i++)
		{
			while(A[i]>=1 && A[i]<=n)
			{
				if(i!=A[i]-1)
				{
					swap(A[i],A[A[i]-1]);
					if(A[i]==A[A[i]-1]) break;
				}
				else
					break;
			}
		}
		for(int i=0;i<n;i++)
			if(A[i]!=i+1) return i+1;
		return n+1;
    }
};

int main()
{
	Solution *s = new Solution();

	int A[] = {1,1};
	cout<<s->firstMissingPositive(A,2)<<endl;


	system("pause");
	return 0;
}