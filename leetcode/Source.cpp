#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> res;
		map<int,int> hashtable;
		for(int i=0;i<numbers.size();i++)
		{
			if(hashtable.find(target - numbers[i]) != hashtable.end())
			{
				res.push_back(hashtable[target - numbers[i]]);
				res.push_back(i+1);
				return res;
			}
			else
			{
				hashtable[numbers[i]]=i+1;
			}
		}
		return res;
	}
};

int main()
{
	Solution *s = new Solution();
	const int arr[] = {2, 7, 11, 15};
	
	vector<int> res = s->twoSum(vector<int>(arr,arr+sizeof(arr)/sizeof(arr[0])),26);
	for(int i=0;i<res.size();i++) cout<<res[i]<<endl;

	system("pause");
	return 0;
}