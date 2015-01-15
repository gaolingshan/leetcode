// Missing Ranges
//   Author: flashahck
//   Update: 2015-01-15
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
    vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
		vector<string> res;
        int i=0, next;
		for(int num=lower;num<=upper;num++)
		{
			if(i<n)next=A[i]; else next=upper+1;
			if(num==next)
			{
				i++;
				continue;
			}
			//from num to next-1 missing
			if(num==next-1)
				res.push_back(to_string(num));
			else
				res.push_back(to_string(num)+"->"+to_string(next-1));
			num=next;
			i++;
		}
		return res;
    }
};

int main()
{
	Solution *s = new Solution();
	int A[]={0, 1, 3, 50, 75};
	//vector<string> res=s->findMissingRanges(A,1,-1,0);
	//vector<string> res=s->findMissingRanges(A,1,-2,-1);
	vector<string> res=s->findMissingRanges(A,5,0,99);
	//vector<string> res=s->findMissingRanges(NULL,0,-1,0);
	for(auto it:res) cout<<it<<endl;

	system("pause");
	return 0;
}