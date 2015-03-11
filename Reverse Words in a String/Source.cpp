// Reverse Words in a String
//   Author: flashhack
//   Update: 2015-01-12
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
    void reverseWords(string &s) {
	    char* data = (char *)s.c_str();
		char* tmp=strtok(data," ");
		vector<string> v;
		while(tmp!=NULL)
		{
			v.push_back(tmp);
			tmp=strtok(NULL," ");
		}
		s="";
		for(auto it=v.rbegin();it!=v.rend();it++)
			s+=*it+" ";
		s=s.substr(0,s.length()-1);
    }
};

/*
1. reverse whole
2. split by space, reverse word, append to res
*/
class Solution {
public:
    void reverseWords(string &s) {
		reverse(s.begin(),s.end());
        string res="",tmp;
        istringstream ss(s);
        while(getline(ss,tmp,' ')){
			if(tmp!="") {
				reverse(tmp.begin(),tmp.end());
				res+=tmp+" ";
			}
        }
        if(!res.empty()) res.pop_back();
        s=res;
    }
};

int main()
{
	Solution *s = new Solution();
	string data = "  the  sky    is blue  ";
	s->reverseWords(data);
	cout<<data<<endl;


	system("pause");
	return 0;
}