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

class Solution_old {
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

//2nd pass: 2015-02-27
/*
aim: put num to index num-1
1. if A[i]==i+1, just next;
2. else need some swap
    A[i] need go to A[A[i]-1]
    A[i] must >=1 && <=n
    due to swap, A[i] must != destination, otherwise next;
3. traverse again found first A[i]!=i+1
4. corner case: if all interger are there, return n+1
[3 ,4,-1,1]
*/

class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		for (int i = 0; i<n;){
			if (A[i]==i+1) i++; else{
				if (A[i]>=1 && A[i]<=n && A[i]!=A[A[i]-1]) swap(A[i], A[A[i]-1]); else
					i++;
			}
		}
		for (int i=0;i<n;i++)
			if (A[i]!=i+1) return i+1;
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