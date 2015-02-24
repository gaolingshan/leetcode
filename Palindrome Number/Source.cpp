#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

class Solution_old {
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

//2nd pass: 2015-02-22
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int digits=log10(x);
        int high=(int)pow(10,digits);
        while(x>0)
        {
            if(x%10 != x/high) return false;
            x=x%high/10;
            high/=100;
        }
        return true;
    }
};

int main()
{
	Solution *s = new Solution();

	cout << s->isPalindrome(-2147447418) << endl;
	cout << s->isPalindrome(12231) << endl;
	cout << s->isPalindrome(1000021) << endl;
	system("pause");
	return 0;
}