// Remove Duplicates from Sorted Array II
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
    int removeDuplicates(int A[], int n) {
		if(n==0 || n==1) return n;
        bool isTwice=false;
		int left=0;
		for(int i=1;i<n;i++)
		{
			if(A[left] != A[i])
			{
				swap(A[i],A[++left]);
				isTwice=false;
			}
			else
			{
				if(!isTwice)
				{
					isTwice=true;
					swap(A[i],A[++left]);
				}
				else
					continue;
			}
		}
		return left+1;
    }
};

int main()
{
	Solution *s = new Solution();
	int A[] = {1,1,1,2,2,3};
	
	int len=s->removeDuplicates(A,6);

	for(int i=0;i<len;i++) cout<<A[i]<<" ";
	cout<<endl;


	system("pause");
	return 0;
}