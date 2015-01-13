// Reverse Words in a String
//   Author: flashhack
//   Update: 2015-01-12
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

int main()
{
	Solution *s = new Solution();
	string data = "the sky is blue";
	s->reverseWords(data);
	cout<<data<<endl;


	system("pause");
	return 0;
}