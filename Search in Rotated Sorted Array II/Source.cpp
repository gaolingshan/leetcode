// Search in Rotated Sorted Array II
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
    bool search(int A[], int n, int target) {
        int left=0,right=n-1,mid=0;
		while(left<=right)
		{
			mid=left+((right-left)>>1);
			if(A[left]<A[right])
			{
				if(target<A[mid])right=mid-1;
				else
				if(target==A[mid])return true;
				else
				if(target>A[mid])left=mid+1;
			}
			else
			if(A[left]==A[right]) 
			{
				if(target==A[left]) return true;else left++;
			}
			else
			{
				if(A[left]==A[mid]) 
				{
					if(target==A[left]) return true;
					else left=mid+1;
				}
				else
				if(A[left]<A[mid])
				{
					if(target>A[mid]) left=mid+1;
					else
					if(target==A[mid]) return true;
					else
					if(target<A[mid]) 
					{
						if(target==A[left]) return true;
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
						if(target==A[right]) return true;
						else
						if(target>A[right]) right=mid-1;
						else
						if(target<A[right]) left=mid+1;
					}
					else
					if(target==A[mid]) return true;
					else
						right=mid-1;
				}
			}
		}
		return false;
    }
};


//2nd pass
/*
if duplicate
left    mid   right

left==right?
left==mid?
right==mid?

right side-- until not equal

*/
class Solution_2nd {
public:
    bool binarySearch(int A[], int left, int right, int target)
    {
        int mid;
        while(left<=right)
        {
            mid=left+((right-left)>>1);
            if(A[mid] == target) return true;
            if(A[mid] > target) right=mid-1;
            if(A[mid] < target) left=mid+1;
        }
        if(target!=A[left]) return false;
    }
    bool search(int A[], int n, int target) {
        int left=0,right=n-1,mid;
        while(left+1<right)
        {
            while(left<right && A[left]==A[right]) right--;
            if(A[left]<A[right]) return binarySearch(A,left,right,target);
            mid=left+((right-left)>>1);
            while(left<mid && A[left]==A[mid]) left++;
            if(A[left]<A[mid])
            {
                if(A[left]<=target && target<=A[mid]) return binarySearch(A,left,mid,target); else left=mid+1;    
            }
            
            while(right>mid && A[right]==A[mid])right--;
            if(A[mid]<A[right])
            {
                if(A[mid]<=target && target<=A[right]) return binarySearch(A,mid,right,target); else right=mid-1;   
            }
        }
        return (A[left]==target)?true:(A[right]==target)?true:false;
    }
};


//3rd pass: 2015-02-18
class Solution {
public:
    bool search(int A[], int n, int target) {
        int left=0,right=n-1,mid=0;
        while(left<=right)
        {
            mid=left+((right-left)>>1);
            if(A[mid]==target) return true;
            if(A[left]==A[mid]) left++;
            else
            if(A[left]<A[mid])
            {
                if(A[left]<=target && target<A[mid]) right=mid-1; 
                else left=mid+1;
            }
            else
            {
                if(A[mid]<target && target<=A[right]) left=mid+1;
                else right=mid-1;
            }
        }
        return false;
    }
};


int main()
{
	Solution *s = new Solution();

	int A[] = {0,0,1,1,2,0};
	cout<< s->search(A,6,0) << endl;

	system("pause");
	return 0;
}