#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
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
				else left++;
		}

		return result;
	}

	vector<vector<int> > threeSum(int left, int target) {
		vector<vector<int> > result;
		vector<vector<int> > twoSumresult;
		int imax = data.size() - 2;

		for(int i=left;i<imax ;i++)
		{
			if(i!=left && data[i-1] == data[i]) continue;
			twoSumresult = twoSum(i+1,data.size()-1,target-data[i]);
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

	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > result;
		vector<vector<int> > threeSumresult;
		
		data = vector<int>(num);
		sort(data.begin(),data.end());
		int imax = data.size() - 3;

		for(int i=0;i<imax;i++)
		{
			if(i!=0 && data[i-1] == data[i]) continue;
			threeSumresult = threeSum(i+1,target-data[i]);
			for(int j=0;j<threeSumresult.size();j++)
			{
				vector<int> tmp;
				tmp.push_back(data[i]);			
				tmp.push_back(threeSumresult[j][0]);
				tmp.push_back(threeSumresult[j][1]);
				tmp.push_back(threeSumresult[j][2]);
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
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        vector<vector<int>> res;
        for(int i=0;i<num.size();i++)
        {
            if(i>0 && num[i]==num[i-1]) continue;
            for(int j=i+1;j<num.size();j++)
                for(int left=j+1,right=num.size()-1; left<right && left<num.size() && right>=0;)
                {
                    int sum=num[i]+num[j]+num[left]+num[right];
                    if(sum==target) res.push_back({num[i],num[j],num[left++],num[right--]});
                    else if(sum>target)right--;else left++;
                }
        }
        sort(res.begin(),res.end());
        res.resize(distance(res.begin(),unique(res.begin(),res.end())));
        return res;
    }
};



int main()
{
	Solution *s = new Solution();

	//int dataarray[] = {1,0,-1,0,-2,2};
	//int dataarray[] = {7,5,-8,-6,-13,7,10,1,1,-4,-14,0,-1,-10,1,-13,-4,6,-11,8,-6,0,0,-5,0,11,-9,8,2,-6,4,-14,6,4,-5,0,-12,12,-13,5,-6,10,-10,0,7,-2,-5,-12,12,-9,12,-9,6,-11,1,14,8,-1,7,-13,8,-11,-11,0,0,-1,-15,3,-11,9,-7,-10,4,-2,5,-4,12,7,-8,9,14,-11,7,5,-15,-15,-4,0,0,-11,3,-15,-15,7,0,0,13,-7,-12,9,9,-3,14,-1,2,5,2,-9,-3,1,7,-12,-3,-1,1,-2,0,12,5,7,8,-7,7,8,7,-15};
	int dataarray[] = {-430,-407,-404,-370,-364,-343,-291,-263,-257,-242,-213,-212,-210,-209,-172,-144,-85,-79,-70,-36,-34,-14,0,18,31,36,45,45,83,117,120,134,153,178,186,197,208,223,234,263,264,313,341,382,388,421,427,439,445,451,458,467,474,480};
	vector<int> data(dataarray, dataarray + sizeof(dataarray)/sizeof(int));
	vector<vector<int> > fourSumResult = s->fourSum(data,4668);
	for(int i=0;i<fourSumResult.size();i++) cout<<fourSumResult[i][0]<<","<<fourSumResult[i][1]<<","<<fourSumResult[i][2]<<","<<fourSumResult[i][3]<<endl;

	system("pause");
	return 0;
}


