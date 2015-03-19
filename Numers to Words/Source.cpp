// Numbers to Words
//   Author: flashhack
//   Update: 2015-03-12
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

/*
3 digits is basic, recursion, then xxx trillion xxx billion xxx million xxx thousand xxx
units 0~19
tens 0,10,20,30..90
skip zero don't output

corners:
1. num==zero, just output
2. after mod, zero, don't output
3. negative number: minus xxx
*/

string convert(int num){
	string res="";
	if(num<0) return "minus "+convert(abs(num));
	if(num==0) return "zero";
    if(num>=1000000000) return convert(num/1000000000) + " billion" + ((num%1000000000)?(" "+convert(num%1000000000)):"");
    if(num>=1000000) return convert(num/1000000) + " million" + ((num%1000000)?(" "+convert(num%1000000)):"");
    if(num>=1000) return convert(num/1000) + " thousand" + ((num%1000)?(" "+convert(num%1000)):"");
	string units[]={"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen",
					"forteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
	string tens[]={"","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    if(num>=100) return units[num/100] + " hundred" + ((num%100)?(" "+convert(num%100)):"");
	if(num<20) return units[num];
	return tens[num/10] + " " + units[num%10];
}

/*
12345 -> 12,345
n%1000 + res
then n/=1000
*/
string convert2(int num){
	string res=(num<0)?"-":"";
	long long n=abs(num);
	while(n){
		res = ((n/1000)?",":"") + to_string(n%1000) + res;
		n/=1000;
	}
	return res;
}

int main()
{
	//cout<<convert(1123456789)<<endl;
	cout<<convert2(123456789)<<endl;
	system("pause");
	return 0;
}