#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

class Solution {
public:
	int atoi(const char *str) {
		return atol(str);
	}
};

int main()
{
	Solution *s = new Solution();

	cout << s->atoi("12313123123123") << endl;
	system("pause");
	return 0;
}