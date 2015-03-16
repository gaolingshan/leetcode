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

class Solution_old {
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

//2nd pass: 2015-02-21
/*
12 => AB, L
0  => invalid
10~26 => OK
1~9 OK
f[i]: 1~i decode ways
f[0] = 1;
f[i+1]+=f[i] , s[i+1] : 1~9
f[i+2]+=f[i] , s[i+1~i+2] : 10~26
res: f[n]
*/
class Solution {
public:
    int numDecodings(string s) {
		if(s=="") return 0;
		vector<int> f(s.length()+1,0);
		for(int i=0;i<s.length();i++)
        {
            if(s[i]>='1' && s[i] <='9') f[i+1]+=f[i];
            if(i+1<s.length())
            {
                int num=stoi(s.substr(i,2));
                if(num>=10 && num<=26) f[i+2]+=f[i];
            }
        }
        return f[s.length()];
    }
};

int main()
{
	Solution *s = new Solution();
	//cout << s->numDecodings("101") << endl;
	cout << s->numDecodings("12") << endl;


	system("pause");
	return 0;
}