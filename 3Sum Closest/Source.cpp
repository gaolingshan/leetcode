#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:

	vector<int> data;

	int twoSum(int left, int right, int target)
	{
		double res=INT_MAX;
		while(left<right)
		{
			if(abs(res-target) > abs(data[left]+data[right]-target)) res=data[left]+data[right];
			if(data[left]+data[right]==target)
			{
				return target;
			}
			else
				if(data[left]+data[right]>target) right--;
				else
					left++;
		}

		return res;
	}

	int threeSumClosest(vector<int> &num, int target) {
		data = vector<int>(num);
		sort(data.begin(),data.end());
		int imax = data.size() - 2;
		double res=INT_MAX;

		for(int i=0;i<imax ;i++)
		{
			if(i!=0 && data[i-1] == data[i]) continue;
			int twoSumresult = twoSum(i+1,data.size()-1,target-data[i]);
			if(abs(twoSumresult+data[i]-target) < abs(res-target)) res = twoSumresult+data[i];
		}

		return res;
	}
};



int main()
{
	Solution *s = new Solution();

	int dataarray[] = {1,1,1,1};
	//int dataarray[] = {0,1,2};
	//int dataarray[] = {-1,2,1,4};
	//int dataarray[] = {7,5,-8,-6,-13,7,10,1,1,-4,-14,0,-1,-10,1,-13,-4,6,-11,8,-6,0,0,-5,0,11,-9,8,2,-6,4,-14,6,4,-5,0,-12,12,-13,5,-6,10,-10,0,7,-2,-5,-12,12,-9,12,-9,6,-11,1,14,8,-1,7,-13,8,-11,-11,0,0,-1,-15,3,-11,9,-7,-10,4,-2,5,-4,12,7,-8,9,14,-11,7,5,-15,-15,-4,0,0,-11,3,-15,-15,7,0,0,13,-7,-12,9,9,-3,14,-1,2,5,2,-9,-3,1,7,-12,-3,-1,1,-2,0,12,5,7,8,-7,7,8,7,-15};
	vector<int> data(dataarray, dataarray + sizeof(dataarray)/sizeof(int));
	cout<<s->threeSumClosest(data,0)<<endl;

	system("pause");
	return 0;
}


