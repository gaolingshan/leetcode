// Search Insert Position
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
    int searchInsert(int A[], int n, int target) {
		int left=0,right=n-1,mid=0;
		while(left<right)
		{
			mid=left+((right-left)>>1);
			if(target<A[mid]) right=mid;
			else
			if(target==A[mid])return mid;
			else
				left=mid+1;
		}
		return target>A[left]?left+1:left;
    }
};


//2nd pass: 2015-02-07
class Solution_2nd {
public:
    int searchInsert(int A[], int n, int target) {
        int left=0,right=n-1,mid;
        while(left<right)
        {
            mid=left+((right-left)>>1);
            if(target==A[mid]) return mid;
            if(A[mid]>target) right=mid;
            if(A[mid]<target) left=mid+1;
        }
        if(target>A[left])return left+1; else return left;
    }
};

//3rd pass: 2015-02-18
class Solution_3rd {
public:
    int searchInsert(int A[], int n, int target) {
        int left=0,right=n-1,mid=0;
        while(left<right)
        {
            mid=left+((right-left)>>1);
            if(A[mid]==target) return mid;
            if(target<A[mid]) right=mid;
            else //if(target>A[mid])
                left=mid+1;
        }
        return (target>A[left])?left+1:left;
    }
};

//4th pass: 2015-03-23
/*
search_ceiling, but if found, return idx
left    mid     right
1. target==mid, just return
2. target < mid, right=mid
3. target > mid, left=mid+1
left<right
A[left]>=target?left:left+1
*/
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int left=0,right=n-1,mid;
        while(left<right){
            mid=left+((right-left)>>1);
            if(target==A[mid]) return mid;
            if(target<A[mid]) right=mid; else left=mid+1;
        }
        return (A[left]>=target)?left:left+1;
    }
};

int main()
{
	Solution *s = new Solution();	

	int A[] = {1,3,5,6};
	cout<< s->searchInsert(A,4,6) << endl;

	//int A[] = {1};
	//cout<< s->searchInsert(A,1,2) << endl;

	system("pause");
	return 0;
}