// Merge Sorted Array
//   Author: flashhack
//   Update: 2014-12-23
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
    void merge(int A[], int m, int B[], int n) {
        int i=m-1,j=n-1,k=m+n-1;
		while(1)
		{
			if(i>=0)
			{
				if(j>=0) 
				{
					A[k--]=(A[i]>B[j])?A[i--]:B[j--];
				}
				else
					A[k--]=A[i--];
			}
			else
			{
				if(j>=0)
					A[k--]=B[j--];
				else
					break;
			}
		}
    }
};

int main()
{
	Solution *s = new Solution();
	int A[]={1,2,3,4,0,0,0,0};
	int B[]={2,3,4,5};
	s->merge(A,0,B,4);
	for(int i=0;i<8;i++) cout<<A[i]<<" ";
	cout<<endl;


	system("pause");
	return 0;
}