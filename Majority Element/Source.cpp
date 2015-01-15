// Majority Element
//   Author: flashhack
//   Update: 2015-01-14
#include <iostream>
#include <sstream>
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
	int total;
	int search(vector<int> &num)
	{
		int mid=(num.size()>>1);
		int tmp=num[mid];
		vector<int> smaller, greater;
		for(int it:num) 
		{
			if(it<tmp) smaller.push_back(it);
			if(it>tmp) greater.push_back(it);
		}

		if(num.size()-smaller.size()-greater.size() > total/2) return tmp;
		if(smaller.size() > greater.size()) return search(smaller);
		return search(greater);
	}
    int majorityElement(vector<int> &num) {
		total=num.size();
		return search(num);
    }
};

int main()
{
	Solution *s = new Solution();
	//int A[]={1,2,2,2,3,3,2};
	//int A[]={4,5,4};
	int A[]={12,52,12,70,12,61,12,12,50,72,82,12,11,25,28,43,40,12,12,53,12,12,98,12,12,92,81,2,12,15,40,12,12,9,12,31,12,12,12,12,77,12,12,50,12,12,12,93,41,92,12,12,12,12,12,12,12,12,12,37,48,14,12,70,82,12,80,12,12,12,12,56,30,12,8,12,50,12,20,12,21,97,12,42,12,10,12,38,73,15,9,11,79,12,12,28,51,12,15,12};
	vector<int> data(A,A+sizeof(A)/sizeof(int));
	cout<<s->majorityElement(data)<<endl;

	//for(auto it:data) cout<<it<<" ";

	system("pause");
	return 0;
}