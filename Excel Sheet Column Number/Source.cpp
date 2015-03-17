// Excel Sheet Column Number
//   Author: flashhack
//   Update: 2015-01-14
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
    int titleToNumber(string s) {
		reverse(s.begin(),s.end());
		int res=0,base=1;
		for(char c:s)
		{
			res+=(c-'A'+1)*base;
			base*=26;
		}
		return res;
    }
};

//2nd pass
class Solution_2nd {
public:
    int titleToNumber(string s) {
        int res=0, base=1;
        for(int i=s.length()-1;i>=0;i--)
        {
            res+=(s[i]-'A'+1)*base;
            base*=26;
        }
        return res;
    }
};

//3rd pass:
/*
A~Z : 0~25
      1~26
      base=26,offset=1
AA 27
AB 28
calc from left to right, ans=ans*26+digit
*/
class Solution {
public:
    int titleToNumber(string s) {
        int ans=0;
        for(char c:s) ans=ans*26+(c-'A')+1;
        return ans;
    }
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}