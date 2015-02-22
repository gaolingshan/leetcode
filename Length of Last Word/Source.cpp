// <filename>.<ext>
//   Author: <name>
//   Update: <date>
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

class Solution_old {
public:
    int lengthOfLastWord(const char *s) {
        int now=0,last=0;
		while(*s!=0)
		{
			if(*s==' ')
			{
				//tricky here, mutiple space
				if(now!=0)last=now;
				now=0;
			}
			else
			{
				now++;
				last=now;
			}
			s++;
		}
		return last;
    }
};

//2nd pass:
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int now=0,last=0;
		while(*s!=0)
		{
			if(*s==' ') now=0;
			else
			{
				now++;
				last=now;
			}
			s++;
		}
		return last;
    }
};

int main()
{
	Solution *s = new Solution();

	cout<<s->lengthOfLastWord("Hello World")<<endl;;
	cout<<s->lengthOfLastWord("   b   a  ")<<endl;;


	system("pause");
	return 0;
}