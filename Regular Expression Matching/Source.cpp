#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

class Solution_old {
public:
	bool isMatch(const char *s, const char *p) {
		if(*s==0 && *p==0) 			return true;
		if(*s!=0 && *p==0)			return false;

		if(*(p+1)=='*')
		{
			while(*s == *p || *p=='.' && *s != 0)
			{
				if(isMatch(s,p+2)) return true;
				s++;
			}
			return isMatch(s,p+2);
		}
		if(*s != 0 && (*s == *p || *p=='.')) return isMatch(s+1,p+1);
		else return false;
	}
};

//2nd pass: 2015-02-22
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*p=='\0') return (*s=='\0');
        if(*(p+1)=='*')
        {
            while(*s && (*s==*p||*p=='.')) 
            {
                if(isMatch(s,p+2)) return true;
                s++;
            }
            return isMatch(s,p+2);
        }
        else
            if(*s && (*s==*p||*p=='.')) return isMatch(s+1,p+1); else return false;
    }
};

int main()
{
	Solution *s = new Solution();
	cout << s->isMatch("",".") << endl;			//0
	cout << s->isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c") << endl;		//0
	cout << s->isMatch("ba", ".*a*a") << endl;		//1
	cout << s->isMatch("a", "ab*") << endl;			//1
	cout << s->isMatch("aaa", "a*a") << endl;		//1

	cout << s->isMatch("aab", "c*a*b") << endl;		//1
	cout << s->isMatch("aaaaa", "a*") << endl;		//1
	cout << s->isMatch("dd", ".*abc") << endl;		//0
	cout << s->isMatch("a",".*") << endl;			//1
	cout << s->isMatch("",".*") << endl;			//1
	cout << s->isMatch("a","") << endl;				//0
	system("pause");
	return 0;
}