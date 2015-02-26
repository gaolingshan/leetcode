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

int main()
{
	Solution *s = new Solution();

	cout << s->atoi("  - 1231a313123abc") << endl;
	system("pause");
	return 0;
}