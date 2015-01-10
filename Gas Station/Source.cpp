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

class Solution {
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

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}