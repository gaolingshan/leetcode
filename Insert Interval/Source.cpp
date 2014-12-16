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

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	struct cmp_struct
	{
		bool operator()(const Interval & a, const Interval & b)
		{
			return a.start<b.start;
		}
	}cmp_object;
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		intervals.push_back(newInterval);
		sort(intervals.begin(),intervals.end(),cmp_object);
		//tricky: intervals may start(0,0)
		int start=-1,end=-1;
		vector<Interval> res;
		if(intervals.size()==0)return res;
		for(int i=0;i<intervals.size();i++)
		{
			if(intervals[i].start > end)
			{
				if(start!=-1) res.push_back(Interval(start,end));
				start=intervals[i].start;
				end=intervals[i].end;
			}
			else
			{
				end=max(end,intervals[i].end);
			}
		}
		res.push_back(Interval(start,end));
		return res;        
    }
};

int main()
{
	Solution *s = new Solution();
	vector<Interval> intervals,res;
	intervals.push_back(Interval(1,3));
	intervals.push_back(Interval(6,9));
	//intervals.push_back(Interval(2,6));
	//intervals.push_back(Interval(8,10));
	//intervals.push_back(Interval(15,18));
	res=s->insert(intervals,Interval(2,5));
	for(int i=0;i<res.size();i++)  cout<<res[i].start<<","<<res[i].end<<endl;

	system("pause");
	return 0;
}