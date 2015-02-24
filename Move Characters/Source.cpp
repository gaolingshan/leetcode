// Move Characters
//   Author: flashhack
//   Update: 2015-02-22
#include <iostream>
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
#include <stack>
using namespace std;

class Solution {
public:
	void moveThem(char *s) {
		int len = strlen(s);
		for (int i = len-1, j = len-1; i >= 0; i--)
			if (s[i] != ' ') swap(s[j--], s[i]);
	}
	void moveLeft(char *s) {
		int len = strlen(s);
		for (int i = 0, j = 0; i < len; i++)
			if (s[i] != ' ') swap(s[j++], s[i]);
	}
};

int main()
{
	Solution *s = new Solution();
	char str[8] = "a b   c";
	s->moveThem(str);
	//s->moveRight(str);
	cout << str << endl;

	system("pause");
	return 0;
}