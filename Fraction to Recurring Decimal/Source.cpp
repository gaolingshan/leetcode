// Fraction to Recurring Decimal
//   Author: flashhack
//   Update: 2015-01-14
#include <iostream>
#include <sstream>
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
    string fractionToDecimal(int numerator, int denominator) {
		bool isNeg=false;
		long long _numerator = (long long)numerator;
		long long _denominator = (long long)denominator;
		if((_numerator<0 && _denominator>0) || (_numerator>0&&_denominator<0))
		{
			isNeg=true;
			_numerator=abs(_numerator);
			_denominator=abs(_denominator);
		}
		string part1=to_string(_numerator/_denominator);
		if(isNeg) part1="-"+part1;
		long long residue = _numerator%_denominator;
		if(residue==0) return part1;
		string part2,res;      
		unordered_map<long long,long long> residue_pos;
		while(residue!=0)
		{
			if(residue_pos.find(residue) != residue_pos.end())
			{
				int i=residue_pos[residue];
				part2=part2.substr(0,i)+"("+part2.substr(i,part2.length()-i)+")";
				res=part1+"."+part2;
				return res;
			}
			residue_pos[residue]=part2.length();
			residue*=10;
			long long num=residue/_denominator;
			residue%=denominator;
			part2+='0'+num;
		}
		return part1+"."+part2;
    }
};

int main()
{
	Solution *s = new Solution();
	//cout<<s->fractionToDecimal(1,6)<<endl;
	//cout<<s->fractionToDecimal(-2147483648, -1)<<endl;
	//cout<<s->fractionToDecimal(-1,-2147483648)<<endl;
	cout<<s->fractionToDecimal(-2147483648,1)<<endl;
	//cout<<s->fractionToDecimal(1,333)<<endl;
	//cout<<s->fractionToDecimal(1,17)<<endl;
	//cout<<s->fractionToDecimal(-50,8)<<endl;

	system("pause");
	return 0;
}