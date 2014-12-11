// Divide Two Integers
//   Author: flashhack
//   Update: 2014-12-11
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
    int divide(int dividend, int divisor) {
		long long a=abs((long long)dividend),b=abs((long long)divisor),c=1,d=b;
        long long result=0,sign=0;
		if(divisor==0) return INT_MAX;
		if(dividend==0) return 0;
		if(dividend>0) sign=(divisor>0)?1:-1;
		if(dividend<0) sign=(divisor>0)?-1:1;

		while(a>=b)
		{
			a -= d;
			result += c;
			if(a > d+d)
			{
				d += d;
				c += c;
			}
			else
			{
				d = b;
				c = 1;
			}
		}

		if(result * sign > INT_MAX || result * sign < INT_MIN) return INT_MAX;
		return result*sign;
    }
};

int main()
{
	Solution *s = new Solution();
	cout<<s->divide(-2147483648,-1)<<endl;

	system("pause");
	return 0;
}