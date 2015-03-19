// Kth Largest Element
//   Author: flashhack
//   Update: 2015-02-06
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
     int findKth(vector<int> &nums, int L, int R, int k)
     {
         if(L==R) return nums[L];
         
         int left=L,right=R,i=L;
         int pivot=nums[L+((R-L)>>1)];
         while(i<=right) //Dijkstra Partition
		 {
             if(nums[i]<pivot) 
				 swap(nums[i++],nums[left++]);
			 else if(nums[i]==pivot) i++;
			 else swap(nums[i],nums[right--]);
		 }
         int len=left-L+1;
         if(len==k) return nums[left];
         if(k<len) return findKth(nums,L,left-1,k);
         else return findKth(nums,left+1,R,k-len);
     }
    int kthLargestElement(int k, vector<int> nums) {
        return findKth(nums,0,nums.size()-1,nums.size()-k+1);
    }
};

/*
follow up: top 2 largest element
a: 1st large, b: 2nd large
1. num < 2nd large, pass
2. num > 2nd large
	2.1 num > 1st large: 2nd large=1st large, 1st large =num
	2.2 just update 2nd large;
*/
pair<int,int> find2nd(vector<int> &num){
	int a=INT_MIN,b=INT_MIN;
	for(int v:num){
		if(v>b)
			if(v>a){b=a; a=v;} else b=v;
	}
	return make_pair(a,b);
}


int main()
{
	//int A[]={9,3,2,4,8};
	int A[]={1,2,3,4,5,6,8,9,10,7};
	vector<int> data(A,A+sizeof(A)/sizeof(int));
	Solution *s = new Solution();
	//cout<<s->kthLargestElement(1,data)<<endl;

	auto p=find2nd(data);
	cout<<p.first<<" "<<p.second<<endl;

	system("pause");
	return 0;
}