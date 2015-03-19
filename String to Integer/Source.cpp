#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution_old {
public:
	int atoi(const char *str) {
		return atol(str);
	}
};

//2nd pass: 2015-02-25
class Solution {
public:
	int atoi(string str) {
		str.erase(0, str.find_first_not_of(' '));
		if (str == "") return 0;
		bool isPositive = true;
		if (str[0] == '-' || str[0] == '+')
		{
			isPositive = (str[0] == '+');
			str = str.substr(1, str.length() - 1);
		}
		long long res = 0; int i = 0;
		while (i<str.length() && isdigit(str[i]) && res<INT_MAX) res = res * 10 + (str[i++] - '0');
		if (res == 0) return 0;
		if (isPositive) return (res>INT_MAX) ? INT_MAX : res;
		else return (-res<INT_MIN) ? INT_MIN : -res;
	}
};

//3rd pass: 2015-03-18
/*
1. trim leading white space
2. optional +-
3. only num, as many as possible. 
    3.1 not num, return
    3.2 if > INT_MAX or < INT_MIN return;
return res

about deal with overflow: 
1. use long long
2.  num>INT_MAX/10,
    num==INT_MAX/10, next digit > 7(+) 8(-) 
*/
int myAtoi(char *str) {
    bool isPositive=true;
    int ans=0;
    while(*str==' ') ++str;
	if(*str=='-' || *str=='+') {
		if(*str=='-') isPositive=false;
		++str;
	}
    while(*str>='0' && *str<='9'){
        int digit=*str-'0';
        if(ans>INT_MAX/10 || (ans==INT_MAX/10 && digit > (isPositive?7:8))) return isPositive?INT_MAX:INT_MIN;
        ans=ans*10+digit;          
		++str;
    }
    return isPositive?ans:-ans;
}

int main()
{
	Solution *s = new Solution();

	cout << s->atoi("  - 1231a313123abc") << endl;
	cout << myAtoi("  - 1231a313123abc") << endl;
	system("pause");
	return 0;
}