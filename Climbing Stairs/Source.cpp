// Climbing Stairs
//   Author: flashhack
//   Update: 2014-12-17
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
    int climbStairs(int n) {
        int a=1,b=1,c=0;
		n=n-1;
		if(n==0)return 1;
		int i=0;
		while(i<n)
		{
			i++;
			c=a+b;
			a=b;
			b=c;
		}
		return c;
    }
};

//2nd pass: 2015-03-04
class Solution {
public:
    int climbStairs(int n) {
        int a=1,b=1,c=0;
        if(n==0) return 1;
        for(int i=1;i<n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return b;
    }
};

int main()
{
	Solution *s = new Solution();
	cout << s->climbStairs(5) << endl;


	system("pause");
	return 0;
}