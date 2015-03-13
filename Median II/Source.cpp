// Median II
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

/*
min max heap
min heap keep nums > median
max heap keep nums < median
size of max heap >= size of min heap

1. num >= top min heap, put in min heap
   num <= top max heap, put in max heap
2. adjust heap
2.1 size min > size max: pop min, push max
2.2 size max > size min + 1: pop max, push min
3. median=top of max heap
*/
class Solution_old {
public:
    vector<int> medianII(vector<int> &nums) {
        priority_queue<int,vector<int>> maxHeap;
        priority_queue<int,vector<int>,greater<int>> minHeap;
        vector<int> res;
        for(int num:nums){
            if(maxHeap.empty() || num<=maxHeap.top()) maxHeap.push(num); else minHeap.push(num);
            if(minHeap.size() > maxHeap.size()){
                int val=minHeap.top();
                minHeap.pop();
                maxHeap.push(val);
            }
            if(maxHeap.size() > minHeap.size()+1){
                int val=maxHeap.top();
                maxHeap.pop();
                minHeap.push(val);
            }
            res.push_back(maxHeap.top());
        }
        return res;
    }
};


/*
Time:O(n^2)
Space:O(1)
new num come in, median can only shift to neighbor!
maintain, low_cnt,low,high_cnt,high,equal_cnt
    [low_cnt,low_cnt+equal_cnt-1]
                (n-1)/2
low             unchange             high
*/
class Solution {
public:
    vector<int> medianII(vector<int> &nums) {
        if(nums.empty()) return {};
        vector<int> res(1,nums[0]);
        int low,low_cnt,high,high_cnt,equal_cnt,n=nums.size();
        for(int i=1;i<n;++i){
            low=INT_MIN; low_cnt=0; high=INT_MAX; high_cnt=0; equal_cnt=0;
            for(int j=0;j<=i;j++){
                if(nums[j]>res[i-1]){
                    ++high_cnt;
                    high=min(high,nums[j]);
                }else
                if(nums[j]<res[i-1]){
                    ++low_cnt;
                    low=max(low,nums[j]);
                }else
                    ++equal_cnt;
            }
            if(i/2 < low_cnt) res.push_back(low);else
            if(i/2 >= low_cnt+equal_cnt) res.push_back(high);else
            res.push_back(res[i-1]);
        }
        return res;
    }
};



int main()
{


	system("pause");
	return 0;
}