#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if(x<0) return false;
		int digi = (int)log10(x);
		int high = (int)pow(10,digi);
		while(x > 0)
		{
			if(x%10 != x/high) return false;
			x %= high;
			x /= 10;
			high /= 100;
		}
		return true;
	}
};

int main()
{
	Solution *s = new Solution();

	cout << s->isPalindrome(-2147447418) << endl;
	system("pause");
	return 0;
}