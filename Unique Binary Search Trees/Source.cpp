// Unique Binary Search Trees
//   Author: flashhack
//   Update: 2014-12-23
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
	int f[1000];
    int numTrees(int n) {
		f[0]=1;
		f[1]=1;
		for(int j=2;j<=n;j++)
			for(int i=1;i<=j;i++) f[j]+=f[i-1]*f[j-i];
		return f[n];
    }
};

int main()
{
	Solution *s = new Solution();
	cout<<s->numTrees(0)<<endl;

	system("pause");
	return 0;
}