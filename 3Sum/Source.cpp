#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution_old {
public:

	vector<int> data;

	vector<vector<int> > twoSum(int left, int right, int target)
	{
		vector<vector<int> > result;
		while(left<right)
		{
			if(data[left]+data[right]==target)
			{
				vector<int> tmp;
				tmp.push_back(data[left]);
				tmp.push_back(data[right]);
				result.push_back(tmp);
				left++;
				right--;
			}
			else
				if(data[left]+data[right]>target) right--;
				else
					left++;
		}
		return result;
	}

	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > result;
		vector<vector<int> > twoSumresult;
		data = vector<int>(num);
		sort(data.begin(),data.end());
		int imax = data.size() - 2;

		for(int i=0;i<imax ;i++)
		{
			if(i!=0 && data[i-1] == data[i]) continue;
			twoSumresult = twoSum(i+1,data.size()-1,-data[i]);
			for(int j=0;j<twoSumresult.size();j++)
			{
				vector<int> tmp;
				tmp.push_back(data[i]);
				tmp.push_back(twoSumresult[j][0]);
				tmp.push_back(twoSumresult[j][1]);
				result.push_back(tmp);
			}
		}

		auto it = unique(result.begin(),result.end());
		result.resize(distance(result.begin(),it));
		return result;
	}
};

//2nd pass: 2015-02-22
class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		sort(num.begin(), num.end());
		vector<vector<int>> res;
		for (int i = 0; i<num.size(); i++)
		{
			if (i>0 && num[i] == num[i - 1]) continue;
			for (int left = i + 1, right = num.size() - 1; left<right && left<num.size() && right >= 0;)
			{
				int sum = num[i] + num[left] + num[right];
				if (sum == 0) res.push_back({ num[i], num[left++], num[right--] });
				else if (sum > 0) right--; else left++;
			}
		}
		res.resize(distance(res.begin(), unique(res.begin(), res.end())));
		return res;
	}
};



int main()
{
	Solution *s = new Solution();

	//int dataarray[] = {1};
	int dataarray[] = {7,5,-8,-6,-13,7,10,1,1,-4,-14,0,-1,-10,1,-13,-4,6,-11,8,-6,0,0,-5,0,11,-9,8,2,-6,4,-14,6,4,-5,0,-12,12,-13,5,-6,10,-10,0,7,-2,-5,-12,12,-9,12,-9,6,-11,1,14,8,-1,7,-13,8,-11,-11,0,0,-1,-15,3,-11,9,-7,-10,4,-2,5,-4,12,7,-8,9,14,-11,7,5,-15,-15,-4,0,0,-11,3,-15,-15,7,0,0,13,-7,-12,9,9,-3,14,-1,2,5,2,-9,-3,1,7,-12,-3,-1,1,-2,0,12,5,7,8,-7,7,8,7,-15};
	vector<int> data(dataarray, dataarray + sizeof(dataarray)/sizeof(int));
	vector<vector<int> > threeSumResult = s->threeSum(data);
	for(int i=0;i<threeSumResult.size();i++) cout<<threeSumResult[i][0]<<","<<threeSumResult[i][1]<<","<<threeSumResult[i][2]<<endl;

	system("pause");
	return 0;
}


