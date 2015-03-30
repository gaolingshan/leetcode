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

class Solution_old {
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

//2nd pass: 2015-02-22
class Solution_2nd {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> res;
		int i = 0, len = intervals.size();
		while (i<len && intervals[i].end < newInterval.start) res.push_back(intervals[i++]);
		while (i<len && newInterval.end >= intervals[i].start)
		{
			newInterval.start = min(newInterval.start, intervals[i].start);
			newInterval.end = max(newInterval.end, intervals[i].end);
			i++;
		}
		res.push_back(newInterval);
		while (i<len) res.push_back(intervals[i++]);
		return res;
	}
};

//3rd pass: 2015-02-22
class Solution_3rd {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		auto it = intervals.begin();
		for (; it != intervals.end(); it++) if (it->start >= newInterval.start) break;
		intervals.insert(it, newInterval);
		vector<Interval> res;
		int len = intervals.size(), start = intervals[0].start, end = intervals[0].end;
		for (int i = 1; i<len; i++)
		{
			auto now = intervals[i];
			if (now.start > end)
			{
				res.emplace_back(start, end);
				start = now.start;
				end = now.end;
			}
			else
				end = max(end, now.end);
		}
		res.emplace_back(start, end);
		return res;
	}
};

//4th pass: 2015-03-30
/*
traverse interval i:
1. no over lap, just add
2. begin over lap, update newInterval
3. finsh over lap, append newInterval, then just add left intervals.

    [new.start,new.end]
[i.start,i.end]     [i.start,i.end]
overlap rule: i.end>=new.start  &&  i.start<=new.end
*/
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        int i=0;
        for(i=0;i<intervals.size();++i) if(intervals[i].end < newInterval.start) res.push_back(intervals[i]); else break;
        for(;i<intervals.size();++i) if(intervals[i].start <= newInterval.end) {
            newInterval.start=min(newInterval.start,intervals[i].start);
            newInterval.end=max(newInterval.end,intervals[i].end);
        } else break;
        res.push_back(newInterval);
        for(;i<intervals.size();++i) res.push_back(intervals[i]);
        return res;
    }
};

int main()
{
	Solution *s = new Solution();
	vector<Interval> intervals,res;
	intervals.push_back(Interval(1,2));
	intervals.push_back(Interval(3,5));
	intervals.push_back(Interval(6,7));
	intervals.push_back(Interval(8,10));
	intervals.push_back(Interval(15,18));
	res=s->insert(intervals,Interval(4,9));
	for(int i=0;i<res.size();i++)  cout<<res[i].start<<","<<res[i].end<<endl;

	system("pause");
	return 0;
}