// Find Peak Element
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
	
	int search(const vector<int> &num, int left, int right)
	{
		if(left>right) return -1;
		if(left==right) return left;
		if(left==right-1)
		{
			int ll=(left==0)?INT_MIN:num[left-1];
			int rr=(right==num.size()-1)?INT_MIN:num[right+1];
			if(num[left]>ll && num[left]>num[right]) return left;
			if(num[right]>num[left] && num[right]>rr) return right;
			return -1;
		}
		int mid=left+((right-left)>>1);
		if(mid>left && mid<right && num[mid-1]<num[mid] && num[mid+1]<num[mid]) return mid;
		if(mid>left && num[mid-1]>num[mid]) return search(num,left,mid-1);
		if(mid<right && num[mid+1]>num[mid]) return search(num,mid+1,right); 
	}
    int findPeakElement(const vector<int> &num) {
		return search(num,0,num.size()-1);
    }
};


//2nd pass: 2015-02-07
/*
left   mid   right
0. mid!=left && mid<mid-1, right=mid-1
1. mid!=right && mid<mid+1, left=mid+1
2. mid>mid-1||mid==left && mid>mid+1 || mid==right, mid is peak
*/
class Solution_2nd {
public:
    int findPeakElement(const vector<int> &num) {
        int left=0,right=num.size()-1,mid;
        while(left<=right)
        {
            mid=left+((right-left)>>1);
            if(mid!=left&&num[mid]<num[mid-1]) right=mid-1;
            else if(mid!=right&&num[mid]<num[mid+1]) left=mid+1;
            else if((mid==left||num[mid]>num[mid-1]) && (mid==right||num[mid]>num[mid+1])) return mid;
        }
        return left;
    }
};

//3rd pass: 2015-02-18
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int len=num.size();
        if(len==1) return 0;
        int left=0,right=len-1,mid=0;
        while(left<=right)
        {
            mid=left+((right-left)>>1);
            if((mid==0 || num[mid]>num[mid-1]) && (mid==len-1 || num[mid]>num[mid+1])) return mid;
            if(mid!=0 && num[mid-1]>num[mid]) right=mid-1;
			else left=mid+1;
			//if(mid!=len-1 && num[mid]<num[mid+1]) left=mid+1;
			//else right=mid-1;
        }
    }
};

int main()
{
	Solution *s = new Solution();
	//int A[]={1,2,3,1,2};
	int A[]={1,2,1,2,3,1};
	//int A[]={-2147483647,-2147483648};
	vector<int> data(A,A+sizeof(A)/sizeof(int));
	cout<<s->findPeakElement(data)<<endl;



	system("pause");
	return 0;
}