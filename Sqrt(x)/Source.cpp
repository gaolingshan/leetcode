// Sqrt(x)
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
    int sqrt(int x) {
		int left=1,right=x/2+1,mid=0;
		long long tmp;
		while(left<=right)
		{
			mid=left+((right-left)>>1);
			tmp=mid;
			tmp*=mid;
			if(tmp==x)return mid;
			if(tmp>x)right=mid-1;
			if(tmp<x)left=mid+1;
		}
		return right;
    }
};

//2nd pass: 2015-02-07
class Solution_2nd {
public:
    int sqrt(int x) {
        int left=0,right=x;
        long long tmp,mid;
        while(left<=right)
        {
            mid=left+((right-left)>>1);
            tmp=mid*mid;
            if(tmp==x) return mid;
            if(tmp>x) right=mid-1;
            if(tmp<x) left=mid+1;
        }
        return right;
    }

	double eps = 1e-8;
	int dblcmp(double x){

		if (abs(x) < eps) return 0;
		return (x > eps) ? 1 : -1;
	}
	double sqrt(double x) {
		double left = 0, right = (dblcmp(x-1)>0)?x:1;
		double tmp, mid;
		while (dblcmp(left-right) <= 0)
		{
			mid = (left + right)/2;
			tmp = mid*mid;
			if (dblcmp(tmp-x) == 0) return mid;
			if (dblcmp(tmp-x)>0) right = mid - eps;
			if (dblcmp(tmp-x)<0) left = mid + eps;
		}
		return right;
	}
};

//3rd pass: 2015-03-22
/*
newton method solution for sqrt and cbrt:
check a==0(stable point, not gonna converge), then start at a
sqrt: x=(x+a/x)/2
cbrt: x=(a/x/x + 2x)/3
*/
class Solution {
public:
	double eps = 1e-8;
	int dblcmp(double x){
		if (abs(x) < eps) return 0;
		return (x > eps) ? 1 : -1;
	}
    double sqrt(double x) {
		if(dblcmp(x)==0) return 0;
		double ans=x, tmp=0;
		while(1){
			tmp=(ans+x/ans)/2;
			if(dblcmp(ans-tmp)==0)break;
			ans=tmp;
		}
		return ans;        
    }
	double cbrt(double x){
		if(dblcmp(x)==0) return 0;
		double ans=x, tmp=0;
		while(1){
			tmp=(x/ans/ans+2*ans)/3;
			if(dblcmp(ans-tmp)==0)break;
			ans=tmp;
		}
		return ans;
	}
};

int main()
{
	Solution *s = new Solution();
	//cout<<s->sqrt(2)<<endl;
	//cout<<s->sqrt(4)<<endl;
	//cout<<s->sqrt(2147483647)<<endl;
	cout << s->sqrt(64) << endl;
	//cout << s->cbrt(-64) << endl;

	system("pause");
	return 0;
}