// <filename>.<ext>
//   Author: <name>
//   Update: <date>
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
    int maxArea(vector<int> &height) {
		int left=0,right=height.size()-1,ans=0;
		while(left<right)
		{
			ans = max(ans, min(height[left],height[right])*(right-left));
			if(height[left]<=height[right]) left++; else right--;
		}
		return ans;
    }
};

int main()
{
	Solution *s = new Solution();

	int A[] = {1,3,5,6};
	vector<int> heights(A,A+sizeof(A)/sizeof(int));
	
	cout<< s->maxArea(heights) << endl;

	system("pause");
	return 0;
}