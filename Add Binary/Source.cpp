// Add Binary 
//   Author: flashhack
//   Update: 2014-12-16
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
    string addBinary(string a, string b) {
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		if(a.length()<b.length()) swap(a,b);
		string res="";
		int digit=0;
		for(int i=0;i<a.length();i++)
		{
			digit=a[i]-'0';
			if(res.length()>i) digit += res[i]-'0';
			if(b.length()>i) digit+=b[i]-'0';
			if(res.length()>i)
				res[i]='0'+digit;
			else
				res.push_back('0'+digit);
			int j=i;
			while((res[j]-'0') / 2)
			{
				if(res.length()>j+1)res[j+1]+=(res[j]-'0')/2;
				else
					res.push_back('0'+(res[j]-'0')/2);
				res[j]='0'+(res[j]-'0')%2;
				if(res.length()>j+1) j++;
			}
		}
		reverse(res.begin(),res.end());
		return res;
    }
};

//Need improve, more compact

int main()
{
	Solution *s = new Solution();
	cout << s->addBinary("1","111101")<<endl;


	system("pause");
	return 0;
}