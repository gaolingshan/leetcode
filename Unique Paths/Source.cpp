// Unique Paths
//   Author: flashhack
//   Update: 2014-12-16
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
    int uniquePaths(int m, int n) {
		vector<int> f;
		if(m==0 || n==0) return 0;
		for(int i=0;i<n;i++) f.push_back(1);
		for(int i=1;i<m;i++)
			for(int j=1;j<n;j++)
				f[j]=f[j]+f[j-1];
		return f[n-1];
    }
};

int main()
{
	Solution *s = new Solution();

	cout<<s->uniquePaths(2,2)<<endl;


	system("pause");
	return 0;
}