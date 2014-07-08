#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

class Solution {
public:
	int f[1000][1000];
	bool isMatch(const char *s, const char *p) {
		int i=strlen(s),j=strlen(p);
		if(f[i][j] != 0) return (f[i][j]==1?true:false);
		if(*s==0 && *p==0) 
		{
			f[i][j] = 1;
			return true;
		}
		if((*s!=0 && *p==0))
		{
			f[i][j] = -1;
			return false;
		}
		
		int tmp = strlen(s);

		if(*(p+1)=='*')
		{
			if(*s != 0)
			{
				if(*s == *p || *p=='.') 
				{
					if(isMatch(s+1,p) || isMatch(s+1,p+2) || isMatch(s,p+2)) f[i][j]=1; else f[i][j]=-1;
					return (f[i][j]==1?true:false);
				}
			}
			if(isMatch(s,p+2)) f[i][j]=1; else f[i][j]=-1;
			return (f[i][j]==1?true:false);
		}
		if(*s != 0 && (*s == *p || *p=='.')) 
		{
			if(isMatch(s+1,p+1)) f[i][j]=1; else f[i][j]=-1;
			return (f[i][j]==1?true:false);
		}
		
		else 
		{
			f[i][j]=-1;
			return false;
		}
	}
};

int main()
{
	Solution *s = new Solution();
	//cout << s->isMatch("",".") << endl;			//0
	//cout << s->isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c") << endl;		//0
	//cout << s->isMatch("ba", ".*a*a") << endl;		//1
	//cout << s->isMatch("a", "ab*") << endl;			//1
	//cout << s->isMatch("aaa", "a*a") << endl;		//1

	//cout << s->isMatch("aab", "c*a*b") << endl;		//1
	//cout << s->isMatch("aaaaa", "a*") << endl;		//1
	//cout << s->isMatch("dd", ".*abc") << endl;		//0
	//cout << s->isMatch("a",".*") << endl;			//1
	//cout << s->isMatch("",".*") << endl;			//1
	//cout << s->isMatch("a","") << endl;				//0
	system("pause");
	return 0;
}