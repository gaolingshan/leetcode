// Max Points on a Line
//   Author: flashhack
//   Update: 2015-01-12
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

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
 

class Solution_old {
public:
	unordered_map<double,int> table;				
    int maxPoints(vector<Point> &points) {
		if(points.size()==0) return 0;
		int ans=0,count=0,same=0;
		for(int i=0;i<points.size();i++)
		{
			Point p1=points[i];
			table.clear();
			//trick here, same points are possible. first count same points.
			same=0;
			for(int j=0;j<points.size();j++) if(p1.x==points[j].x && p1.y==points[j].y) same++;
			count=same;
			ans=max(ans,count);
			for(int j=0;j<points.size();j++)
				if(p1.x != points[j].x || p1.y != points[j].y)
				{
					Point p2=points[j];
					if(p1.x == p2.x)
					{
						count++;
						ans=max(ans,count);
					}
					else
					{
						//trick here, stupid int problem
						double slope=(double)(p2.y-p1.y)/(p2.x-p1.x);
						if(table.find(slope)==table.end()) 
							table[slope]=same+1;
						else
							table[slope]++;
						ans=max(ans,table[slope]);
					}
				
				}
		}
		return ans;
    }
};

//2nd pass: 2015-02-07
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        unordered_map<double,int> table;
        int ans=0;
        for(int i=0;i<points.size();i++)
        {
            Point a=points[i];
            int count=0,same=0;
            for(auto p:points)if(p.x==a.x && p.y==a.y) same++;
			count=same;
			ans=max(ans,same);
            table.clear();
            for(auto p:points)
            {
                if(p.x==a.x && p.y!=a.y) 
                {
                    count++;
                    ans=max(ans,count);
                }
                else
                {
                    double intercept=(double)(p.y-a.y)/(p.x-a.x);
					if(table.count(intercept)==0) table[intercept]=same+1; else
                    table[intercept]++;
                    ans=max(ans,table[intercept]);
                }
            }
        }
        return ans;
    }
};

int main()
{
	Solution *s = new Solution();
	//Point A[] = {Point(0,0),Point(1,0)};
	//Point A[] = {Point(1,1),Point(1,1),Point(2,2),Point(2,2)};
	Point A[] = {Point(84,250),Point(0,0),Point(1,0),Point(0,-70),Point(0,-70),Point(1,-1),Point(21,10),Point(42,90),Point(-42,-230)};
	vector<Point> data;
	for(auto it:A) data.push_back(it);
	cout<<s->maxPoints(data)<<endl;

	system("pause");
	return 0;
}