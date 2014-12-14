// Count and Say
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

class Solution {
public:
    string countAndSay(int n) {
        string res="1";
		char buffer[10000];
		for(int i=2;i<=n;i++)
		{
			string next="";
			int cnt=1;
			int len = res.length();
			for(int j=0;j<len;j++)
			{
				if(j+1<len && res[j]==res[j+1])
				{
					cnt++;
					continue;
				}
				sprintf(buffer,"%d",cnt);
				next+=buffer;
				next+=res[j];
				cnt=1;
			}
			res=next;
		}
		return res;
    }
};

int main()
{
	Solution *s = new Solution();

	cout<<s->countAndSay(6)<<endl;


	system("pause");
	return 0;
}