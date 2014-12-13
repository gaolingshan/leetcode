// Search for a Range
//   Author: <name>
//   Update: <date>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:

    vector<int> searchRange(int A[], int n, int target) {
		int left=0,right=n-1,mid=0;
		int first=0,last=0;
		//find first
		while(left<right)
		{
			mid=left+((right-left)>>1);
			if(target<=A[mid])right=mid; else left=mid+1;
		}
		first = (left==right)?(A[left]==target?left:-1):-1;
		//find last
		left=0;right=n-1;
		while(left+1<right)
		{
			mid=left+((right-left)>>1);
			if(target<A[mid])right=mid-1;else left=mid;
		}
		if(left+1==right) last = A[right]==target?right:(A[left]==target?left:-1);
		if(left==right) last = A[left]==target?left:-1;
		vector<int> res;
		res.push_back(first);
		res.push_back(last);
		return res;
    }
};

int main()
{
	Solution *s = new Solution();

	int A[] = {5,7,7,8,8,10};
	vector<int> res = s->searchRange(A,6,10);
	for(int i=0;i<res.size();i++)
		cout << res[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}