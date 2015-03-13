// Median
//   Author: flashhack
//   Update: 2015-03-12
#include <iostream>
#include <functional>
#include <bitset>
#include <chrono>
#include <exception>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

class Solution {
public:
    int quickselect(vector<int> &nums, int begin, int end, int k){
        int i=begin,l=begin,r=end, pivot=nums[begin+((end-begin)>>1)];
        while(i<=r){
            if(nums[i]<pivot) swap(nums[i++],nums[l++]); else
            if(nums[i]==pivot)++i;else swap(nums[i],nums[r--]);
        }
        int len=l-begin+1;
        if(len==k) return nums[l];
        if(len>k) return quickselect(nums,begin,l-1,k);else
        return quickselect(nums,l+1,end,k-len);
    }
    int median(vector<int> &nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n%2) return quickselect(nums,0,n-1,n/2+1); else
        return quickselect(nums,0,n-1,n/2);
    }
};



int main()
{


	system("pause");
	return 0;
}