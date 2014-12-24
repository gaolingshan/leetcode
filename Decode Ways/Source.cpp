// Decode Ways
//   Author: flashhack
//   Update: 2014-12-23
#include <iostream>
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
	int f[10000];
    int numDecodings(string s) {
		int len=s.length();
		if(len==0) return 0;
		memset(f,0,sizeof(f));
		//boundary case here
		if(s[0]=='0') return 0; else f[0]=1;
		int num=0;
		for(int i=1;i<len;i++)
		{
			//trick here: 0 cannot be interpreted, must appear in 10 form
			f[i]=(s[i]=='0'?0:f[i-1]);
			num=atoi(s.substr(i-1,2).c_str());
			//trick here: two digits must >=10, not 1
			if(num>=10 && num<=26) f[i]+=(i>=2?f[i-2]:1);
		}
		return f[len-1];
    }
};

int main()
{
	Solution *s = new Solution();
	cout << s->numDecodings("101") << endl;


	system("pause");
	return 0;
}