// Pascal's Triangle II
//   Author: flashhack
//   Update: 2015-01-06
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
    vector<int> getRow(int rowIndex) {
		rowIndex+=1;
		vector<int> now,prev;
		now.push_back(1);
		if(rowIndex==0) return now;
		prev=now;
		for(int i=1;i<rowIndex;i++)
		{
			now.clear();
			for(int j=0;j<=i;j++)
			{
				int a = (j-1>=0)?prev[j-1]:0;
				int b = (j<=i-1)?prev[j]:0;
				now.push_back(a+b);
			}
			prev=now;
		}
		return now;
    }
};

int main()
{
	Solution *s = new Solution();
	vector<int> res = s->getRow(24);
	for(auto it : res) cout<<it<<" ";
	cout<<endl;


	system("pause");
	return 0;
}