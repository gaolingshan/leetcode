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

class Solution {
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

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}