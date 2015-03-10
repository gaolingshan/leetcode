// Longest Increasing Subsequence
//   Author: flashhack
//   Update: 2015-03-10
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

/*
0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15
2,5,3,1,2,3,4
4,2,4,4,5,3,7

2 3 4 5 7

1. aux array A[i], end element of length i+1
2. find A[i] just larger than num, 
	2.1 found A[i]=num
	2.2 not found append
ans=lenA
*/
class Solution {
public:
    vector<int> A;
    int searchCeiling(int num){
        int left=0,right=A.size()-1,mid=0;
        while(left<right){
            mid=left+((right-left)>>1);
            if(num<A[mid]) right=mid; else left=mid+1;
        }
        if(A[left]>num) return left; else return -1;
    }
    int longestIncreasingSubsequence(vector<int> nums) {
        if(nums.empty()) return 0;
		A.clear();
        A.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            int idx=searchCeiling(nums[i]);
            if(idx==-1) A.push_back(nums[i]); else A[idx]=nums[i];
        }
        return A.size();
    }
};

int main()
{
	Solution s;
	cout<<s.longestIncreasingSubsequence({5, 4, 1, 2, 3})<<endl;
	cout<<s.longestIncreasingSubsequence({4, 2, 4, 5, 3, 7})<<endl;

	system("pause");
	return 0;
}