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

class Solution {
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

int main()
{
	Solution *s = new Solution();
	cout<<s->pow(2,2)<<endl;

	system("pause");
	return 0;
}