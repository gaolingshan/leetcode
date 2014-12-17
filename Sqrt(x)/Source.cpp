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

class Solution {
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

int main()
{
	Solution *s = new Solution();
	cout<<s->sqrt(4)<<endl;
	cout<<s->sqrt(2147483647)<<endl;


	system("pause");
	return 0;
}