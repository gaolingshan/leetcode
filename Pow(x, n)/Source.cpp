// <filename>.<ext>
//   Author: <name>
//   Update: <date>
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
    double pow(double x, int n) {
        double res=1,tmp=x;
		int tmpn=abs(n);
		while(tmpn>0)
		{
			if(tmpn%2)res*=tmp;
			tmp*=tmp;
			tmpn>>=1;
		}
		if(n<0) return (double)1/res; else
		return res;
    }
};

//2nd pass
class Solution_2nd {
public:
    double pow(double x, int n) {
        bool needReverse=false;
        if(n<0) needReverse=true;
        long long nn=abs((long long)n);
        double res=1, m=x;
        while(nn)
        {
            if(nn%2)res*=m;
            m*=m;
            nn>>=1;
        }
        if(needReverse) return 1/res; else
        return res;
    }
};

//3rd pass: 2015-02-18
class Solution {
public:
    double pow(double x, int n) {
        long long nn=abs((long long)n);
        double m=x,res=1;
        while(nn)
        {
            if(nn%2) res*=m;
            m*=m;
            nn>>=1;
        }
        return (n>0)?res:1/res;
    }
};

int main()
{
	Solution *s = new Solution();
	cout<<s->pow(2,0)<<endl;

	system("pause");
	return 0;
}