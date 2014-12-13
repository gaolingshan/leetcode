// Search in Rotated Sorted Array
//   Author: flashhack
//   Update: 2014-12-12
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
    int search(int A[], int n, int target) {
        int left=0,right=n-1,mid=0;
		while(left<=right)
		{
			mid=left+((right-left)>>1);
			if(A[left]<A[right])
			{
				if(target<A[mid])right=mid-1;
				else
				if(target==A[mid])return mid;
				else
				if(target>A[mid])left=mid+1;
			}
			else
			if(A[left]==A[right]) return (target==A[left]?left:-1);
			else
			{
				if(A[left]==A[mid]) return (target==A[left]?left:(target==A[right]?right:-1));
				else
				if(A[left]<A[mid])
				{
					if(target>A[mid]) left=mid+1;
					else
					if(target==A[mid]) return mid;
					else
					if(target<A[mid]) 
					{
						if(target==A[left]) return left;
						else
						if(target>A[left]) {left=left+1;right=mid-1;}
						else
						if(target<A[left]) left=mid+1;
					}
				}
				else
				{
					if(target>A[mid])
					{
						if(target==A[right]) return right;
						else
						if(target>A[right]) right=mid-1;
						else
						if(target<A[right]) left=mid+1;
					}
					else
					if(target==A[mid]) return mid;
					else
						right=mid-1;
				}
			}
		}
		return -1;
    }
};

int main()
{
	Solution *s = new Solution();

	int A[] = {6,7,8,1,2,3,4,5};
	cout<< s->search(A,8,6) << endl;

	system("pause");
	return 0;
}