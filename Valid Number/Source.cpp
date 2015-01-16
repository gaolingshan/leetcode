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
		if(str.length()==0) return false;
		while(str[0]==' ' && str.length()>0) str=str.substr(1,str.length()-1);
		if(str.length()==0) return false;
		while(str[str.length()-1]==' ' && str.length()>0) str=str.substr(0,str.length()-1);
		if(str.length()==0) return false;
		//eleminate trailing and preling zeros.

		char* pEnd;
		double tmp = strtod(str.c_str(),&pEnd);
		if(pEnd!=NULL && string(pEnd)!="") return false;
		return true;
    }
};

int main()
{
	Solution *s = new Solution();
	//cout<<s->isNumber("-2.e1")<<endl;
	//cout<<s->isNumber("2e10")<<endl;
	//cout<<s->isNumber("078332e437")<<endl;
	//cout<<s->isNumber("06020e6073")<<endl;
	//cout<<s->isNumber("e")<<endl;
	//cout<<s->isNumber(" 005047e+6")<<endl;
	//cout<<s->isNumber("92e1740e91")<<endl;
	//cout<<s->isNumber("3")<<endl;


	system("pause");
	return 0;
}