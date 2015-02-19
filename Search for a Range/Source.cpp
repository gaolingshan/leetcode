// Search for a Range
//   Author: <name>
//   Update: <date>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

class Solution_old {
public:

    vector<int> searchRange(int A[], int n, int target) {
		int left=0,right=n-1,mid=0;
		int first=0,last=0;
		//find first
		while(left<right)
		{
			mid=left+((right-left)>>1);
			if(target<=A[mid])right=mid; else left=mid+1;
		}
		first = (left==right)?(A[left]==target?left:-1):-1;
		//find last
		left=0;right=n-1;
		while(left+1<right)
		{
			mid=left+((right-left)>>1);
			if(target<A[mid])right=mid-1;else left=mid;
		}
		if(left+1==right) last = A[right]==target?right:(A[left]==target?left:-1);
		if(left==right) last = A[left]==target?left:-1;
		vector<int> res;
		res.push_back(first);
		res.push_back(last);
		return res;
    }
};


//2nd pass: 2015-02-07
/*
1st. find just smaller than target, check+1
2nd. find just larger than target, check-1

*/
class Solution_2nd {
public:
    int binarySearch1(int A[],int left, int right, int target)
    {
        int mid;
        while(left+1<right)
        {
            mid=left+((right-left)>>1);
            if(A[mid]>=target) right=mid-1;
            if(A[mid]<target) left=mid;
        }
        return (A[right]<target)?right:(A[left])<target?left:-1;
    }
    int binarySearch2(int A[],int left,int right,int target)
    {
        int mid;
        while(left<right)
        {
            mid=left+((right-left)>>1);
            if(A[mid]<=target)left=mid+1;
            if(A[mid]>target)right=mid;
        }
        return (A[left]>target)?left:-1;
    }
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2,-1);
        if(n==0) res;
        res.clear();
        int left=binarySearch1(A,0,n-1,target);
        int right=binarySearch2(A,0,n-1,target);
        if(left==-1) left=(A[0]==target)?0:-1;
		else
        if(left==n-1) left=-1;
		else
			left=(A[left+1]==target)?left+1:-1;

        if(right==-1) right=(A[n-1]==target)?n-1:-1;
		else
        if(right==0) right=-1;
		else
			right=(A[right-1]==target)?right-1:-1;
        res.push_back(left);
        res.push_back(right);
		return res;
    }
};

//3rd pass: 2015-02-18
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int left=0,right=n-1,mid=0;
        //search 1st occur
        while(left<right)
        {
            mid=left+((right-left)>>1);
            if(target<=A[mid]) right=mid;
            else left=mid+1;
        }
        int idx1=(A[left]==target)?left:-1;
        left=0; right=n-1;
        //search last occur
        while(left+1<right)
        {
            mid=left+((right-left)>>1);
            if(target<A[mid]) right=mid-1;
            else left=mid;
        }
        int idx2=(A[right]==target)?right:(A[left]==target)?left:-1;
        vector<int> res;
        res.push_back(idx1);
        res.push_back(idx2);
		return res;
    }
};

int main()
{
	Solution *s = new Solution();

	int A[] = {5,7,7,8,8,10};
	vector<int> res = s->searchRange(A,6,5);
	for(int i=0;i<res.size();i++)
		cout << res[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}