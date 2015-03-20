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

to remember all the intermediate sequnce:
2. find A[i] just larger than num, 
	2.1 found A[i]=num
		2.1.1 i==0, just update num
		2.1.2 copy A[i-1] to A[i], append num // this is a must!! cannot just update
	2.2 not found append
		append last sequence, append num
ans=lenA
*/
class Solution {
public:
    vector<int> A;
	vector<vector<int>> res;
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
		res.clear();
		res.push_back({nums[0]});
		A.clear();
        A.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            int idx=searchCeiling(nums[i]);
			if(idx==-1) {
				A.push_back(nums[i]);
				res.push_back(res.back());
				res.back().push_back(nums[i]);
			} else {
				A[idx]=nums[i];
				if(idx!=0) res[idx]=res[idx-1];
				if(idx!=0) res[idx].push_back(nums[i]); else res[idx].front()=nums[i];
			}
        }
        return A.size();
    }
};

int main()
{
	Solution s;
	cout<<s.longestIncreasingSubsequence({5, 4, 1, 2, 3})<<endl;
	for(auto v:s.res) {
		for(int num:v) cout<<num<<" ";
		cout<<endl;
	}
	cout<<endl;
	cout<<s.longestIncreasingSubsequence({4, 2, 4, 5, 3, 7})<<endl;
	for(auto v:s.res) {
		for(int num:v) cout<<num<<" ";
		cout<<endl;
	}
	cout<<endl;
	cout<<s.longestIncreasingSubsequence({0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15})<<endl;
	for(auto v:s.res) {
		for(int num:v) cout<<num<<" ";
		cout<<endl;
	}
	cout<<endl;
	system("pause");
	return 0;
}