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
//4rd pass: 2015-03-22
/*
n: 101
loop until n==0
n$1 ans *= base
base *= base
n>>1

corner case: neg n over flow
*/
class Solution_int {
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

class Solution {
public:
    const double eps=1e-10;
    int dblcmp(double x){
        return (x>eps)?1:(x<-eps)?-1:0;
    }
	double exp(double x){
		double ans=0, factor=1, factorial=1;
		if(dblcmp(x)==0) return 1;
		for(int i=1;dblcmp(factor/factorial)!=0;++i){
			ans+=factor/factorial;
			factorial*=i;
			factor*=x;
		}
		return ans;
	}
    double log(double x){
        if(dblcmp(x)==0) return 1;
        if(dblcmp(x-1)>0) return log(x/exp(1.0))+1;
		// newton
		double ans=0, tmp=0;
		while(1){
			tmp=2 *(x-exp(ans))/(x+exp(ans));
			if(dblcmp(tmp)==0) break;
			ans = ans + tmp;
		}
        return ans;
    }
    double pow(double x, int n) {
		if(dblcmp(x)<0) return (n%2)?-exp(n*log(-x)):exp(n*log(-x));
        return exp(n*log(x));
    }
};

int main()
{
	Solution *s = new Solution();
	//cout<<s->pow(-5,2)<<endl;
	//cout<<s->pow(0.00001,2147483647)<<endl;
	cout<<s->pow(-1.00001,447125)<<endl;

	system("pause");
	return 0;
}