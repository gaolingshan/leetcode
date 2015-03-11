// Factorial Trailing Zeroes
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

class Solution_old {
public:
    int trailingZeroes(int n) {
        int base=5,ans=0;
		while(n>=base)
		{
			ans+=n/base;
			if(base<INT_MAX/5) base*=5; else break;
		}
		return ans;
    }
};

/*
2*5=10, 5 fewer than 2, count multiples of 5s
5, 25, 625 ...
*/
class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        long long base=5;
        while(n>=base){
            ans+=n/base;
            base*=5;
        }
        return ans;
    }
};

int main()
{
	Solution *s = new Solution();
	cout<<s->trailingZeroes(5)<<endl;


	system("pause");
	return 0;
}