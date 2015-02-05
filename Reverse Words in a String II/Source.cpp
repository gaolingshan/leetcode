// Reverse Words in a String II
//   Author: flashhack
//   Update: 2015-02-04
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
    void reverse(string &s, int start, int end)
    {
        if(start == end) return;
        int i=start, j=end;
        while(i<j)
        {
            swap(s[i],s[j]);
            i++;j--;
        }
    }
    void reverseWords(string &s) {
        reverse(s,0,s.length()-1);
        int i=0,j=0;
        while(j<s.length())
        {
            if(s[j]!=' ')
            {
                j++;
                continue;
            }
            reverse(s,i,j-1);
            j++;
            i=j;
        }
        reverse(s,i,j-1);
    }
};

int main()
{
	Solution *s = new Solution();
	string str="the sky is blue";
	s->reverseWords(str);
	cout<<str<<endl;


	system("pause");
	return 0;
}