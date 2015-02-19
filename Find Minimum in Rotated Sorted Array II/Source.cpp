// Find Minimum in Rotated Sorted Array II
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
		while(left<right && num[left]==num[right]) left++;
		if(num[left]<num[right]) return num[left];
		int mid=left+((right-left)>>1);
		return min(search(num,left,mid),search(num,mid+1,right));
	}
    int findMin(vector<int> &num) {
		return search(num,0,num.size()-1);
    }
};

//2nd pass: 2015-02-07
class Solution_2nd {
public:
    int search(vector<int> &num, int left,int right)
    {
        if(left>right) return INT_MAX;
        if(left==right) return num[left];
        if(left+1==right) return min(num[left],num[right]);
        while(left<right && num[left]==num[right]) right--;
        if(num[left]<num[right]) return num[left];
        int mid=left+((right-left)>>1);
        while(left<mid && num[left]==num[mid]) left++;
        if(num[left]<num[mid]) return min(num[left],search(num,mid+1,right));
        while(mid<right && num[mid]==num[right]) right--;
        if(num[mid]<num[right]) return min(num[mid],search(num,left,mid-1));
		return search(num,left,right);
    }
    int findMin(vector<int> &num) {
        return search(num,0,num.size()-1);
    }
};

//3rd pass: 2015-02-18
class Solution_3rd {
public:
    int findMin(vector<int> &num) {
        int ans=INT_MAX;
        int left=0,right=num.size()-1,mid=0;
        while(left<=right)
        {
            if(num[left]==num[right])
            {
                ans=min(ans,num[right]);
                right--;
                continue;
            }
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
            {
                ans=min(ans,num[mid]);
                right=mid-1;
            }
        }
        return ans;
    }
};

//4th pass: 2015-02-18
class Solution {
public:
    int findMin(vector<int> &num) {
        int left=0,right=num.size()-1,mid=0;
        while(left+1<right)
        {
            mid=left+((right-left)>>1);
			if(num[mid]==num[right])
			{
				right--;
				continue;
			}
            if(num[mid]<num[right]) right=mid;
            else left=mid;
        }
        return (num[left]<num[right])?num[left]:num[right];
    }
};

int main()
{
	Solution *s = new Solution();
	int A[]={4,5,6,7,0,1,2};
	//int A[]={3,1,1,1,2,2};
	//int A[]={3,1,1};
	//int A[]={2,0,1,1,1};
	vector<int> data(A,A+sizeof(A)/sizeof(int));
	cout<<s->findMin(data)<<endl;

	system("pause");
	return 0;
}