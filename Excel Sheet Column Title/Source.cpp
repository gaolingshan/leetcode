// Excel Sheet Column Title
//   Author: flashhack
//   Update: 2015-01-14
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
    string convertToTitle(int n) {
		string res;
		while(n!=0)
		{
			res+='A'+(n-1)%26;
			n=(n-1)/26;
		}
		reverse(res.begin(),res.end());
		return res;
    }
};

//2nd pass: 2015-02-07
/*
A-0
B-1
C-2
..
Z-25
AA- 0,0 = 26*1+0     26
AB- 0,1 = 26*1+1     27
AZ- 0,25 = 26*1+25   51
BA- 1,0 = 26*2+0     52
BB- 1,1 = 26*2+1     53

num/26-1 ~ A..Z
num%26 ~ A..Z
         0  25
             
*/
class Solution {
public:
    string convertToTitle(int n) {
        n--;
        string res;
        while(n>=0)
        {
            res+='A'+n%26;
            n=n/26-1;
        }
		reverse(res.begin(),res.end());
        return res;
    }
};

int main()
{
	Solution *s = new Solution();
	cout<<s->convertToTitle(29)<<endl;

	system("pause");
	return 0;
}