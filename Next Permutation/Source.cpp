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

class Solution_old {
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

//2nd pass: 2015-02-24
//3rd pass: 2015-03-22
/*
1 2 6 5 4 3
  i       j
1 3 2 4 5 6

i: first num[i]<num[i+1], or 0(swap all)
j: first num[j]>num[i], or i(don't do anything)

1. swap(i,j)
2. reverse(i+1,end)
*/
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.empty()) return;
        int i=num.size()-2, j=num.size()-1;
        while(i>=0 && num[i]>=num[i+1]) --i;
        if(i<0){
            reverse(num.begin(),num.end());
            return;
        }
        while(j>i && num[j]<=num[i]) --j;
        swap(num[i],num[j]);
        reverse(num.begin()+i+1,num.end());
    }
};

int main()
{
	Solution *s = new Solution();

	vector<int> num = { 5,1, 1 };

	s->nextPermutation(num);

	for(int i=0;i<num.size();i++)
		cout<<num[i]<<" ";
	cout<<endl;


	system("pause");
	return 0;
}