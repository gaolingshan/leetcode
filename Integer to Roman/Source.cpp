// Integer to Roman
//   Author: flashhack
//   Update: 2014-12-13
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

class Solution {
public:
    string intToRoman(int num) {
        string res="";
		char list[] = {'I','V','X','L','C','D','M'};
		int digit=0,base=1000,n=3;
		while(base > 0)
		{
			digit=num/base;
			int i=0;
			if(digit<=3)
				for(i=1;i<=digit;i++)
				{
					res += list[2*n];
				}
			if(digit==4)
			{
				res += list[2*n];
				res += list[2*n+1];
			}
			if(digit>=5 && digit <=8)
			{
				res += list[2*n+1];
				for(i=6;i<=digit;i++)
				{
					res += list[2*n];
				}
			}
			if(digit==9)
			{
				res += list[2*n];
				res += list[2*n+2];
			}
			num%=base;
			base/=10;
			n--;
		}
		return res;
    }
};

int main()
{
	Solution *s = new Solution();
	cout<<s->intToRoman(11)<<endl;

	system("pause");
	return 0;
}