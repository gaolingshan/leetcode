// Sort Colors
//   Author: flashhack
//   Update: 2014-12-21
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
    void sortColors(int A[], int n) {
		if(n==0 || n==1)return;
        int pt_0=-1,pt_1=-1,pt_2=0;
		int i=0;
		for(i=0;i<n;i++)if(A[i]!=0)break;	//ignore all prescedent 0s
		pt_0=i-1;
		pt_1=i-1;
		pt_2=i;
		while(pt_2<n)
		{
			while(A[pt_2] != 2)
			{
				if(A[pt_2]==0)
				{
					if(pt_0==pt_2)break;
					swap(A[++pt_0],A[pt_2]);	
					if(pt_1<pt_0)pt_1=pt_0;	//pt_1 must >= pt_0
					continue;
				}
				if(A[pt_2]==1)
				{
					if(pt_1==pt_2) break;
					swap(A[++pt_1],A[pt_2]);
					continue;
				}
			}
			pt_2++;
		}
    }
};

int main()
{
	Solution *s = new Solution();

	//int A[] = {0,1,0,1,0,1};
	int A[] = {2,0,1,1,2,0};
	int n=6;
	s->sortColors(A,n);

	for(int i=0;i<n;i++) cout<<A[i]<<" ";
	cout<<endl;


	system("pause");
	return 0;
}