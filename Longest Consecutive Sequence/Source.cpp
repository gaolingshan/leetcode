// Longest Consecutive Sequence
//   Author: flashhack
//   Update: 2015-01-09
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
	unordered_set<int> visited;

    int longestConsecutive(vector<int> &num) {
		for(int i=0;i<num.size();i++) visited.insert(num[i]);
		int left=0,right=0,ans=0;
		for(int i=0;i<num.size();i++)
			if(visited.find(num[i]) != visited.end())
			{
				left=num[i];
				right=num[i];
				while(visited.find(left-1) != visited.end())
				{
					left--;
					visited.erase(left);
				}
				while(visited.find(right+1) != visited.end())
				{
					right++;
					visited.erase(right);
				}
				ans=max(ans,right-left+1);
			}
		return ans;
    }
};

int main()
{
	Solution *s = new Solution();
	int A[]={100, 4, 200, 1, 3, 2};
	vector<int> data(A,A+sizeof(A)/sizeof(int));
	cout<<s->longestConsecutive(data)<<endl;


	system("pause");
	return 0;
}