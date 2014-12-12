// Next Permutation
//   Author: flashhack
//   Update: 2014-12-12
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
		if(num.size() == 1) return;
		int i = num.size()-2;
		while(i>=0)
		{
			if(num[i]<num[i+1]) break;
			i--;
		}
		int j=num.size()-1;
		if(i>=0)
		{
			while(j>i) 
			{
				if(num[j]>num[i]) break;
				j--;
			}
			//if (j==i) return;
			// swap i,j
			num[i]^=num[j];
			num[j]^=num[i];
			num[i]^=num[j];
		}
		// reverse i+1 to n
		int ii=i+1,jj=num.size()-1;
		while(ii<jj)
		{
			num[ii]^=num[jj];
			num[jj]^=num[ii];
			num[ii]^=num[jj];
			ii++;
			jj--;
		}
    }
};

int main()
{
	Solution *s = new Solution();

	vector<int> num;
	num.push_back(5);
	num.push_back(1);
	num.push_back(1);
	num.push_back(1);

	s->nextPermutation(num);

	for(int i=0;i<num.size();i++)
		cout<<num[i]<<" ";
	cout<<endl;


	system("pause");
	return 0;
}