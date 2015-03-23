#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
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
class Solution_2nd {
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

//3rd pass: 2015-03-22
/*
method 1: hash
method 2: sort then two pointers
*/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int,int> table;
        for(int i=0;i<numbers.size();++i) table[numbers[i]]=i;
        for(int i=0;i<numbers.size();++i) if(table.count(target-numbers[i])!=0 && table[target-numbers[i]]>i) return {i+1,table[target-numbers[i]]+1};
    }
    vector<pair<int,int>> twoSum2(vector<int> &numbers, int target) {
		vector<pair<int,int>> res;
        sort(numbers.begin(), numbers.end());
        int left=0,right=numbers.size()-1;
        while(left<right){
            if(numbers[left]+numbers[right]>target) --right; 
            else if(numbers[left]+numbers[right]<target) ++left;
            else res.emplace_back(numbers[left++],numbers[right--]);
        }
		return res;
    }
};

int main()
{
	Solution *s = new Solution();
	vector<int> data={2, 1, 5, 7, -1, 4};
	
	//vector<int> res = s->twoSum(data,6);
	//for(int i=0;i<res.size();i++) cout<<res[i]<<endl;

	auto ans=s->twoSum2(data,6);
	for(auto t:ans) cout<<t.first<<" "<<t.second<<endl;

	system("pause");
	return 0;
}