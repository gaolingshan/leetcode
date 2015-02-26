#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution_old {
public:
	int reverse(int x) {
		long long int res = 0;
		long long int i=1;
		vector<long long int> digits;
		while(x!=0)
		{
			digits.push_back(x%10);
			x /= 10;
		}
		for(int j=digits.size()-1;j>=0;j--)
		{
			res += digits[j] * i;
			i *= 10;
		}

		return res;
	}
};

//2nd pass: 2015-02-26
class Solution {
public:
	int reverse(int x) {
		if (x == 0) return 0;
		bool isPositive = (x>0);
		x = abs(x);
		long long res = 0;
		while (x)
		{
			res = res * 10 + x % 10;
			x /= 10;
		}
		if (isPositive) return (res>INT_MAX) ? 0: res;
		else return (-res<INT_MIN) ? 0: -res;
	}
};

int main()
{
	Solution *s = new Solution();

	cout << s->reverse(-1233) << endl;
	system("pause");
	return 0;
}
