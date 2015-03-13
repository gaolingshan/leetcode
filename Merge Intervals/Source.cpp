// Merge Intervals
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

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


class Solution_old {
public:
	struct cmp
	{
		bool operator()(const Interval & a, const Interval & b)
		{
			return a.start<b.start;
		}
	}cmp_object;

    vector<Interval> merge(vector<Interval> &intervals) {
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
	struct cmp
	{
		bool operator () (const Interval &a, const Interval &b)
		{
			return a.start<b.start;
		}
	}cmp_obj;
	vector<Interval> merge(vector<Interval> &intervals) {
		sort(intervals.begin(), intervals.end(), cmp_obj);
		vector<Interval> res;
		if (intervals.size() == 0) return res;
		int start = intervals[0].start, end = intervals[0].end;
		for (int i = 1; i<intervals.size(); i++)
		{
			if (intervals[i].start > end)
			{
				res.push_back(Interval(start, end));
				start = intervals[i].start;
				end = intervals[i].end;
			}
			else
				end = max(end, intervals[i].end);
		}
		res.push_back(Interval(start, end));
		return res;
	}
};

//3rd pass: 2015-03-12
/*
1. sort intervals with start
2. set st,ed = 1st interval
3. traverse from 2~n intervals
3.1 ed>=i.st , need merge ed=max(ed,i.end), i++
3.2 ed<i.st, [st,ed] is a new one, set st,ed to interval i
4. finally insert [st,ed]
*/
class Solution {
public:
    struct cmp_struct{
        bool operator () (const Interval &a, const Interval &b) const{
            return a.start < b.start;
        }
    }cmp_obj;
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        if(intervals.empty()) return res;
        sort(intervals.begin(),intervals.end(),cmp_obj);
        int st=intervals[0].start, ed=intervals[0].end;
        for(int i=1;i<intervals.size();i++){
            if(ed>=intervals[i].start) ed=max(ed,intervals[i].end); else{
                res.emplace_back(st,ed);
                st=intervals[i].start;
                ed=intervals[i].end;
            }
        }
        res.emplace_back(st,ed);
        return res;
    }
};

int main()
{
	Solution *s = new Solution();
	vector<Interval> intervals,res;
	intervals.push_back(Interval(1,2));
	intervals.push_back(Interval(2,6));
	intervals.push_back(Interval(8,10));
	intervals.push_back(Interval(15,18));
	res=s->merge(intervals);
	for(int i=0;i<res.size();i++)  cout<<res[i].start<<","<<res[i].end<<endl;

	system("pause");
	return 0;
}