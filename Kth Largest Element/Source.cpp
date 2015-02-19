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
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
     int findKth(vector<int> &nums, int L, int R, int k)
     {
         if(L==R) return nums[L];
         
         int left=L,right=R,i=L;
         int pivot=nums[L+((R-L)>>1)];
         while(i<=right)
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
        // write your code here
        return findKth(nums,0,nums.size()-1,nums.size()-k+1);
    }
};


int main()
{
	//int A[]={9,3,2,4,8};
	int A[]={1,2,3,4,5,6,8,9,10,7};
	vector<int> data(A,A+sizeof(A)/sizeof(int));
	Solution *s = new Solution();
	cout<<s->kthLargestElement(1,data)<<endl;


	system("pause");
	return 0;
}