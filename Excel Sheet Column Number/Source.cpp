// Excel Sheet Column Number
//   Author: flashhack
//   Update: 2015-01-14
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
    int titleToNumber(string s) {
		reverse(s.begin(),s.end());
		int res=0,base=1;
		for(char c:s)
		{
			res+=(c-'A'+1)*base;
			base*=26;
		}
		return res;
    }
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}