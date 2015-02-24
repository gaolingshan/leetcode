#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution_old {
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

//2nd pass: 2015-02-22
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int,int> table;
        vector<int> res;
        for(int i=0;i<numbers.size();i++) table[numbers[i]]=i;
        for(int i=0;i<numbers.size();i++) 
        {
            int num=target-numbers[i];
            if(table.count(num)!=0 && table[num]>i)
            {
                res.push_back(i);
                res.push_back(table[num]);
                return res;
            }
        }
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