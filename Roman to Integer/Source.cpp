// Roman to Integer
//   Author: flashhack
//   Update: 2014-12-13
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
    int romanToInt(string s) {
		int len=s.length();
		int res=0;
		string list="IVXLCDM";
		int val[]={1,5,10,50,100,500,1000};
        for(int i=0;i<len;i++)
		{
			int pos=list.find(s[i]);
			if(i<len)
			{
				int pos2=list.find(s[i+1]);
				if(pos<pos2) res-=val[pos]; else res+=val[pos];
			}
		}
		return res;
    }
};

//2nd pass:
class Solution {
public:
    int romanToInt(string s) {
		unordered_map<char,int> table;
		table['I']=1; table['V']=5; table['X']=10; table['L']=50; table['C']=100; table['D']=500; table['M']=1000;
		int ans=0,prev=INT_MAX;
		for(char c:s)
		{
		    int num=table[c];
		    ans+=num;
            if(prev<num) ans-=2*prev;
            prev=num;
		}
        return ans;		
    }
};

int main()
{
	Solution *s = new Solution();

	cout<<s->romanToInt("XIV")<<endl;

	system("pause");
	return 0;
}