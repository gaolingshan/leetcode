// Gas Station
//   Author: flashhack
//   Update: 2015-01-10
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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int tmp=INT_MAX,tmpstart=0;
		for(int i=0;i<gas.size();i++)
		{
			if(gas[i]-cost[i]<tmp)
			{
				tmp=gas[i]-cost[i];
				tmpstart=i;
			}
		}
		tmpstart=(tmpstart+1)%gas.size();
		for(int start=tmpstart;start<gas.size();start++)
		{
			int now=0;
			bool finished=true;
			for(int j=0;j<gas.size();j++)
			{
				int k=(start+j)%gas.size();
				now+=gas[k]-cost[k];
				if(now<0)
				{
					finished=false;
					break;
				}
			}
			if(finished) return start;
		}
		return -1;
    }
};

//2nd pass: 2015-03-11
/*
total gas<cost, -1. Otherwise must have a starting point
sum += gas-cost so far
1. sum>=0 continue
2. sum<0, these whole range cannot be start point, st=i+1, sum=0
*/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum=0,st=0,total=0;
        for(int i=0;i<gas.size();i++){
            sum+=gas[i]-cost[i];
            total+=gas[i]-cost[i];
            if(sum<0) {
                st=i+1;
                sum=0;
            }
        }
        if(total<0) return -1; else return st;
    }
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}