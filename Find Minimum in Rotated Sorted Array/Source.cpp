// Find Minimum in Rotated Sorted Array
//   Author: flashhack
//   Update: 2015-01-13
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
	int search(vector<int> &num, int left, int right)
	{
		if(left > right) return INT_MAX;
		if(left == right) return num[left];	//trick here, must return, otherwise dead loop
		if(num[left]<num[right]) return num[left];
		int mid=left+((right-left)>>1);
		return min(search(num,left,mid),search(num,mid+1,right));
	}
    int findMin(vector<int> &num) {
		return search(num,0,num.size()-1);
    }
};



//2nd pass: 2015-02-07
/*
left < right   => sorted, return left
left   mid   right
left<mid   ->  left is smallest, do mid+1~right
mid<right  ->  mid is smallest, do left~mid-1
*/
class Solution_2nd {
public:
    int findMin(vector<int> &num) {
        int left=0,right=num.size()-1,mid;
        int ans=INT_MAX;
        while(left<=right)
        {
            if(num[left]<num[right])
            {
                ans=min(ans,num[left]);
                return ans;
            }
            mid=left+((right-left)>>1);
            if(num[left]<=num[mid])
            {
                ans=min(ans,num[left]);
                left=mid+1;
            }
			else
			if(num[mid]<num[right])
			{
                ans=min(ans,num[mid]);
                right=mid-1;
			}
        }
        return ans;
    }
};


//3rd pass: 2015-02-07
class Solution_3rd {
public:
    int search(vector<int> &num, int left,int right)
    {
        if(left>right) return INT_MAX;
        if(left==right) return num[left];
        if(left+1==right) return min(num[left],num[right]);
        if(num[left]<num[right]) return num[left];
        int mid=left+((right-left)>>1);
        if(num[left]<num[mid]) return min(num[left],search(num,mid+1,right));
        if(num[mid]<num[right]) return min(num[mid],search(num,left,mid-1));
    }
    int findMin(vector<int> &num) {
        return search(num,0,num.size()-1);
    }
};

//4th pass: 2015-02-18
class Solution_4th {
public:
    int findMin(vector<int> &num) {
        int ans = INT_MAX;
        int left=0, right=num.size()-1,mid=0;
        while(left<=right)
        {
            if(num[left]<=num[right])
            {
                ans=min(ans,num[left]);
                return ans;
            }
            mid = left + ((right-left)>>1);
            if(num[left]<=num[mid])
            {
                ans=min(ans,num[left]);
                left=mid+1;
            }
            else
            {
                ans=min(ans,num[mid]);
                right=mid-1;
            }
        }
        return ans;
    }
};

//5th pass: 2015-02-18
class Solution_5th {
public:
    int findMin(vector<int> &num) {
        int left=0,right=num.size()-1,mid=0;
        while(left+1<right)
        {
            mid=left+((right-left)>>1);
            if(num[mid]<num[right]) right=mid;
            else left=mid;
        }
        return (num[left]<num[right])?num[left]:num[right];
    }
};

//6th pass: 2015-03-22
/*
left    mid     right
A[mid]<A[right]-> right part sorted
1. right part sorted, min in left part(included mid)
right=mid
2. right part unsorted, min in right part
left=mid+1

left<right
*/
class Solution {
public:
    int findMin(vector<int> &num) {
        int left=0,right=num.size()-1,mid;
        while(left<right){
            mid=left+((right-left)>>1);
            if(num[mid]<num[right]) right=mid; else left=mid+1;
        }
        return num[left];
    }
};

int main()
{
	Solution *s = new Solution();
	//int A[]={2};
	//int A[]={2,1};
	//int A[]={0,1,2,4,5,6,7};
	//int A[]={4,5,6,7,0,1,2};
	int A[]={1,2,3};
	vector<int> data(A,A+sizeof(A)/sizeof(int));
	cout<<s->findMin(data)<<endl;

	system("pause");
	return 0;
}