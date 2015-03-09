// 
//   Author: 
//   Update: 
#include <iostream>
#include <functional>
#include <bitset>
#include <chrono>
#include <exception>
#include <fstream>
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
#include <deque>
#include <stack>
using namespace std;

class BigInt
{
public:
	vector<int> digits;
	bool isPositive;
	BigInt()
	{
		digits.push_back(0);
		isPositive=true;
	}
	string toString()
	{
		string res = "";
		if (!isPositive) res = "-";
		for (int i=digits.size()-1;i>=0;i--) res+=to_string(digits[i]);
		return res;
	}

	BigInt operator + (const BigInt& other)
	{
		for(int i=0;i<other.digits.size();i++)
		{
			if(i<digits.size()) {
				digits[i]+=other.digits[i];
				if(digits[i]/10)
				{
					if(i+1<digits.size())
						digits[i+1]+=digits[i]/10;
					else
						digits.push_back(digits[i]/10);
					digits[i]%=10;
				}
			}else
				digits.push_back(other.digits[i]);
		}
		return *this;
	}

	BigInt& operator = (const BigInt& other){
		digits.assign(other.digits.begin(), other.digits.end());
		isPositive = other.isPositive;
		return *this;
	}

	BigInt& operator = (const string& other){
		digits.clear();
		isPositive=true;
		string tmp=other;
		if(tmp[0]=='-') {
			isPositive = false;
			tmp=tmp.substr(1);
		}
		for(int i=tmp.size()-1;i>=0;i--) digits.push_back(tmp[i]-'0');
		return *this;
	}

	BigInt& operator = (int number){
		digits.clear();
		isPositive = (number>0);
		number=abs(number);
		while(number) {
			digits.push_back(number%10);
			number/=10;
		}
		return *this;
	}
};

int main()
{
	BigInt a,b,c;
	a=123;
	b="9999999999999999999999999999999999999";
	cout<<a.toString()<<endl;
	c=a+b;
	cout<<c.toString()<<endl;
	system("pause");
	return 0;
}