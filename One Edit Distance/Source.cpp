// One Edit Distance
//   Author: flashhack
//   Update: 2015-01-15
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
	bool check(string a, string b) // check whether two strings can be transformed within one step
	{
		int cnt=0;
		for(int i=0;i<a.length();i++) 
		{
			if(a[i]!=b[i]) cnt++;
			if(cnt>1) return false;
		}
		if (cnt==0) return false;
		return true;
	}

    bool isOneEditDistance(string s, string t) {
		int lenS=s.length();
		int lenT=t.length();
		if(abs(lenS-lenT)>1) return false;
		if(lenS==lenT) return check(s,t);
		if(lenS>lenT)
		{
			swap(s,t);
			swap(lenS,lenT);
		}
		for(int i=0;i<lenT;i++)
		{
			string tmp=t.substr(0,i) + t.substr(i+1,lenT-i);
			if(tmp==s) return true;
		}
		return false;
    }
};


//2nd pass: 2015-02-21
class Solution {
public:
    inline bool check(string s, string t)
    {
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=t[i]) cnt++;
            if(cnt>1) return false;
        }
        return cnt==1;
    }
    bool isOneEditDistance(string s, string t) {
        int lenS=s.length(), lenT=t.length();
        if(abs(lenS-lenT)>1) return false;
        if(lenS==lenT) return check(s,t);
        if(lenS<lenT)  {swap(s,t); swap(lenS,lenT);}
        for(int i=0;i<lenS;i++)
		{
			string tmp=s;
            if(tmp.erase(i,1)==t) return true;
		}
        return false;
    }
};

int main()
{
	Solution *s = new Solution();
	cout<<s->isOneEditDistance("a","ab")<<endl;

	system("pause");
	return 0;
}