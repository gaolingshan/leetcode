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

class Solution_old {
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


//2nd pass: 2015-02-07
class Solution_2nd {
public:
    int binarySearch(int A[], int left, int right, int target)
    {
        int mid;
        while(left<=right)
        {
            mid=left+((right-left)>>1);
            if(A[mid] == target) return mid;
            if(A[mid] > target) right=mid-1;
            if(A[mid] < target) left=mid+1;
        }
        if(target!=A[left]) return -1;
    }
    int search(int A[], int n, int target) {
        int left=0,right=n-1,mid;
        while(left+1<right)
        {
            if(A[left]<A[right]) return binarySearch(A,left,right,target);
            mid=left+((right-left)>>1);
            if(A[left]<A[mid])
            {
                if(A[left]<=target && target<=A[mid]) return binarySearch(A,left,mid,target); else left=mid+1;    
            }
            
            if(A[mid]<A[right])
            {
                if(A[mid]<=target && target<=A[right]) return binarySearch(A,mid,right,target); else right=mid-1;   
            }
        }
        return (A[left]==target)?left:(A[right]==target)?right:-1;
    }
};


//3rd pass: 2015-02-18

class Solution {
public:
    int search(int A[], int n, int target) {
        int left=0,right=n-1,mid=0;
        while(left<=right)
        {
            mid=left+((right-left)>>1);
            if(target==A[mid]) return mid;
            if(A[left]<=A[mid])
            {
                if(A[left]<=target && target<A[mid]) right=mid-1;
                else left=mid+1;
            }   
            else // 
            {
                if(A[mid]<target && target <= A[right]) left=mid+1;
                else right=mid-1;
            }
        }
        return -1;
    }
};

int main()
{
	Solution *s = new Solution();

	int A[] = {6,7,8,1,2,3,4,5};
	cout<< s->search(A,8,10) << endl;

	//int A[] = {3,1};
	//cout<< s->search(A,2,2) << endl;

	system("pause");
	return 0;
}