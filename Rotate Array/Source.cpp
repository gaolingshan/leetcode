// Rotate Array
//   Author: flashhack
//   Update: 2015-02-24
#include <iostream>
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
#include <stack>
using namespace std;

class Solution {
public:
	void reverse(int nums[], int n)
	{
		int left = 0, right = n - 1;
		while (left<right) swap(nums[left++], nums[right--]);
	}
	void rotate(int nums[], int n, int k) {
		if (n == 0) return;
		k %= n;
		reverse(nums, n);
		reverse(nums, k);
		reverse(nums + k, n - k);
	}
};

int main()
{
	//Solution *s = new Solution();

	system("pause");
	return 0;
}