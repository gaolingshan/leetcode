// Two Sum II - Input array is sorted
//   Author: flashhack
//   Update: 2015-01-15
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
	int search(vector<int> &num,int left, int right, int target)	//search the index of just <= target
	{
		while(left+1<right)
		{
			int mid=left+((right-left)>>1);
			if(target==num[mid]) return mid;
			if(target>num[mid]) left=mid;
			else right=mid-1;
		}
		return (num[right]<=target)?right:left;
	}
	int search2(vector<int> &num,int left, int right, int target)	//search the index of just >= target
	{
		while(left<right)
		{
			int mid=left+((right-left)>>1);
			if(target==num[mid]) return mid;
			if(target>num[mid]) left=mid+1;
			else right=mid;
		}
		return left;
	}
    vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> res;
		int left=0,right=numbers.size()-1;
		while(1)
		{
			if(numbers[left]+numbers[right]==target)
			{
				res.push_back(left+1);
				res.push_back(right+1);
				return res;
			}
			if(numbers[left]+numbers[right]>target)
				right=search(numbers,left,right,target-numbers[left]);
			else
				left=search2(numbers,left,right,target-numbers[right]);
		}
    }
};

int main()
{
	Solution *s = new Solution();
	//int A[]={2,7,11,15};
	//int A[]={2,3,4,6,8};
	//int A[]={1,2,3,4,4,9,56,90};
	int A[]={12,13,23,28,43,44,59,60,61,68,70,86,88,92,124,125,136,168,173,173,180,199,212,221,227,230,277,282,306,314,316,321,325,328,336,337,363,365,368,370,370,371,375,384,387,394,400,404,414,422,422,427,430,435,457,493,506,527,531,538,541,546,568,583,585,587,650,652,677,691,730,737,740,751,755,764,778,783,785,789,794,803,809,815,847,858,863,863,874,887,896,916,920,926,927,930,933,957,981,997};
	vector<int>data(A,A+sizeof(A)/sizeof(int));
	//vector<int> res=s->twoSum(data,8);
	vector<int> res=s->twoSum(data,542);
	for(int it:res) cout<<it<<" ";
	cout<<endl;


	system("pause");
	return 0;
}