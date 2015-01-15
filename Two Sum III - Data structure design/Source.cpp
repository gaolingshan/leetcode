// Two Sum III - Data structure design
//   Author: flashhack
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

class TwoSum {
public:
    unordered_map<int,int> table;
	void add(int number) {
	    table[number]++;
	}

	bool find(int value) {
	    for(auto it:table)
	    {
			if(table.find(value-it.first)!=table.end())
	        {
				if(it.first!=value-it.first) return true;
				else if(table[it.first]>=2) return true;
	        }
	    }
	    return false;
	}
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}