// Plus One
//   Author: flashhack
//   Update: 2014-12-17
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

//only 8ms! Not reversing the digits!
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		if(digits.empty())
		{
			digits.push_back(1);
			return digits;
		}
		int len=digits.size();
		digits[len-1]+=1;
		int residue=digits[len-1]/10;
		digits[len-1]%=10;
		int i=len-2;
		while(residue)
		{
			if(i>=0) 
			{
				digits[i]+=residue;
				residue=digits[i]/10;
				digits[i]%=10;
				i--;
			}
			else
			{
				digits.insert(digits.begin(),residue);
				residue=0;
			}
		}
		return digits;
    }
};

int main()
{
	Solution *s = new Solution();
	int A[] = {9,9,9,9};
	vector<int> digits(A,A+sizeof(A)/sizeof(int));
	vector<int> res = s->plusOne(digits);
	for(auto it : res) cout<<it;
	cout<<endl;


	system("pause");
	return 0;
}