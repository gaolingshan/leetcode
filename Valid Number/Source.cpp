// Valid Number
//   Author: flashhack
//   Update: 2015-01-14
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
    bool isNumber(const char *s) {
        string str(s);
		bool isInt=true;
		bool isFloat=true;
		try
		{
			int tmp=stoi(str);
			cout<<tmp<<endl;
			cout<<str<<endl;
		}
		catch(exception e)
		{
			isInt=false;
		}

		try
		{
			double tmp=stod(str);
			cout<<tmp<<endl;
			cout<<str<<endl;
		}
		catch(exception e)
		{
			isFloat=false;
		}
		return isInt & isFloat;
    }
};

int main()
{
	Solution *s = new Solution();
	cout<<s->isNumber("2 . 1")<<endl;;
	//cout<<s->isNumber("2e10")<<endl;;


	system("pause");
	return 0;
}