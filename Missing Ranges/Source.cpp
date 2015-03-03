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

class Solution_old {
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

//2nd pass: 2015-02-05
class Solution_2nd {
public:
    vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
        vector<string> res;
        int i=0;
        for(int x=lower;x<=upper;x++)
        {
            if(i<n && x==A[i])
            {
                i++;
                continue;
            }
            if(i==n)
            {
                if(x<=upper)
                {
                    string tmp=(x==upper)?to_string(x):to_string(x)+"->"+to_string(upper);
                    res.push_back(tmp);
                }
                break;
            }
            if(x<A[i])
            {
                string tmp=(x==A[i]-1)?to_string(x):to_string(x)+"->"+to_string(A[i]-1);
                res.push_back(tmp);
                x=A[i]-1;
            }
        }
        return res;
    }
};

//3rd pass: 2015-02-27
class Solution {
public:
	vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
		int x = lower;
		vector<string> res;
		for (int i = 0; i <= n; i++){
			int num=(i==n)?upper+1:A[i];
			if (x==num) x++; else{
				if (x==num-1) res.push_back(to_string(x));
				else res.push_back(to_string(x) + "->"+to_string(num-1));
				x = num + 1;
			}
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