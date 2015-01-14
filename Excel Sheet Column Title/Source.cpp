// Excel Sheet Column Title
//   Author: flashhack
//   Update: 2015-01-14
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
    string convertToTitle(int n) {
		string res;
		while(n!=0)
		{
			res+='A'+(n-1)%26;
			n=(n-1)/26;
		}
		reverse(res.begin(),res.end());
		return res;
    }
};

int main()
{
	Solution *s = new Solution();
	cout<<s->convertToTitle(53)<<endl;

	system("pause");
	return 0;
}