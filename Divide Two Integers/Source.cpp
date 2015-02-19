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

class Solution_old {
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


//2nd pass: 2015-02-07
class Solution_2nd {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0) return INT_MAX;
        if(dividend==0) return 0;
        int signa=(dividend<0)?0:1;
        int signb=(divisor<0)?0:1;
        int sign=signa^signb;   //1 neg, 0 pos
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        if(a<b) return 0;
        long long res=0;
        long long count=1,c=b;
        while(a>=b)
        {
            if(a>=c)
            {
                a-=c;
                res+=count;
                count=count<<1;
                c+=c;
            }
            else
            {
                c=b;
                count=1;
            }
        }
        if(sign==1) return -res;
        if(sign==0) 
        {
            if(res>INT_MAX) return INT_MAX;
            return res;
        }
    }
};

//3rd pass: 2015-02-18
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0) return 0;
        if(divisor==0) return INT_MAX;
        bool isPositive = (dividend>0 && divisor>0) || (dividend<0 && divisor<0);
        long long a=abs((long long)dividend);
        long long b=abs((long long)divisor);
        int i=0; long long ans=0;
        while(a>=b)
        {
            b<<=1;
            i++;
        }
        while(i>=0)
        {
            if(a>=b)
            {
                ans+=(long long)1<<i;
                a-=b;
            }
            i--;
            b>>=1;
        }
		if(isPositive)
			return (ans>INT_MAX)?INT_MAX:ans;
		else
			return (-ans<INT_MIN)?INT_MAX:-ans;
    }
};

int main()
{
	Solution *s = new Solution();
	//cout<<s->divide(-2147483648,-1)<<endl;
	//cout<<s->divide(-2,1)<<endl;
	cout<<s->divide(1,1)<<endl;

	system("pause");
	return 0;
}