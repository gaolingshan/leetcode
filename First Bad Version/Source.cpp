// First Bad Version
//   Author: flashhack
//   Update: 2015-02-23
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

class VersionControl {
public:
	static bool isBadVersion(int version);
};

class Solution {
public:
	int findFirstBadVersion(int n) {
		int left = 1, right = n, mid = 0;
		while (left<right)
		{
			mid = left + ((right - left) >> 1);
			if (VersionControl::isBadVersion(mid)) right = mid;
			else left = mid + 1;
		}
		return left;
	}
};

int main()
{
	//Solution *s = new Solution();

	system("pause");
	return 0;
}